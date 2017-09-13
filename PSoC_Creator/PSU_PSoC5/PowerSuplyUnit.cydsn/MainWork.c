/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "MainWork.h"
#include "LCD_Display.h"
#include "Temperature\TemperControl.h"
#include "MousePS2\MousePS2.h"
#include "Regulator\RegulatorTask.h"
#include "Storage.h"

#define BtnOk_Pressed 0x02
#define BtnOk_LongPress 0x01

#define MultiJog_Rotated 0x01
#define MultiJog_FastRotate 0x02

TFunction MainWorkFunction;
TMainWork_Object MainWorkObj;
void ChangeState(TMainWorkState newState);
void ProtectiveBehaviorChanged(BOOL btnPressed);
BOOL ProtectiveBehaviorIndicator();
void RefreshDisplay();
BOOL RiseRatePowerUpChanged(BOOL btnRiseRatePowerUpPressed);
void ButtonOkPressed(BYTE value);
void ButtonOnOrChangePolarityPressed (BYTE value);
void MultiJogChangingValue(BYTE value);
BOOL TemperatureControl();
void ChangeValue(INT shiftValue);
void UpdateAllSetPoints();
BOOL ErrorIndicator();
BOOL CheckRegulatorStatusCore(BYTE status);
BOOL CheckRegulatorStatus();
void ClearRegulatorStatusAndErrors();

void MainWork_Init() {
    EEPROMStorage_Start();
    RegulatorControl_Write(0x0A);
    MainWorkObj.State = mwsInit;
    MainWorkObj.ChangedValue = cvVoltageA;  
    MainWorkObj.StabilizeModeA = smVoltageStab;  
    MainWorkObj.StabilizeModeB = smAmperageStab; 
    InitMouse();
}

void MainWork_Task(){	    
    ChangeState(mwsStart);    
    LoadFromStorage();
    UpdateAllSetPoints();
    TaskSleep(&MainWorkFunction, SYSTICK_mS(2000));  //waiting for start screen  
    ChangeState(mwsStandBy);  
    RefreshDisplay();
    ResetErrorState();
    Regulator_ChangeStabilizeMode();
    Buttons_Read();  
    BYTE prevButtons = 0xFF;  
	while (TRUE) {
        CheckRegulatorStatus();
        BYTE bt = Buttons_Read();
        if (prevButtons != bt) {
            
            if (prevButtons & 0x08 || bt & 0x08) {
                ProtectiveBehaviorChanged(bt & 0x08);
            }
            if (prevButtons & 0x04 || bt & 0x04) {
                RiseRatePowerUpChanged(bt & 0x04);  
            }
            if (prevButtons & (BtnOk_LongPress | BtnOk_Pressed) || bt & (BtnOk_LongPress | BtnOk_Pressed)) {
                ButtonOkPressed(bt & (BtnOk_LongPress | BtnOk_Pressed)); 
            }
            if (!(prevButtons & 0x10) && bt & 0x10) {
                ButtonOnOrChangePolarityPressed(bt & 0x10);  
            }
            
            prevButtons = bt;
        } 
        bt = MultiJog_Status_Read();
        if (bt & MultiJog_Rotated) {
            MultiJogChangingValue(bt);
        }        
        
        if (!MouseHandler()){
            if(!TemperatureControl()) {  
                if (!ErrorIndicator()) {
                    if(!ProtectiveBehaviorIndicator()) {
                        
                    }
                }
            }
        }
        
        if (MainWorkObj.State == mwsWorkStarting) {
            if (GetElapsedPeriod(MainWorkObj.WorkStartingPeriod) >= SYSTICK_mS(50)) {   //delay for switch on output relay
                ChangeState(mwsWork);   
            }
        }
        
		TaskSleep(&MainWorkFunction, SYSTICK_mS(50));	
	}
}

void ChangeState(TMainWorkState newState){   
    if (newState == mwsWorkStarting) {
        ClearRegulatorStatusAndErrors();
        if (MainWorkObj.StabilizeModeA == smAmperageStab) {
            RegulatorControl_Write(0x15 | 0x20);
        } else {
            RegulatorControl_Write(0x15);  
        }
        MainWorkObj.WorkStartingPeriod = GetTickCount();
    } else if (newState != mwsWork) {
        RegulatorControl_Write(0x0A);        
    } 
    
    if (MainWorkObj.State == mwsWork && newState == mwsStandBy) {        
        SaveToStorage();
    } else if (MainWorkObj.State == mwsErrGlb && newState != mwsErrGlb) {              
        O_Led_Error_Write(FALSE);    
    }
    Regulator_WorkStateChanged(MainWorkObj.State, newState);
    Display_WorkStateChanged(MainWorkObj.State, newState);
    MainWorkObj.State = newState;   
}

