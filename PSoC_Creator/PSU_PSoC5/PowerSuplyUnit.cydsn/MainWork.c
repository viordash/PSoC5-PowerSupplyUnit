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

#define BtnOk_Pressed 0x02
#define BtnOk_LongPress 0x01

#define MultiJog_Rotated 0x01
#define MultiJog_FastRotate 0x02

TFunction MainWorkFunction;
TMainWork_Object MainWorkObj;
void ChangeState(TMainWorkState newState);
//BOOL PolarModeChanged(BOOL btnBipolarModePressed);
void RefreshDisplay();
BOOL RiseRatePowerUpChanged(BOOL btnRiseRatePowerUpPressed);
void ButtonOkPressed(BYTE value);
void MultiJogChangingValue(BYTE value);
BOOL TemperatureControl();
void ChangeValue(INT shiftValue);
void CheckRegulatorStatus();
void LoadFromStorage();

void MainWork_Init() {
    EEPROMStorage_Start();
    RegulatorControl_Write(0x0A);
    MainWorkObj.State = mwsInit;
    MainWorkObj.ChangedValue = cvVoltageA;  
    MainWorkObj.StabilizeModeA = smVoltageStab;  
    MainWorkObj.StabilizeModeB = smAmperageStab; 
    InitMouse();
    LoadFromStorage();
}

void MainWork_Task(){	    
    ChangeState(mwsStart);
    TaskSleep(&MainWorkFunction, SYSTICK_mS(2000));  //waiting for start screen  
    ChangeState(mwsStandBy);  
    BYTE prevButtons = Buttons_Read();  
	while (TRUE) {
        CheckRegulatorStatus();
        BYTE bt = Buttons_Read();
        if (prevButtons != bt) {
            prevButtons = bt;
           // PolarModeChanged(bt & 0x08);
            RiseRatePowerUpChanged(bt & 0x04);    
            ButtonOkPressed(bt & (BtnOk_LongPress | BtnOk_Pressed)); 
            RefreshDisplay();
        } 
        bt = MultiJog_Status_Read();
        if (bt & MultiJog_Rotated) {
            MultiJogChangingValue(bt);
        }
        
        
        if (!MouseHandler()){
            if(!TemperatureControl()) {
                
            }
        }
		TaskSleep(&MainWorkFunction, SYSTICK_mS(50));	
	}
}

void ChangeState(TMainWorkState newState){ 
    MainWorkObj.State = newState;   
    if (newState != mwsWork) {
        RegulatorControl_Write(0x0A);        
    } else {
        RegulatorControl_Write(0x15);    
    }    
}

void SuppressProtection(BOOL withOn) {
}

void ChangeOutputState() {
    if (MainWorkObj.State == mwsWork || MainWorkObj.State == mwsErrGlb) {
        ChangeState(mwsStandBy);    
    } else if (MainWorkObj.State == mwsStandBy) { 
        ChangeState(mwsWork);    
    }
}

