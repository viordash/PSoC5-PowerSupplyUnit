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
#include "Regulator\RegulatorTask.h"
#include "Utils\Calibrating.h"


TFunction RegulatorFunction;
TRegulatorObject RegulatorObj;

BOOL RegulatingChannelA();
BOOL RegulatingChannelB();

BOOL ReadCalibratedValues() {
    
    return TRUE;
}

void Regulator_Init() {
    PWM_VoltageA_Start();
    PWM_VoltageA_WriteCompare(0);
    PWM_VoltageB_Start();
    PWM_VoltageB_WriteCompare(0);
    ADC_AmperageA_Start();
    PGA_AmperageA_Start();
    PGA_AmperageB_Start();
    VDAC8_OverAmperageA_Start();
    Comp_OverAmperageA_Start();
    VDAC8_OverAmperageB_Start();
    Comp_OverAmperageB_Start();
    PGA_VoltageA_Start();
    ADC_VoltageA_SetPower(ADC_VoltageA__HIGHPOWER);
    ADC_VoltageA_Start();
    VDAC8_OverVoltageA_Start();
    Comp_OverVoltageA_Start();
    VDAC8_OverVoltageB_Start();
    Comp_OverVoltageB_Start();
    ADC_VoltageB_Start();
    ADC_VoltageB_SetPower(ADC_VoltageB__HIGHPOWER);
    AMuxChanelB_Start();
    AMuxChanelB_Next(); 
    memset(&RegulatorObj, 0, sizeof(TRegulatorObject));   
    ReadCalibratedValues();
}

void Regulator_Task() {	 
    ADC_VoltageA_StartConvert();
    ADC_AmperageA_StartConvert();
    ADC_VoltageB_StartConvert();
	while (TRUE) {
        RegulatingChannelA();
		TaskSleep(&RegulatorFunction, SYSTICK_mS(1));	
        RegulatingChannelB();
		TaskSleep(&RegulatorFunction, SYSTICK_mS(1));	
	}
}

BYTE CalculateOverVoltageVDACValue(TElectrValue value) {
    DWORD dw = (Voltage_MAX * 1000) / value;
    dw = (255 * 1000) / dw;
    return 255;// (BYTE)dw;
}

BYTE CalculateOverAmperageVDACValue(TElectrValue value) {
    DWORD dw = (Amperage_MAX * 1000) / value;
    dw = (255 * 1000) / dw;
    return 255;// (BYTE)dw;    
}

/*>>>-------------- Requests -----------------*/
void Regulator_RequestToChangeSetPointVoltageA(TElectrValue value) {
    RegulatorObj.ChanelA.Voltage.SetPoint = value;
    VDAC8_OverVoltageA_SetValue(CalculateOverVoltageVDACValue(value));
}

void Regulator_RequestToChangeCuttOffVoltageA(TElectrValue value) {
    RegulatorObj.ChanelA.Voltage.CuttOff = value;
    VDAC8_OverVoltageA_SetValue(CalculateOverVoltageVDACValue(value));
}

void Regulator_RequestToChangeSetPointAmperageA(TElectrValue value) {
    RegulatorObj.ChanelA.Amperage.SetPoint = value;
    VDAC8_OverAmperageA_SetValue(CalculateOverAmperageVDACValue(value));
}

void Regulator_RequestToChangeCuttOffAmperageA(TElectrValue value) {
    RegulatorObj.ChanelA.Amperage.CuttOff = value;
    VDAC8_OverAmperageA_SetValue(CalculateOverAmperageVDACValue(value));
}

void Regulator_RequestToChangeSetPointVoltageB(TElectrValue value) {
    RegulatorObj.ChanelB.Voltage.SetPoint = value;
    VDAC8_OverVoltageB_SetValue(CalculateOverVoltageVDACValue(value));
}
     
void Regulator_RequestToChangeCuttOffVoltageB(TElectrValue value) {
    RegulatorObj.ChanelB.Voltage.CuttOff = value;
    VDAC8_OverVoltageB_SetValue(CalculateOverVoltageVDACValue(value));
}
     
