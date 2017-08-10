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
    TElectrValue xx = CalcSetPointValueVoltageA(val);
    if (xx ==1234) {
        return -1;
    }
    return val;
}

TElectrValue CalcSetPointValueVoltageA (TElectrValue value) {   
    value *= 10;
    value /= 8; 
    TElectrValue adcCounts = ((value * ADC_VoltageA_countsPer10Volt) - (ADC_VoltageA_countsPer10Volt / 2)) / ADC_VoltageA_10MV_COUNTS;
    
    adcCounts += ADC_VoltageA_offset;
    if (adcCounts < 0) {
        adcCounts = 0;    
    }
//      int  mVolts = (int16)( (( (int32)adcCounts * ADC_VoltageA_10MV_COUNTS ) + 
//    ( (adcCounts > 0) ?  (ADC_VoltageA_countsPer10Volt / 2) : (-(ADC_VoltageA_countsPer10Volt / 2)) )) / ADC_VoltageA_countsPer10Volt);
        
    return adcCounts;
}

INT CalcDisplayValueAmperageA (TElectrValue value) {
    ADC_Amperage_SetOffset(GetAdcOffsetAmperageA());
    ADC_Amperage_SetGain(GetAdcGainAmperageA());
    INT val = ADC_Amperage_CountsTo_uVolts(value);
    if (val < 0) {
        val = 0;    
    } else {        
        val *= 20;   
        val /= 1000;  
    }
    return val;
}

INT CalcDisplayValueVoltageB (TElectrValue value) {
    INT val = ADC_VoltageB_CountsTo_mVolts(value);
    if (val < 0) {
        val = 0;    
    } else {        
        val *= 8;   
        val /= 10;  
    }
    return val;
}

TElectrValue CalcSetPointValueVoltageB (TElectrValue value) {   
    value *= 10;
    value /= 8; 
    TElectrValue adcCounts = ((value * ADC_VoltageB_countsPer10Volt) - (ADC_VoltageB_countsPer10Volt / 2)) / ADC_VoltageA_10MV_COUNTS;
    
    adcCounts += ADC_VoltageA_offset;
    if (adcCounts < 0) {
        adcCounts = 0;    
    }
    return adcCounts;
}

INT CalcDisplayValueAmperageB (TElectrValue value) {
    ADC_Amperage_SetOffset(GetAdcOffsetAmperageB());
    ADC_Amperage_SetGain(GetAdcGainAmperageB());
    INT val = ADC_Amperage_CountsTo_uVolts(value);
    if (val < 0) {
        val = 0;    
    } else {        
        val *= 20;   
        val /= 1000;  
    }
    return val;
}

/* [] END OF FILE */
