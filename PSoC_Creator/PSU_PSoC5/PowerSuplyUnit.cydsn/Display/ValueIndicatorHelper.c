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
    if (MainWorkObj.Properties.PolarMode == pmBipolar) {        
        if (MainWorkObj.Properties.StabilizeModeA == smVoltageStab) {  
            if (MainWorkObj.Properties.StabilizeModeB == smVoltageStab) {
               if (MainWorkObj.Properties.ChangedValue == cvVoltageA) {
                    RequestToSelect(svMeasuredVoltageB);
                } else {
                    RequestToSelect(svMeasuredVoltageA);
                } 
            } else if (MainWorkObj.Properties.StabilizeModeB == smAmperageStab) {
               if (MainWorkObj.Properties.ChangedValue == cvVoltageA) {
                    RequestToSelect(svMeasuredAmperageB);
                } else {
                    RequestToSelect(svMeasuredVoltageA);
                } 
            }
        } else if (MainWorkObj.Properties.StabilizeModeA == smAmperageStab) {  
            if (MainWorkObj.Properties.StabilizeModeB == smVoltageStab) {
               if (MainWorkObj.Properties.ChangedValue == cvAmperageA) {
                     RequestToSelect(svMeasuredVoltageB);
                } else {
                     RequestToSelect(svMeasuredAmperageA);
                } 
            } else if (MainWorkObj.Properties.StabilizeModeB == smAmperageStab) {
               if (MainWorkObj.Properties.ChangedValue == cvAmperageA) {
                     RequestToSelect(svMeasuredAmperageB);
                } else {
                     RequestToSelect(svMeasuredAmperageA);
                } 
            }
        }
    } else if (MainWorkObj.Properties.PolarMode == pmUnipolar) {
        if (MainWorkObj.Properties.ChangedValue == cvVoltageA) {
            RequestToSelect(svMeasuredAmperageA);
        } else {
            RequestToSelect(svMeasuredVoltageA);
        }
    }
} 

void SelectNextIndicator() { 
    TSelectValue currentSelectedValue = GetCurrentSelectedValue();
    if (MainWorkObj.Properties.PolarMode == pmBipolar) {
        if (currentSelectedValue == svMeasuredVoltageA) {
            RequestToSelect(svMeasuredAmperageA);
        } else if (currentSelectedValue == svMeasuredAmperageA) {
            RequestToSelect(svMeasuredVoltageB);
        } else if (currentSelectedValue == svMeasuredVoltageB) {
            RequestToSelect(svMeasuredAmperageB); 
        } else  {
            RequestToSelect(svMeasuredVoltageA); 
        }
    } else if (MainWorkObj.Properties.PolarMode == pmUnipolar) {
        if (currentSelectedValue == svMeasuredVoltageA) {
            RequestToSelect(svMeasuredAmperageA);
        } else  {
            RequestToSelect(svMeasuredVoltageA);
        }
    }
}

void SelectPrevIndicator() { 
    TSelectValue currentSelectedValue = GetCurrentSelectedValue();
    if (MainWorkObj.Properties.PolarMode == pmBipolar) {
        if (currentSelectedValue == svMeasuredVoltageA) {
            RequestToSelect(svMeasuredAmperageB);
        } else if (currentSelectedValue == svMeasuredAmperageB) {
            RequestToSelect(svMeasuredVoltageB);
        } else if (currentSelectedValue == svMeasuredVoltageB) {
            RequestToSelect(svMeasuredAmperageA); 
        } else  {
            RequestToSelect(svMeasuredVoltageA); 
        }
    } else if (MainWorkObj.Properties.PolarMode == pmUnipolar) {
        if (currentSelectedValue == svMeasuredVoltageA) {
            RequestToSelect(svMeasuredAmperageA);
        } else  {
            RequestToSelect(svMeasuredVoltageA);
        }
    }
}
/*----------------- Selecting Value --------------<<<*/

/*>>>-------------- Focusing -----------------*/
void ConfirmSelection() {
    TSelectValue selectedValue = GetCurrentSelectedValue();
    if (selectedValue == svMeasuredAmperageA) {
        MainWorkObj.Properties.ChangedValue = cvAmperageA;    
    } else if (selectedValue == svMeasuredVoltageB) {
        MainWorkObj.Properties.ChangedValue = cvVoltageB;    
    } else if (selectedValue == svMeasuredAmperageB) {
        MainWorkObj.Properties.ChangedValue = cvAmperageB;    
    } else {
        MainWorkObj.Properties.ChangedValue = cvVoltageA; 
        selectedValue = svMeasuredVoltageA;
    }
    RequestToFocusing(selectedValue);    
}
/*----------------- Focusing --------------<<<*/


/*>>>-------------- Editing -----------------*/
#define Voltage_MAX 15 * 100
#define Voltage_MIN 0
#define Amperage_MAX 8 * 1000
#define Amperage_MIN 5

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
    TChangedValue changedValue = MainWorkObj.Properties.ChangedValue;
    if (changedValue == cvAmperageA) {
        IncrementValue(&MainWorkObj.Properties.SetPointAmperageA, shiftValue, Amperage_MAX, Amperage_MIN);
        RequestToChangeValue(svSetPointAmperageA, MainWorkObj.Properties.SetPointAmperageA);
        RequestToChangeValue(svMeasuredAmperageA, MainWorkObj.Properties.SetPointAmperageA);
    } else if (changedValue == cvVoltageB) {
        IncrementValue(&MainWorkObj.Properties.SetPointVoltageB, shiftValue, Voltage_MAX, Voltage_MIN);
        RequestToChangeValue(svSetPointVoltageB, MainWorkObj.Properties.SetPointVoltageB);
        RequestToChangeValue(svMeasuredVoltageB, MainWorkObj.Properties.SetPointVoltageB);
    } else if (changedValue == cvAmperageB) {
        IncrementValue(&MainWorkObj.Properties.SetPointAmperageB, shiftValue, Amperage_MAX, Amperage_MIN);
        RequestToChangeValue(svSetPointAmperageB, MainWorkObj.Properties.SetPointAmperageB);
        RequestToChangeValue(svMeasuredAmperageB, MainWorkObj.Properties.SetPointAmperageB);
    } else {
        IncrementValue(&MainWorkObj.Properties.SetPointVoltageA, shiftValue, Voltage_MAX, Voltage_MIN);   
        RequestToChangeValue(svSetPointVoltageA, MainWorkObj.Properties.SetPointVoltageA);
        RequestToChangeValue(svMeasuredVoltageA, MainWorkObj.Properties.SetPointVoltageA);
    }   
    
        
}
/*----------------- Editing --------------<<<*/


/* [] END OF FILE */