///*>>>-------------- Polar Output mode -----------------*/
//BOOL PolarModeChanged(BOOL btnBipolarModePressed) {
//    BOOL res = FALSE;
//    if (MainWorkObj.PolarMode == pmUnipolar) {
//        if (btnBipolarModePressed) {
//            ChangePolarMode(pmBipolar);
//            res = TRUE;
//        }
//    } else if (MainWorkObj.PolarMode == pmBipolar) {
//        if (!btnBipolarModePressed) {
//            ChangePolarMode(pmUnipolar);
//            res = TRUE;
//        }
//    } else if (MainWorkObj.PolarMode == pmInit) {
//        ChangePolarMode(btnBipolarModePressed ? pmBipolar : pmUnipolar);
//        res = TRUE;
//    }
//    return res;
//}
//
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
//
//void ChangePolarMode(TPolarMode polarMode) {
//    MainWorkObj.PolarMode = polarMode;
//    RefreshDisplay(polarMode);
//    if (polarMode == pmBipolar) {
//        O_Led_Polar_Write(0);
//    } else if (polarMode == pmUnipolar) {  
//        O_Led_Polar_Write(0xFF);
//    }
//}
/*----------------- Polar Output mode --------------<<<*/


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
        } else {  //smVoltageStab
            Regulator_RequestToChangeCuttOffAmperageA(MainWorkObj.SetPointVoltageA);             
        }
        Display_RequestToChangeValue(svSetPointAmperageA, MainWorkObj.SetPointAmperageA);
        
    } else if (changedValue == cvVoltageB) {
        IncrementValue(&MainWorkObj.SetPointVoltageB, shiftValue, Voltage_MAX, Voltage_MIN);
        if (MainWorkObj.StabilizeModeB == smVoltageStab) {
            Regulator_RequestToChangeSetPointVoltageB(MainWorkObj.SetPointVoltageB);   
        } else {  //smAmperageStab
            Regulator_RequestToChangeCuttOffVoltageB(MainWorkObj.SetPointVoltageB);             
        }
        Display_RequestToChangeValue(svSetPointVoltageB, MainWorkObj.SetPointVoltageB);
        
    } else if (changedValue == cvAmperageB) {
        IncrementValue(&MainWorkObj.SetPointAmperageB, shiftValue, Amperage_MAX, Amperage_MIN);
        if (MainWorkObj.StabilizeModeB == smAmperageStab) {
            Regulator_RequestToChangeSetPointAmperageB(MainWorkObj.SetPointAmperageB);   
        } else {  //smVoltageStab
            Regulator_RequestToChangeCuttOffAmperageB(MainWorkObj.SetPointVoltageB);             
        }
        Display_RequestToChangeValue(svSetPointAmperageB, MainWorkObj.SetPointAmperageB);
        
    } else { //cvVoltageA
        IncrementValue(&MainWorkObj.SetPointVoltageA, shiftValue, Voltage_MAX, Voltage_MIN);
        if (MainWorkObj.StabilizeModeA == smVoltageStab) {
            Regulator_RequestToChangeSetPointVoltageA(MainWorkObj.SetPointVoltageA);   
        } else {  //smAmperageStab
            Regulator_RequestToChangeCuttOffVoltageA(MainWorkObj.SetPointVoltageA);             
        }
        Display_RequestToChangeValue(svSetPointVoltageA, MainWorkObj.SetPointVoltageA);  
    }   
}

/*----------------- Change values --------------<<<*/

/*>>>-------------- Errors -----------------*/
void ThrowException(PCHAR message) {
    ChangeState(mwsErrGlb); 
    RequestToShowError(message);
}

void ResetErrorState() {
}
/*----------------- Errors --------------<<<*/

/*>>>-------------- Regulator state & status -----------------*/
void CheckRegulatorStatus() {
CHAR buffer[60];   
PCHAR pBuffer = buffer;
    BYTE status = RegulatorStatus_Read();
    if (!status) {
        return;    
    }
    buffer[0] = 0;    
    if (status & 0x01) {
        pBuffer = _strncpy(pBuffer, "[A] HwVolt; ", sizeof("[A] HwVolt; ")); 
    } 
    if (status & 0x02) {
        pBuffer = _strncpy(pBuffer, "[A] HwCurr; ", sizeof("[A] HwCurr; "));    
    } 
    if (status & 0x04) {
        pBuffer = _strncpy(pBuffer, "[B] HwVolt; ", sizeof("[B] HwVolt; ")); 
    } 
    if (status & 0x08) {
        pBuffer = _strncpy(pBuffer, "[B] HwCurr; ", sizeof("[B] HwCurr; "));    
    }  

    ThrowException(buffer); 
}

/*----------------- Regulator state & status --------------<<<*/

/*>>>-------------- Storage -----------------*/
void LoadFromStorage() {    
    //memset(&MainWorkObj.Storage, 0, sizeof(TEepromStrorage)); 
    PBYTE pBuffer = (PBYTE) &(MainWorkObj.Storage);
    WORD adress;
    for (adress = 0; adress < (INT)sizeof(TEepromStrorage); adress++){
        *(pBuffer++) = EEPROMStorage_ReadByte(adress);       
    }       
}
/*----------------- Storage --------------<<<*/


/* [] END OF FILE */