void Regulator_RequestToChangeSetPointAmperageB(TElectrValue value) {
    RegulatorObj.ChanelB.Amperage.SetPoint = value;
    VDAC8_OverAmperageB_SetValue(CalculateOverAmperageVDACValue(value));
}

void Regulator_RequestToChangeCuttOffAmperageB(TElectrValue value) {
    RegulatorObj.ChanelB.Amperage.CuttOff = value;
    VDAC8_OverAmperageB_SetValue(CalculateOverAmperageVDACValue(value));
}
/*----------------- Requests --------------<<<*/

/*>>>-------------- Measuring -----------------*/
BOOL MeasureVoltageA(PTElectrValue pValue) {
    if (ADC_VoltageA_IsEndConversion(ADC_VoltageA_RETURN_STATUS) == 0) {
        return FALSE;    
    }       
    INT value = ADC_VoltageA_GetResult16();
    if (MainWorkObj.State != mwsStart) {
        value -= RegulatorObj.ChanelA.Voltage.Offset;  
        if (value > 0) {
            *pValue = value; 
        } else {
            *pValue = 0;    
        }  
        return TRUE;           
    } else {
        MedianFilter3_Push(&(RegulatorObj.ChanelA.Voltage.OffsetMedianFilter3), value);
        return FALSE;    
    }      
}

BOOL MeasureAmperageA(PTElectrValue pValue) {
    if (ADC_AmperageA_IsEndConversion(ADC_AmperageA_RETURN_STATUS) == 0) {
        return FALSE;    
    }
    INT value = ADC_AmperageA_GetResult16();
    if (MainWorkObj.State != mwsStart) {
        value -= RegulatorObj.ChanelA.Amperage.Offset;  
        if (value > 0) {
            *pValue = value; 
        } else {
            *pValue = 0;    
        }   
        return TRUE;         
    } else {
        MedianFilter3_Push(&(RegulatorObj.ChanelA.Amperage.OffsetMedianFilter3), value);
        return FALSE;    
    }
}

BOOL MeasureVoltageB(PTElectrValue pValue) {
static BOOL waitingAdcVoltageB = FALSE;    
    if (waitingAdcVoltageB) {
        if (AMuxChanelB_GetChannel() != 0) {
            return FALSE;      
        }     
    } else if (Status_VoltageB_Eos_Read() != 0) { //end of sampling
        AMuxChanelB_Next();
        waitingAdcVoltageB = TRUE; 
    }
    if (ADC_VoltageB_IsEndConversion(ADC_VoltageB_RETURN_STATUS) == 0) {
        return FALSE;    
    }
    INT value = ADC_VoltageB_GetResult16();
    waitingAdcVoltageB = FALSE;
    ADC_VoltageB_StartConvert();
    
    if (MainWorkObj.State != mwsStart) {
        value -= RegulatorObj.ChanelB.Voltage.Offset;  
        if (value > 0) {
            *pValue = value; 
        } else {
            *pValue = 0;    
        }  
        return TRUE;           
    } else {
        MedianFilter3_Push(&(RegulatorObj.ChanelB.Voltage.OffsetMedianFilter3), value);
        return FALSE;    
    }        
}

BOOL MeasureAmperageB(PTElectrValue pValue) {
static BOOL waitingAdcAmperageB = FALSE;    
    if (waitingAdcAmperageB) {
        if (AMuxChanelB_GetChannel() != 1) {
            return FALSE;      
        }     
    } else if (Status_VoltageB_Eos_Read() != 0) { //end of sampling
        AMuxChanelB_Next();
        waitingAdcAmperageB = TRUE; 
    }
    if (ADC_VoltageB_IsEndConversion(ADC_VoltageB_RETURN_STATUS) == 0) {
        return FALSE;    
    }
    INT value = ADC_VoltageB_GetResult16();
    waitingAdcAmperageB = FALSE;
    ADC_VoltageB_StartConvert();
    
    if (MainWorkObj.State != mwsStart) {
        value -= RegulatorObj.ChanelB.Amperage.Offset;  
        if (value > 0) {
            *pValue = value; 
        } else {
            *pValue = 0;    
        }   
        return TRUE;         
    } else {
        MedianFilter3_Push(&(RegulatorObj.ChanelB.Amperage.OffsetMedianFilter3), value);
        return FALSE;    
    }  
}