void SuppressProtection(BOOL withOn) {
}

void ChangeOutputState() {
    if (MainWorkObj.State == mwsWork || MainWorkObj.State == mwsErrGlb) {
        ChangeState(mwsStandBy);    
    } else if (MainWorkObj.State == mwsStandBy) { 
        ChangeState(mwsWorkStarting);    
    }
}

/*>>>-------------- Protective Sensitivity-----------------*/
void ProtectiveBehaviorChanged(BOOL btnPressed) {   
    if (btnPressed == 0) {
        MainWorkObj.ProtectiveSensitivity = psWeak;
        O_Led_ProtectiveSensitivity_Write(TRUE);
        UpdateAllSetPoints();
    } else {
        MainWorkObj.ProtectiveSensitivity = psNormal;
        O_Led_ProtectiveSensitivity_Write(FALSE);
        UpdateAllSetPoints();
    }
}

BOOL ProtectiveBehaviorIndicator() {
	static DWORD protectiveSensitivityFlashTick = 0;
    if (MainWorkObj.ProtectiveSensitivity != psWeak) {
        return FALSE;    
    }
	if (GetElapsedPeriod(protectiveSensitivityFlashTick) < SYSTICK_mS(500)) {   
        return FALSE;
    }    
    protectiveSensitivityFlashTick = GetTickCount(); 
    O_Led_ProtectiveSensitivity_Write(!O_Led_ProtectiveSensitivity_Read());
    return TRUE;
}
/*----------------- Protective Sensitivity --------------<<<*/


/*>>>-------------- Rise rate of voltage at power-up -----------------*/
BOOL RiseRatePowerUpChanged(BOOL btnRiseRatePowerUpPressed) {
    BOOL res = FALSE;
    if (btnRiseRatePowerUpPressed) {
        O_Led_RiseRatePowerUp_Write(0);  
        MainWorkObj.RiseRatePowerUp = rrpuFast;
    } else {
        O_Led_RiseRatePowerUp_Write(0xFF);
        MainWorkObj.RiseRatePowerUp = rrpuSlow;
    }    
    
    res = TRUE;
    return res;
}
/*----------------- Rise rate of voltage at power-up --------------<<<*/

/*>>>-------------- Button Ok pressed -----------------*/
void ButtonOkPressed (BYTE value) {
    if (!value) {
        return;            
    }
    if (MainWorkObj.State == mwsStandBy || MainWorkObj.State == mwsWork) {
        if (!(value & BtnOk_LongPress)) {
            if(MainWorkObj.State == mwsStandBy && IsDisplayInChangingStabilizeMode()) {
                ConfirmSelectionStabilize();
            } else if(!IsDisplayInSelectionMode()) {
                SelectValue();
            } else {
                ConfirmSelection();
            }
        } else if (MainWorkObj.State == mwsStandBy) {
            if(!IsDisplayInChangingStabilizeMode()) {
                SelectStabilizeMode();
            }
        }
    } else if (MainWorkObj.State == mwsErrGlb) {
    	ResetErrorState();        
    }
}
/*----------------- Button Ok pressed --------------<<<*/

/*>>>-------------- Button On or Change polarity pressed -----------------*/
void ButtonOnOrChangePolarityPressed (BYTE value) {
    if (!value) {
        return;            
    }

    if (!MainWorkObj.MousePresent) {
        ChangeOutputState();
    }
}
/*----------------- Button On or Change polarity pressed --------------<<<*/

/*>>>-------------- MultiJog Changing Value -----------------*/
void MultiJogChangingValue (BYTE value) {
static DWORD prevTick = 0;  
    if (GetElapsedPeriod(prevTick) < SYSTICK_mS(100)) {
        return;
    }
    prevTick = GetTickCount();
    
    INT i = MultiJog_GetCounter();
    MultiJog_SetCounter(0);
    if(IsDisplayInSelectionMode()) {
        if (i > 0) {
            SelectNextIndicator();    
        } else if (i < 0) {
            SelectPrevIndicator();    
        }
    } else if(IsDisplayInChangingStabilizeMode()) {
        if (i > 0) {
            SelectNextStabilizeIndicator();    
        } else if (i < 0) {
            SelectPrevStabilizeIndicator();    
        }
    } else {
        INT mult = 1;
        if (value & MultiJog_FastRotate) {        
            mult = 10;
        }
        if (i) {
            ChangeValue((i * mult));
        }
    }    
}
/*----------------- MultiJog Changing Value --------------<<<*/


