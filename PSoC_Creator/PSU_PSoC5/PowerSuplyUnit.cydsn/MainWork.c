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

TFunction MainWorkFunction;
TMainWork_Object MainWorkObj;
BOOL PolarModeChanged(BOOL btnBipolarModePressed);
void ChangePolarMode(TPolarMode polarMode);
BOOL RiseRatePowerUpChanged(BOOL btnRiseRatePowerUpPressed);
BOOL ButtonOkPressed (BOOL value);
BOOL MultiJogChangingValue (BOOL value);

void MainWork_Init() {
  MainWorkObj.Properties.State = mwsInit;
  MainWorkObj.Properties.PolarMode = pmInit;
}

void MainWork_Task(){	
    BYTE prevButtons = 0x00;
    
    TaskSleep(&MainWorkFunction, SYSTICK_mS(2000));  //waiting for start screen    
	while (TRUE) {
        {
            BYTE bt = Buttons_Read();
            if (bt != prevButtons) {
                prevButtons = bt;
                PolarModeChanged(bt & 0x04);
                RiseRatePowerUpChanged(bt & 0x02);
                ButtonOkPressed(bt & 0x01);
                if ((bt & 0x01) != 0) {
                    MultiJogChangingValue(bt & 0x30);
                }
            }
		}
		TaskSleep(&MainWorkFunction, SYSTICK_mS(100));		
	}
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
BOOL ButtonOkPressed (BOOL value) {
    BOOL res = FALSE;
    if (!value) {
        INT i = MultiJog_GetCounter();
        if (i > 1) {
            RequestToNextSelect();
            MultiJog_SetCounter(0);
            res = TRUE;
        } else if (i < -1) {
            RequestToPrevSelect();
            MultiJog_SetCounter(0);
            res = TRUE;
        }
    }
    return res;
}
/*----------------- Changing the focused editor --------------<<<*/

/*>>>-------------- MultiJog Changing Value -----------------*/
BOOL MultiJogChangingValue (BOOL value) {
    BOOL res = FALSE;
    INT i = MultiJog_GetCounter();
    newValueA.Voltage += i;
    RequestToChannelA(newValueA);
    MultiJog_SetCounter(0);
    res = TRUE;
    return res;
}
/*----------------- MultiJog Changing Value --------------<<<*/

/* [] END OF FILE */