BOOL Regulating(PTRegulatorChannel pRegulatorChannel, TWritePwm writePwm, TReadPwm readPwm, BOOL bAmperageInConversion) {
    TElectrValue voltageMeasured = pRegulatorChannel->Voltage.Measured;
    TElectrValue voltageSetPoint = pRegulatorChannel->Voltage.SetPoint;
    TElectrValue amperageMeasured = pRegulatorChannel->Amperage.Measured;
    TElectrValue amperageSetPoint = pRegulatorChannel->Amperage.SetPoint;
        
    INT diffValue = voltageMeasured - voltageSetPoint;
    BOOL isLessThanSetPoint = diffValue < 0;
    if (isLessThanSetPoint) {
        diffValue *= -1;
    }
    if (diffValue < voltageMeasured / 1024) { //если несоответсвие менее 0.1% не регулировать
        return FALSE;
    }
    SHORT pwmDiff;
    if (diffValue < voltageMeasured / 512) { //если разница менее 0.2%        
        pwmDiff = 1;        
    } else if (diffValue < voltageMeasured / 256) { //если разница менее 0.4%
        if (MainWorkObj.RiseRatePowerUp == rrpuSlow) {
            pwmDiff = 2;       
        } else {
            pwmDiff = 4;
        }
    } else if (diffValue < voltageMeasured / 128) { //если разница менее 0.8%
        if (MainWorkObj.RiseRatePowerUp == rrpuSlow) {
            pwmDiff = 4;  
        } else {
            pwmDiff = 8;
        }
    } else if (diffValue < voltageMeasured / 64) { //если разница менее 1.6%
        if (MainWorkObj.RiseRatePowerUp == rrpuSlow) {
            pwmDiff = 8;  
        } else {
            pwmDiff = 16;
        }
     } else if (diffValue < voltageMeasured / 32) { //если разница менее 3.2%
        if (MainWorkObj.RiseRatePowerUp == rrpuSlow) {
            pwmDiff = 16;  
        } else {
            pwmDiff = 32;
        }
    } else if (diffValue < voltageMeasured / 16) { //если разница менее 6.2%
        if (MainWorkObj.RiseRatePowerUp == rrpuSlow) {
            pwmDiff = 32;  
        } else {
            pwmDiff = 64;
        }
    } else if (!isLessThanSetPoint) { //если новое значение резко уменьшилось, то установить сразу
        TElectrValue pwmNew = GetCalibratedPwmValue(voltageSetPoint); 
        writePwm(pwmNew); 
        return TRUE;
    } else {
        if (MainWorkObj.RiseRatePowerUp == rrpuSlow) {
            pwmDiff = 64;  
        } else {
            pwmDiff = 128;
        }            
    }
    if (!isLessThanSetPoint) { //если напряжение меньше SetPoint        
    //если текущий ток еще замеряется, а предыдущее значение тока близко к максимуму, то pwmDiff установить на минимум. Чтобы не было скачка тока        
        INT amperageDiffValue = amperageSetPoint - amperageMeasured;
        if (bAmperageInConversion && (amperageDiffValue < amperageSetPoint / 5)) {  //если Measured >= 80%
            pwmDiff = 1;    
        }
        pwmDiff *= -1;     
    }
    INT pwm = readPwm() + pwmDiff;
    if (pwm > 65535) {
        pwm = 65535;    
    } else if (pwm < 0) {
        pwm = 0;    
    }
    writePwm(pwm);     
    return TRUE;    
}