/*>>>-------------- Mouse Changing Value -----------------*/
void MouseState(BOOL present) {
    while (!RequestToVisibileMousePresent(present)) {
        TaskSleep(&MainWorkFunction, SYSTICK_mS(100));	    
    }
    MainWorkObj.MousePresent = present;
}

void MouseChangingValue(INT value) {
    ChangeValue(value);
}

/*----------------- Mouse Changing Value --------------<<<*/


/*>>>-------------- Temperature Control -----------------*/
BOOL TemperatureControl() {
	static DWORD temperatureScanTick = 0;
	if (GetElapsedPeriod(temperatureScanTick) < SYSTICK_mS(5000)) {   
        return FALSE;
    }
    temperatureScanTick = GetTickCount(); 
    TTemperature temperatures = CheckTemper();
    RequestToChangeTemperatures(temperatures);
    return TRUE;
}
/*----------------- Temperature Control --------------<<<*/

/*>>>-------------- Change values -----------------*/
void IncrementValue(PTElectrValue pElectrValue, INT shiftValue, TElectrValue max, TElectrValue min) {
    TElectrValue electrValue  = *pElectrValue;
    electrValue += shiftValue;
    if (shiftValue < 0) {
        if (electrValue < min || electrValue > max) {
            electrValue = min;  
        }       
    } else if (electrValue < min) {
        electrValue = min;  
    } else if (electrValue > max) {
        electrValue = max;  
    }   
    *pElectrValue = electrValue;
}

void ChangeValue(INT shiftValue) {
    TChangedValue changedValue = MainWorkObj.ChangedValue;
    if (changedValue == cvAmperageA) {
        IncrementValue(&MainWorkObj.SetPointAmperageA, shiftValue, Amperage_MAX, Amperage_MIN); 
        Regulator_RequestToChangeSetPointAmperageA(MainWorkObj.SetPointAmperageA);   
        Display_RequestToChangeValue(svSetPointAmperageA, MainWorkObj.SetPointAmperageA);
        
    } else if (changedValue == cvVoltageB) {
        IncrementValue(&MainWorkObj.SetPointVoltageB, shiftValue, Voltage_MAX, Voltage_MIN);
        Regulator_RequestToChangeSetPointVoltageB(MainWorkObj.SetPointVoltageB);     
        Display_RequestToChangeValue(svSetPointVoltageB, MainWorkObj.SetPointVoltageB);
        
    } else if (changedValue == cvAmperageB) {
        IncrementValue(&MainWorkObj.SetPointAmperageB, shiftValue, Amperage_MAX, Amperage_MIN);
        Regulator_RequestToChangeSetPointAmperageB(MainWorkObj.SetPointAmperageB);   
        Display_RequestToChangeValue(svSetPointAmperageB, MainWorkObj.SetPointAmperageB);
        
    } else { //cvVoltageA
        IncrementValue(&MainWorkObj.SetPointVoltageA, shiftValue, Voltage_MAX, Voltage_MIN);
        Regulator_RequestToChangeSetPointVoltageA(MainWorkObj.SetPointVoltageA);  
        Display_RequestToChangeValue(svSetPointVoltageA, MainWorkObj.SetPointVoltageA);  
    }   
}

void UpdateAllSetPoints() {    
    Regulator_RequestToChangeSetPointVoltageA(MainWorkObj.SetPointVoltageA); 
    Regulator_RequestToChangeSetPointAmperageA(MainWorkObj.SetPointAmperageA);
    Regulator_RequestToChangeSetPointVoltageB(MainWorkObj.SetPointVoltageB); 
    Regulator_RequestToChangeSetPointAmperageB(MainWorkObj.SetPointAmperageB);    
}
/*----------------- Change values --------------<<<*/

/*>>>-------------- Errors -----------------*/
void ThrowException(PCHAR message) {
    ChangeState(mwsErrGlb); 
    RequestToShowMessage(message, 0);
}

void ThrowErrorOverCore(TErrorOver setErrorOver, TErrorOver resetErrorOver) {
    static TErrorOver prevErrorOver = ERROR_OVER_NONE;
    prevErrorOver |= (setErrorOver & ~ERROR_OVER_URGENT_OFF);
    prevErrorOver &= ~resetErrorOver;
    
    Display_RequestToErrorOver(prevErrorOver);
    if ((setErrorOver & ERROR_OVER_URGENT_OFF) 
    || (MainWorkObj.StabilizeModeA == smVoltageStab && (prevErrorOver & (ERROR_OVER_HW_AMPERAGE_A | ERROR_OVER_SW_VOLTAGE_A | ERROR_OVER_SW_AMPERAGE_A)))
    || (MainWorkObj.StabilizeModeB == smVoltageStab && (prevErrorOver & (ERROR_OVER_SW_VOLTAGE_B | ERROR_OVER_SW_AMPERAGE_B)))) {
        ChangeState(mwsErrGlb); 
    }
}

