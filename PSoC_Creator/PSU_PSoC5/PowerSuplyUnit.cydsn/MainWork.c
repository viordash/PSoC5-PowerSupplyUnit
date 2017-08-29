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
void MultiJogChangingValue(BYTE value);
BOOL TemperatureControl();
void ChangeValue(INT shiftValue);
void UpdateAllSetPoints();
void CheckRegulatorStatus();
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
    BYTE prevButtons = Buttons_Read();  
	while (TRUE) {
        CheckRegulatorStatus();
        BYTE bt = Buttons_Read();
        if (prevButtons != bt) {
            prevButtons = bt;
            ProtectiveBehaviorChanged(bt & 0x08);
            RiseRatePowerUpChanged(bt & 0x04);    
            ButtonOkPressed(bt & (BtnOk_LongPress | BtnOk_Pressed)); 
        } 
        bt = MultiJog_Status_Read();
        if (bt & MultiJog_Rotated) {
            MultiJogChangingValue(bt);
        }        
        
        if (!MouseHandler()){
            if(!TemperatureControl()) {                
                if(!ProtectiveBehaviorIndicator()) {
                    
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
        if (MainWorkObj.ProtectiveBehavior == pbRestrict) {
            RegulatorControl_Write(0x15 | 0x020);
        } else {
            RegulatorControl_Write(0x15);  
        }
        MainWorkObj.WorkStartingPeriod = GetTickCount();
    } else if (newState != mwsWork) {
        RegulatorControl_Write(0x0A);        
    } 
    
    if (MainWorkObj.State == mwsWork && newState == mwsStandBy) {        
        SaveToStorage();
    }
    Regulator_WorkStateChanged(MainWorkObj.State, newState);
    Display_WorkStateChanged(MainWorkObj.State, newState);
    if (MainWorkObj.State != newState) {
        if (newState == mwsStandBy) {
            RequestToShowMessage("Stand By", tcNorm);    
        } else if (newState == mwsWork) {
            RequestToShowMessage("Power on", tcNorm);    
        } else if (newState == mwsErrGlb) {
            RequestToShowMessage("!!!ERROR!!!", tcInvert);    
        }  
    }
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

/*>>>-------------- Protective Behavior-----------------*/
void ProtectiveBehaviorChanged(BOOL btnPressed) {   
    if (btnPressed == 0) {
        MainWorkObj.ProtectiveBehavior = pbRestrict;
        O_Led_ProtectiveBehavior_Write(TRUE);
    } else {
        MainWorkObj.ProtectiveBehavior = pbCutOff;
        O_Led_ProtectiveBehavior_Write(FALSE);
    }
}

BOOL ProtectiveBehaviorIndicator() {
	static DWORD protectiveBehaviorFlashTick = 0;
    if (MainWorkObj.ProtectiveBehavior != pbRestrict) {
        return FALSE;    
    }
	if (GetElapsedPeriod(protectiveBehaviorFlashTick) < SYSTICK_mS(500)) {   
        return FALSE;
    }    
    protectiveBehaviorFlashTick = GetTickCount(); 
    O_Led_ProtectiveBehavior_Write(!O_Led_ProtectiveBehavior_Read());
    return TRUE;
}
/*----------------- Protective Behavior --------------<<<*/


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
    }
}
/*----------------- Button Ok pressed --------------<<<*/

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
        if (MainWorkObj.StabilizeModeA == smAmperageStab) {
            Regulator_RequestToChangeSetPointAmperageA(MainWorkObj.SetPointAmperageA);  
            Regulator_RequestToChangeCuttOffAmperageA(MainWorkObj.SetPointAmperageA);  
        } else {  //smVoltageStab
            Regulator_RequestToChangeCuttOffAmperageA(MainWorkObj.SetPointAmperageA);             
        }
        Display_RequestToChangeValue(svSetPointAmperageA, MainWorkObj.SetPointAmperageA);
        
    } else if (changedValue == cvVoltageB) {
        IncrementValue(&MainWorkObj.SetPointVoltageB, shiftValue, Voltage_MAX, Voltage_MIN);
        if (MainWorkObj.StabilizeModeB == smVoltageStab) {
            Regulator_RequestToChangeSetPointVoltageB(MainWorkObj.SetPointVoltageB); 
            Regulator_RequestToChangeCuttOffVoltageB(MainWorkObj.SetPointVoltageB);     
        } else {  //smAmperageStab
            Regulator_RequestToChangeCuttOffVoltageB(MainWorkObj.SetPointVoltageB);             
        }
        Display_RequestToChangeValue(svSetPointVoltageB, MainWorkObj.SetPointVoltageB);
        
    } else if (changedValue == cvAmperageB) {
        IncrementValue(&MainWorkObj.SetPointAmperageB, shiftValue, Amperage_MAX, Amperage_MIN);
        if (MainWorkObj.StabilizeModeB == smAmperageStab) {
            Regulator_RequestToChangeSetPointAmperageB(MainWorkObj.SetPointAmperageB);  
            Regulator_RequestToChangeCuttOffAmperageB(MainWorkObj.SetPointAmperageB);   
        } else {  //smVoltageStab
            Regulator_RequestToChangeCuttOffAmperageB(MainWorkObj.SetPointAmperageB);             
        }
        Display_RequestToChangeValue(svSetPointAmperageB, MainWorkObj.SetPointAmperageB);
        
    } else { //cvVoltageA
        IncrementValue(&MainWorkObj.SetPointVoltageA, shiftValue, Voltage_MAX, Voltage_MIN);
        if (MainWorkObj.StabilizeModeA == smVoltageStab) {
            Regulator_RequestToChangeSetPointVoltageA(MainWorkObj.SetPointVoltageA);  
            Regulator_RequestToChangeCuttOffVoltageA(MainWorkObj.SetPointVoltageA);  
        } else {  //smAmperageStab
            Regulator_RequestToChangeCuttOffVoltageA(MainWorkObj.SetPointVoltageA);             
        }
        Display_RequestToChangeValue(svSetPointVoltageA, MainWorkObj.SetPointVoltageA);  
    }   
}

