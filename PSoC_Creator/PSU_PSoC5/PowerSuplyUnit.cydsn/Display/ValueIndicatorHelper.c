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



/*>>>-------------- Selecting Value -----------------*/
void SelectValue() {           
    if (MainWorkObj.StabilizeModeA == smVoltageStab) {  
        if (MainWorkObj.StabilizeModeB == smVoltageStab) {
           if (MainWorkObj.ChangedValue == cvVoltageA) {
                RequestToSelect(svMeasuredVoltageB);
            } else {
                RequestToSelect(svMeasuredVoltageA);
            } 
        } else if (MainWorkObj.StabilizeModeB == smAmperageStab) {
           if (MainWorkObj.ChangedValue == cvVoltageA) {
                RequestToSelect(svMeasuredAmperageB);
            } else {
                RequestToSelect(svMeasuredVoltageA);
            } 
        }
    } else if (MainWorkObj.StabilizeModeA == smAmperageStab) {  
        if (MainWorkObj.StabilizeModeB == smVoltageStab) {
           if (MainWorkObj.ChangedValue == cvAmperageA) {
                 RequestToSelect(svMeasuredVoltageB);
            } else {
                 RequestToSelect(svMeasuredAmperageA);
            } 
        } else if (MainWorkObj.StabilizeModeB == smAmperageStab) {
           if (MainWorkObj.ChangedValue == cvAmperageA) {
                 RequestToSelect(svMeasuredAmperageB);
            } else {
                 RequestToSelect(svMeasuredAmperageA);
            } 
        }
    }
} 

void SelectNextIndicator() { 
    TSelectValue currentSelectedValue = GetCurrentSelectedValue();
    if (currentSelectedValue == svMeasuredVoltageA) {
        RequestToSelect(svMeasuredAmperageA);
    } else if (currentSelectedValue == svMeasuredAmperageA) {
        RequestToSelect(svMeasuredVoltageB);
    } else if (currentSelectedValue == svMeasuredVoltageB) {
        RequestToSelect(svMeasuredAmperageB); 
    } else  {
        RequestToSelect(svMeasuredVoltageA); 
    }
}

void SelectPrevIndicator() { 
    TSelectValue currentSelectedValue = GetCurrentSelectedValue();
    if (currentSelectedValue == svMeasuredVoltageA) {
        RequestToSelect(svMeasuredAmperageB);
    } else if (currentSelectedValue == svMeasuredAmperageB) {
        RequestToSelect(svMeasuredVoltageB);
    } else if (currentSelectedValue == svMeasuredVoltageB) {
        RequestToSelect(svMeasuredAmperageA); 
    } else  {
        RequestToSelect(svMeasuredVoltageA); 
    }
}
/*----------------- Selecting Value --------------<<<*/

/*>>>-------------- Focusing -----------------*/
void ConfirmSelection() {
    TSelectValue selectedValue = GetCurrentSelectedValue();
    if (selectedValue == svMeasuredAmperageA) {
        MainWorkObj.ChangedValue = cvAmperageA;    
    } else if (selectedValue == svMeasuredVoltageB) {
        MainWorkObj.ChangedValue = cvVoltageB;    
    } else if (selectedValue == svMeasuredAmperageB) {
        MainWorkObj.ChangedValue = cvAmperageB;    
    } else {
        MainWorkObj.ChangedValue = cvVoltageA; 
        selectedValue = svMeasuredVoltageA;
    }
    RequestToFocusing(selectedValue);    
}
/*----------------- Focusing --------------<<<*/






/* [] END OF FILE */