void ThrowErrorOver(TErrorOver setErrorOver, TErrorOver resetErrorOver) {
    if (!CheckRegulatorStatusCore(RegulatorStatus_Read())) {//если есть HW ошибка то отображать только ее 
        ThrowErrorOverCore(setErrorOver, resetErrorOver);
    }
}

void ResetErrorState() {
    RegulatorStatus_Read();
    ThrowErrorOverCore(ERROR_OVER_NONE, ~ERROR_OVER_NONE);
    ChangeState(mwsStandBy);  
}

BOOL ErrorIndicator() {
	static DWORD errorFlashTick = 0;
    if (MainWorkObj.State != mwsErrGlb) {
        return FALSE;    
    }
	if (GetElapsedPeriod(errorFlashTick) < SYSTICK_mS(150)) {   
        return FALSE;
    }    
    errorFlashTick = GetTickCount(); 
    O_Led_Error_Write(!O_Led_Error_Read());
    return TRUE;
}
/*----------------- Errors --------------<<<*/

/*>>>-------------- Regulator state & status -----------------*/
BOOL CheckRegulatorStatusCore(BYTE status) {
    if (status & 0x01) {
        ThrowErrorOverCore(ERROR_OVER_HW_AMPERAGE_A, ERROR_OVER_NONE);
        return TRUE; 
    } 
    return FALSE;
}
BOOL CheckRegulatorStatus() {
    static BYTE prevStatus = 0;
    BYTE status = RegulatorStatus_Read();
    if (status == prevStatus) {
        return FALSE;    
    }   
    prevStatus = status;
    if (CheckRegulatorStatusCore(status)) {
        return TRUE;
    } else {
        ThrowErrorOverCore(ERROR_OVER_NONE, ERROR_OVER_HW_AMPERAGE_A);
        return FALSE; 
    } 
}

void ClearRegulatorStatusAndErrors() {
    RegulatorStatus_Read();
}

/*----------------- Regulator state & status --------------<<<*/

void RefreshDisplay() {
    RequestToChangeScreen(dsWork);
    Display_RequestToChangeValue(svMeasuredVoltageA, MainWorkObj.SetPointVoltageA);
    Display_RequestToChangeValue(svSetPointVoltageA, MainWorkObj.SetPointVoltageA);
    Display_RequestToChangeValue(svMeasuredAmperageA, MainWorkObj.SetPointAmperageA);
    Display_RequestToChangeValue(svSetPointAmperageA, MainWorkObj.SetPointAmperageA);
    Display_RequestToChangeValue(svMeasuredVoltageB, MainWorkObj.SetPointVoltageB);
    Display_RequestToChangeValue(svSetPointVoltageB, MainWorkObj.SetPointVoltageB);
    Display_RequestToChangeValue(svMeasuredAmperageB, MainWorkObj.SetPointAmperageB);
    Display_RequestToChangeValue(svSetPointAmperageB, MainWorkObj.SetPointAmperageB);
    
    RequestToFocusing(svMeasuredVoltageA);  
    if (MainWorkObj.StabilizeModeA == smAmperageStab) { 
        RequestToFocusingStabilize(ssmAmperageA); 
    } else {
        RequestToFocusingStabilize(ssmVoltageA);
    }
    if (MainWorkObj.StabilizeModeB == smAmperageStab) { 
        RequestToFocusingStabilize(ssmAmperageB); 
    } else {
        RequestToFocusingStabilize(ssmVoltageB);
    }

    RequestToRepaintTemperatures();
    RequestToRepaintMousePresent();
}


/*>>>-------------- Change Stabilize Mode -----------------*/
void MainWork_ChangeStabilizeMode(TSelectStabilizeMode selectedValue) {
    if (selectedValue == ssmVoltageA) {
        MainWorkObj.StabilizeModeA = smVoltageStab; 
    } else if (selectedValue == ssmAmperageA) {
        MainWorkObj.StabilizeModeA = smAmperageStab; 
    } else if (selectedValue == ssmVoltageB) {
        MainWorkObj.StabilizeModeB = smVoltageStab; 
    } else if (selectedValue == ssmAmperageB) {
        MainWorkObj.StabilizeModeB = smAmperageStab; 
    } 
    Regulator_ChangeStabilizeMode();
}
/*----------------- Change Stabilize Mode --------------<<<*/
/* [] END OF FILE */