BOOL RegulatingChannelA() {
    TElectrValue voltageMeasured, amperageMeasured;
    BOOL bVoltageInConversion = !MeasureVoltageA(&voltageMeasured);
    BOOL bAmperageInConversion = !MeasureAmperageA(&amperageMeasured);

    if (!bVoltageInConversion && (RegulatorObj.ChanelA.Voltage.Measured != voltageMeasured)) {
        RegulatorObj.ChanelA.Voltage.Measured = voltageMeasured;
        Display_RequestToChangeVoltageA(voltageMeasured);
        if (MainWorkObj.State == mwsWork && RegulatorObj.ChanelA.Voltage.Measured >= RegulatorObj.ChanelA.Voltage.CuttOff) {
            ThrowErrorOver(ERROR_OVER_SW_VOLTAGE_A);
        }
    }
    if (!bAmperageInConversion && (RegulatorObj.ChanelA.Amperage.Measured != amperageMeasured)) {
        RegulatorObj.ChanelA.Amperage.Measured = amperageMeasured;
        Display_RequestToChangeAmperageA(amperageMeasured);
        if (MainWorkObj.State == mwsWork && RegulatorObj.ChanelA.Amperage.Measured >= RegulatorObj.ChanelA.Amperage.CuttOff) {
            ThrowErrorOver(ERROR_OVER_SW_AMPERAGE_A);
        }
    }  
    return !bVoltageInConversion && Regulating(&RegulatorObj.ChanelA, PWM_VoltageA_WriteCompare, PWM_VoltageA_ReadCompare, bAmperageInConversion);
}

BOOL RegulatingChannelB() {
    TElectrValue voltageMeasured, amperageMeasured;
    BOOL bVoltageInConversion = !MeasureVoltageB(&voltageMeasured);
    BOOL bAmperageInConversion = !MeasureAmperageB(&amperageMeasured);

    if (!bVoltageInConversion && (RegulatorObj.ChanelB.Voltage.Measured != voltageMeasured)) {
        RegulatorObj.ChanelB.Voltage.Measured = voltageMeasured;
        Display_RequestToChangeVoltageB(voltageMeasured);
        if (MainWorkObj.State == mwsWork && RegulatorObj.ChanelB.Voltage.Measured >= RegulatorObj.ChanelB.Voltage.CuttOff) {
            ThrowErrorOver(ERROR_OVER_SW_VOLTAGE_B);
        }
    }
    if (!bAmperageInConversion && (RegulatorObj.ChanelB.Amperage.Measured != amperageMeasured)) {
        RegulatorObj.ChanelB.Amperage.Measured = amperageMeasured;
        Display_RequestToChangeAmperageB(amperageMeasured);
        if (MainWorkObj.State == mwsWork && RegulatorObj.ChanelB.Amperage.Measured >= RegulatorObj.ChanelB.Amperage.CuttOff) {
            ThrowErrorOver(ERROR_OVER_SW_AMPERAGE_B);
        }
    }  
    return !bVoltageInConversion && Regulating(&RegulatorObj.ChanelB, PWM_VoltageB_WriteCompare, PWM_VoltageB_ReadCompare, bAmperageInConversion);
}
/*----------------- Measuring --------------<<<*/


void Regulator_WorkStateChanged(TMainWorkState oldState, TMainWorkState newState){
    if (oldState == mwsStart && newState == mwsStandBy) {
        RegulatorObj.ChanelA.Voltage.Offset = MedianFilter3_Calc(&(RegulatorObj.ChanelA.Voltage.OffsetMedianFilter3));
        RegulatorObj.ChanelA.Amperage.Offset = MedianFilter3_Calc(&(RegulatorObj.ChanelA.Amperage.OffsetMedianFilter3));
        RegulatorObj.ChanelB.Voltage.Offset = MedianFilter3_Calc(&(RegulatorObj.ChanelB.Voltage.OffsetMedianFilter3));
        RegulatorObj.ChanelB.Amperage.Offset = MedianFilter3_Calc(&(RegulatorObj.ChanelB.Amperage.OffsetMedianFilter3));
    }
}

/* [] END OF FILE */
