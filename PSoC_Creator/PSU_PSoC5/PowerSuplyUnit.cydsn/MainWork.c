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

void MainWork_Init() {
  MainWorkObj.Properties.State = mwsInit;
  MainWorkObj.Properties.PolarMode = pmInit;
}

void MainWork_Task(){	
    BYTE prevButtons = 0x00;   
    ChangeState(mwsStart);
    TaskSleep(&MainWorkFunction, SYSTICK_mS(2000));  //waiting for start screen  
    ChangeState(mwsStandBy);  
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
        
		TaskSleep(&MainWorkFunction, SYSTICK_mS(100));		
	}
}

void ChangeState(TMainWorkState newState){
    MainWorkObj.Properties.State = newState;    
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

TDisplayChannelData newValueA = {1210, 561};
TDisplayChannelData newValueB = {515, 1300};

void ChangePolarMode(TPolarMode polarMode) {
    MainWorkObj.Properties.PolarMode = polarMode;
    if (polarMode == pmBipolar) {
        RequestToChangeScreen(dsBipolar);
        RequestToChannelA(newValueA);
        RequestToChannelB(newValueB);
        TStabilizeMode stabilizeModeA = smVoltageStab;
        RequestToStabilizeModeA(stabilizeModeA);
        TStabilizeMode stabilizeModeB = smAmperageStab;
        RequestToStabilizeModeB(stabilizeModeB);

        O_Led_Polar_Write(0);
    } else if (polarMode == pmUnipolar) {
        RequestToChangeScreen(dsUnipolar);
        TDisplayChannelData newValueA = {332, 6950};
        RequestToChannelA(newValueA);
        TStabilizeMode stabilizeModeA = smAmperageStab;
        RequestToStabilizeModeA(stabilizeModeA);        
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
    if (MainWorkObj.Properties.State == mwsStandBy) {
        if (!(value & BtnOk_LongPress)) {
            RequestToNextSelect();
        }
        
    }
}
/*----------------- Changing the focused editor --------------<<<*/

/*>>>-------------- MultiJog Changing Value -----------------*/
void MultiJogChangingValue (BYTE value) {
static DWORD prevTick = 0;  
    if (GetElapsedPeriod(prevTick) < SYSTICK_mS(100)) {
        return;
    }
    prevTick = GetTickCount();
    
    INT i = MultiJog_GetCounter();
    MultiJog_SetCounter(0);
    INT mult = 1;
    if (value & MultiJog_FastRotate) {        
        mult = 10;
    }
    newValueA.Voltage += (i * mult);
    RequestToChannelA(newValueA); 
}
/*----------------- MultiJog Changing Value --------------<<<*/

/* [] END OF FILE */
