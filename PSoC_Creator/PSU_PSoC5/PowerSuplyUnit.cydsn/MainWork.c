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

#define BtnOk_Pressed 0x02
#define BtnOk_LongPress 0x01

#define MultiJog_Rotated 0x01
#define MultiJog_FastRotate 0x02

TFunction MainWorkFunction;
TMainWork_Object MainWorkObj;
void ChangeState(TMainWorkState newState);
BOOL PolarModeChanged(BOOL btnBipolarModePressed);
void ChangePolarMode(TPolarMode polarMode);
BOOL RiseRatePowerUpChanged(BOOL btnRiseRatePowerUpPressed);
void ButtonOkPressed(BYTE value);
void MultiJogChangingValue(BYTE value);
BOOL TemperatureControl();

void MainWork_Init() {
    MainWorkObj.Properties.State = mwsInit;
    MainWorkObj.Properties.PolarMode = pmInit;   
    MainWorkObj.Properties.ChangedValue = cvVoltageA;  
    MainWorkObj.Properties.StabilizeModeA = smVoltageStab;  
    MainWorkObj.Properties.StabilizeModeB = smAmperageStab; 
    InitMouse();
}

void MainWork_Task(){	    
    ChangeState(mwsStart);
    TaskSleep(&MainWorkFunction, SYSTICK_mS(2000));  //waiting for start screen  
    ChangeState(mwsStandBy);  
    BYTE prevButtons = Buttons_Read();  
	while (TRUE) {
        {
            BYTE bt = Buttons_Read();
            if (prevButtons != bt) {
                prevButtons = bt;
                PolarModeChanged(bt & 0x08);
                RiseRatePowerUpChanged(bt & 0x04);    
                ButtonOkPressed(bt & (BtnOk_LongPress | BtnOk_Pressed)); 
            } 
            bt = MultiJog_Status_Read();
            if (bt & MultiJog_Rotated) {
                MultiJogChangingValue(bt);
            }
		}        
        
        if (MainWorkObj.Properties.State != mwsWork) {
            
        }
        if (!MouseHandler()){
            if(!TemperatureControl()) {
                
            }
        }
		TaskSleep(&MainWorkFunction, SYSTICK_mS(100));	
	}
}

void ChangeState(TMainWorkState newState){
    MainWorkObj.Properties.State = newState;    
}

void ResetErrorState() {
}

void SuppressProtection(BOOL withOn) {
}

void ChangeOutputState() {
}

/*>>>-------------- Polar Output mode -----------------*/
BOOL PolarModeChanged(BOOL btnBipolarModePressed) {
    BOOL res = FALSE;
    if (MainWorkObj.Properties.PolarMode == pmUnipolar) {
        if (btnBipolarModePressed) {
            ChangePolarMode(pmBipolar);
            res = TRUE;
        }
    } else if (MainWorkObj.Properties.PolarMode == pmBipolar) {
        if (!btnBipolarModePressed) {
            ChangePolarMode(pmUnipolar);
            res = TRUE;
        }
    } else if (MainWorkObj.Properties.PolarMode == pmInit) {
        ChangePolarMode(btnBipolarModePressed ? pmBipolar : pmUnipolar);
        res = TRUE;
    }
    return res;
}

void ChangePolarMode(TPolarMode polarMode) {
    MainWorkObj.Properties.PolarMode = polarMode;
    if (polarMode == pmBipolar) {
        RequestToChangeScreen(dsBipolar);
        RequestToChangeValue(svMeasuredVoltageA, 1210);
        RequestToChangeValue(svSetPointVoltageA, 1234);
        RequestToChangeValue(svMeasuredAmperageA, 561);
        RequestToChangeValue(svSetPointAmperageA, 1500);
        RequestToChangeValue(svMeasuredVoltageB, 515);
        RequestToChangeValue(svSetPointVoltageB, 520);
        RequestToChangeValue(svMeasuredAmperageB, 1300);
        RequestToChangeValue(svSetPointAmperageB, 3756);
        
        RequestToFocusing(svMeasuredVoltageA);  
        RequestToFocusingStabilize(ssmVoltageA);
        RequestToFocusingStabilize(ssmAmperageB);
        
        O_Led_Polar_Write(0);
    } else if (polarMode == pmUnipolar) {
        RequestToChangeScreen(dsUnipolar);
        RequestToChangeValue(svMeasuredVoltageA, 332);
        RequestToChangeValue(svSetPointVoltageA, 334);
        RequestToChangeValue(svMeasuredAmperageA, 6950);
        RequestToChangeValue(svSetPointAmperageA, 7000);   
        RequestToFocusing(svMeasuredAmperageA);  
        RequestToFocusingStabilize(ssmAmperageA);    
        O_Led_Polar_Write(0xFF);
    }
}
/*----------------- Polar Output mode --------------<<<*/


/*>>>-------------- Rise rate of voltage at power-up -----------------*/
BOOL RiseRatePowerUpChanged(BOOL btnRiseRatePowerUpPressed) {
    BOOL res = FALSE;
    O_Led_RiseRatePowerUp_Write(btnRiseRatePowerUpPressed ? 0 : 0xFF);
    res = TRUE;
    return res;
}
/*----------------- Rise rate of voltage at power-up --------------<<<*/

/*>>>-------------- Button Ok pressed -----------------*/
void ButtonOkPressed (BYTE value) {
    if (!value) {
        return;            
    }
    if (MainWorkObj.Properties.State == mwsStandBy || MainWorkObj.Properties.State == mwsWork) {
        if (!(value & BtnOk_LongPress)) {
            if(MainWorkObj.Properties.State == mwsStandBy && IsDisplayInChangingStabilizeMode()) {
                ConfirmSelectionStabilize();
            } else if(!IsDisplayInSelectionMode()) {
                SelectValue();
            } else {
                ConfirmSelection();
            }
        } else if (MainWorkObj.Properties.State == mwsStandBy) {
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
    MainWorkObj.Properties.MousePresent = present;
    
        O_Led_RiseRatePowerUp_Write(present);
}

void MouseChangingValue(INT value) {
    if (value) {
        ChangeValue(value);
    }
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
/* [] END OF FILE */