void UpdateAllSetPoints() {    
    Regulator_RequestToChangeSetPointVoltageA(MainWorkObj.SetPointVoltageA); 
    Regulator_RequestToChangeCuttOffVoltageA(MainWorkObj.SetPointVoltageA);
    Regulator_RequestToChangeSetPointAmperageA(MainWorkObj.SetPointAmperageA);
    Regulator_RequestToChangeCuttOffAmperageA(MainWorkObj.SetPointAmperageA);
    Regulator_RequestToChangeSetPointVoltageB(MainWorkObj.SetPointVoltageB); 
    Regulator_RequestToChangeCuttOffVoltageB(MainWorkObj.SetPointVoltageB);
    Regulator_RequestToChangeSetPointAmperageB(MainWorkObj.SetPointAmperageB); 
    Regulator_RequestToChangeCuttOffAmperageB(MainWorkObj.SetPointAmperageB);    
}
/*----------------- Change values --------------<<<*/

/*>>>-------------- Errors -----------------*/
void ThrowException(PCHAR message) {
    ChangeState(mwsErrGlb); 
    RequestToShowMessage(message, 0);
}

void ResetErrorState() {
    RegulatorStatus_Read();
    Display_RequestToErrorOver(ERROR_OVER_NONE);
    ChangeState(mwsStandBy);    
}

void ThrowErrorOver(TErrorOver errorOver) {
    Display_RequestToErrorOver(errorOver);
    if ((MainWorkObj.ProtectiveBehavior == pbCutOff) && ((errorOver & ERROR_OVER_HW_AMPERAGE_A) || (errorOver & ERROR_OVER_HW_AMPERAGE_B))) {
        ChangeState(mwsErrGlb); 
    }
}
/*----------------- Errors --------------<<<*/

/*>>>-------------- Regulator state & status -----------------*/
void CheckRegulatorStatus() {
    static TErrorOver prevErrorOver = ERROR_OVER_NONE;
    BYTE status = RegulatorStatus_Read();
    if (!status && prevErrorOver == ERROR_OVER_NONE) {
        return;    
    }   
    TErrorOver errorOver = ERROR_OVER_NONE;
    if (status & 0x01) {
        errorOver |= ERROR_OVER_HW_AMPERAGE_A;
    } 
    if (status & 0x02) {
        errorOver |= ERROR_OVER_HW_AMPERAGE_B;
    } 
    ThrowErrorOver(errorOver);
    prevErrorOver = errorOver;
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

/* [] END OF FILE */
