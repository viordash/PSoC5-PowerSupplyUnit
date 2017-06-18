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
#include "Display\ValueIndicatorHelper.h"



/*>>>-------------- Selecting StabilizeMode -----------------*/
void SelectStabilizeMode() {    
    if (MainWorkObj.Properties.StabilizeModeA == smAmperageStab) { 
        RequestToSelectStabilize(ssmAmperageA); 
    } else {
        RequestToSelectStabilize(ssmVoltageA);
    }
} 

void SelectNextStabilizeIndicator() { 
    TSelectStabilizeMode currentSelectedValue = GetCurrentSelectedStabilize();
    if (MainWorkObj.Properties.PolarMode == pmBipolar) {
        if (currentSelectedValue == ssmVoltageA) {
            RequestToSelectStabilize(ssmAmperageA);
        } else if (currentSelectedValue == ssmAmperageA) {
            RequestToSelectStabilize(ssmVoltageB);
        } else if (currentSelectedValue == ssmVoltageB) {
            RequestToSelectStabilize(ssmAmperageB); 
        } else  {
            RequestToSelectStabilize(ssmVoltageA); 
        }
    } else if (MainWorkObj.Properties.PolarMode == pmUnipolar) {
        if (currentSelectedValue == ssmVoltageA) {
            RequestToSelectStabilize(ssmAmperageA);
        } else  {
            RequestToSelectStabilize(ssmVoltageA);
        }
    }
}

void SelectPrevStabilizeIndicator() { 
    TSelectStabilizeMode currentSelectedValue = GetCurrentSelectedStabilize();
    if (MainWorkObj.Properties.PolarMode == pmBipolar) {
        if (currentSelectedValue == ssmVoltageA) {
            RequestToSelectStabilize(ssmAmperageB);
        } else if (currentSelectedValue == ssmAmperageB) {
            RequestToSelectStabilize(ssmVoltageB);
        } else if (currentSelectedValue == ssmVoltageB) {
            RequestToSelectStabilize(ssmAmperageA); 
        } else  {
            RequestToSelectStabilize(ssmVoltageA); 
        }
    } else if (MainWorkObj.Properties.PolarMode == pmUnipolar) {
        if (currentSelectedValue == ssmVoltageA) {
            RequestToSelectStabilize(ssmAmperageA);
        } else  {
            RequestToSelectStabilize(ssmVoltageA);
        }
    }
}
/*----------------- Selecting StabilizeMode --------------<<<*/

/*>>>-------------- Focusing -----------------*/
void ConfirmSelectionStabilize() {
    TSelectStabilizeMode selectedValue = GetCurrentSelectedStabilize();
    if (MainWorkObj.Properties.PolarMode == pmBipolar) {
        if (selectedValue == ssmVoltageA) {
            MainWorkObj.Properties.StabilizeModeA = smVoltageStab; 
        } else if (selectedValue == ssmAmperageA) {
            MainWorkObj.Properties.StabilizeModeA = smAmperageStab; 
        } else if (selectedValue == ssmVoltageB) {
            MainWorkObj.Properties.StabilizeModeB = smVoltageStab; 
        } else if (selectedValue == ssmAmperageB) {
            MainWorkObj.Properties.StabilizeModeB = smAmperageStab; 
        }
    } else if (MainWorkObj.Properties.PolarMode == pmUnipolar) {
        if (selectedValue == ssmVoltageA) {
            MainWorkObj.Properties.StabilizeModeA = smVoltageStab; 
        } else if (selectedValue == ssmAmperageA) {
            MainWorkObj.Properties.StabilizeModeA = smAmperageStab; 
        }
    }
    RequestToFocusingStabilize(selectedValue);    
}
/*----------------- Focusing --------------<<<*/


/* [] END OF FILE */