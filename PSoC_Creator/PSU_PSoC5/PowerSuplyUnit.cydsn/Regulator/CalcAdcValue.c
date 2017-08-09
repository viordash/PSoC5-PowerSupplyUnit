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
#include "Regulator\CalcAdcValue.h"

INT CalcDisplayValueVoltageA (TElectrValue value) {
    INT val = ADC_VoltageA_CountsTo_mVolts(value);
    if (val < 0) {
        val = 0;    
    } else {        
        val *= 8;   
        val /= 10;  
    }
    return val;
}

INT CalcDisplayValueAmperageA (TElectrValue value) {
    INT val = ADC_AmperageA_CountsTo_uVolts(value);
    if (val < 0) {
        val = 0;    
    } else {        
        val *= 20;   
        val /= 1000;  
    }
    return val;
}

INT CalcDisplayValueVoltageB (TElectrValue value) {
    ADC_VoltageB_SetOffset(GetAdcOffsetVoltageB());
    ADC_VoltageB_SetScaledGain(GetAdcGainVoltageB());
    INT val = ADC_VoltageB_CountsTo_mVolts(value);
    if (val < 0) {
        val = 0;    
    } else {        
        val *= 8;   
        val /= 10;  
    }
    return val;
}

INT CalcDisplayValueAmperageB (TElectrValue value) {
    ADC_VoltageB_SetOffset(GetAdcOffsetAmperageB());
    ADC_VoltageB_SetScaledGain(GetAdcGainAmperageB());
    INT val = ADC_VoltageB_CountsTo_uVolts(value);
    if (val < 0) {
        val = 0;    
    } else {        
        val *= 5;   
        val /= 1000;  
    }
    return val;
}

/* [] END OF FILE */
