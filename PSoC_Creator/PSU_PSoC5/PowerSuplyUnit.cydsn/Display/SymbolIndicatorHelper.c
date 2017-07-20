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
    if (MainWorkObj.StabilizeModeA == smAmperageStab) { 
        RequestToSelectStabilize(ssmAmperageA); 
    } else {
        RequestToSelectStabilize(ssmVoltageA);
    }
} 

void SelectNextStabilizeIndicator() { 
    TSelectStabilizeMode currentSelectedValue = GetCurrentSelectedStabilize();
    if (currentSelectedValue == ssmVoltageA) {
        RequestToSelectStabilize(ssmAmperageA);
    } else if (currentSelectedValue == ssmAmperageA) {
        RequestToSelectStabilize(ssmVoltageB);
    } else if (currentSelectedValue == ssmVoltageB) {
        RequestToSelectStabilize(ssmAmperageB); 
    } else  {
        RequestToSelectStabilize(ssmVoltageA); 
    }
}

void SelectPrevStabilizeIndicator() { 
    TSelectStabilizeMode currentSelectedValue = GetCurrentSelectedStabilize();
    if (currentSelectedValue == ssmVoltageA) {
        RequestToSelectStabilize(ssmAmperageB);
    } else if (currentSelectedValue == ssmAmperageB) {
        RequestToSelectStabilize(ssmVoltageB);
    } else if (currentSelectedValue == ssmVoltageB) {
        RequestToSelectStabilize(ssmAmperageA); 
    } else  {
        RequestToSelectStabilize(ssmVoltageA); 
    }
}
/*----------------- Selecting StabilizeMode --------------<<<*/

/*>>>-------------- Focusing -----------------*/
void ConfirmSelectionStabilize() {
    TSelectStabilizeMode selectedValue = GetCurrentSelectedStabilize();
    if (selectedValue == ssmVoltageA) {
        MainWorkObj.StabilizeModeA = smVoltageStab; 
    } else if (selectedValue == ssmAmperageA) {
        MainWorkObj.StabilizeModeA = smAmperageStab; 
    } else if (selectedValue == ssmVoltageB) {
        MainWorkObj.StabilizeModeB = smVoltageStab; 
    } else if (selectedValue == ssmAmperageB) {
        MainWorkObj.StabilizeModeB = smAmperageStab; 
    }
    RequestToFocusingStabilize(selectedValue);    
}
/*----------------- Focusing --------------<<<*/


/* [] END OF FILE */
