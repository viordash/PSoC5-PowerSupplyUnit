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
#include <limits.h>
#include "MainWork.h"
#include "LCD_Display.h"
#include "Regulator\RegulatorTask.h"
#include "Utils\Calibrating.h"
#include "Regulator\CalcAdcValue.h"
#include "Utils\AggregatedValues.h"

TFunction RegulatorFunction;
TRegulatorObject RegulatorObj;

BOOL RegulatingChannelA();
BOOL RegulatingChannelB();

volatile BYTE DmaAdcVoltageA_Chan;
volatile BYTE DmaAdcVoltageA_TD[1];

volatile BYTE DmaAdcVoltageB_Chan;
volatile BYTE DmaAdcVoltageB_TD[1];


CY_ISR(PwmVoltageAIrqHandler) {
    BYTE bt = PWM_VoltageA_ReadStatusRegister();
    if (bt & PWM_VoltageA_STATUS_TC && RegulatorObj.ChanelA.Voltage.PwmChanged) {
        INT pwm = RegulatorObj.ChanelA.Voltage.Pwm;    
        if (pwm > PWM_MAX_PERIOD * 4) {
            pwm = PWM_MAX_PERIOD * 4;   
            RegulatorObj.ChanelA.Voltage.Pwm = pwm; 
        } else if (pwm < 0) {
            pwm = 0; 
            RegulatorObj.ChanelA.Voltage.Pwm = pwm;    
        }
        *PWM_VoltageA_Ex_Control_PTR = pwm & 0x03;
        pwm >>= 2;
        PWM_VoltageA_WriteCompare1(pwm);   
        PWM_VoltageA_WriteCompare2(pwm + 1); 
        RegulatorObj.ChanelA.Voltage.PwmChanged = FALSE; 
    }
}

CY_ISR(PwmVoltageBIrqHandler) {
    BYTE bt = PWM_VoltageB_ReadStatusRegister();
    if (bt & PWM_VoltageB_STATUS_TC && RegulatorObj.ChanelB.Voltage.PwmChanged) {
        INT pwm = RegulatorObj.ChanelB.Voltage.Pwm;    
        if (pwm > PWM_MAX_PERIOD * 4) {
            pwm = PWM_MAX_PERIOD * 4;    
            RegulatorObj.ChanelB.Voltage.Pwm = pwm;
        } else if (pwm < 0) {
            pwm = 0;  
            RegulatorObj.ChanelB.Voltage.Pwm = pwm;  
        }
        *PWM_VoltageA_Ex_Control_PTR = pwm & 0x03;
        pwm >>= 2;
        PWM_VoltageB_WriteCompare1(pwm);   
        PWM_VoltageB_WriteCompare2(pwm + 1); 
        RegulatorObj.ChanelB.Voltage.PwmChanged = FALSE; 
    }
}


void InitAdcDma_A() {
    /* Defines for DmaAdcVoltageA */
#define DmaAdcVoltageA_BYTES_PER_BURST 2
#define DmaAdcVoltageA_REQUEST_PER_BURST 1
#define DmaAdcVoltageA_SRC_BASE (CYDEV_PERIPH_BASE)
#define DmaAdcVoltageA_DST_BASE (CYDEV_SRAM_BASE)    
    DmaAdcVoltageA_Chan = DmaAdcVoltageA_DmaInitialize(DmaAdcVoltageA_BYTES_PER_BURST, DmaAdcVoltageA_REQUEST_PER_BURST, 
        HI16(DmaAdcVoltageA_SRC_BASE), HI16(DmaAdcVoltageA_DST_BASE));
    DmaAdcVoltageA_TD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(DmaAdcVoltageA_TD[0], 3 * 2, CY_DMA_DISABLE_TD, DmaAdcVoltageA__TD_TERMOUT_EN | CY_DMA_TD_INC_DST_ADR);
    CyDmaTdSetAddress(DmaAdcVoltageA_TD[0], LO16((uint32)ADC_VoltageA_SAR_WRK0_PTR), LO16((uint32)&(RegulatorObj.ChanelA.Voltage.AdcRawValues)));
    CyDmaChSetInitialTd(DmaAdcVoltageA_Chan, DmaAdcVoltageA_TD[0]);
}

void InitAdcDma_B() {
    /* Defines for DmaAdcVoltageA */
#define DmaAdcVoltageB_BYTES_PER_BURST 2
#define DmaAdcVoltageB_REQUEST_PER_BURST 1
#define DmaAdcVoltageB_SRC_BASE (CYDEV_PERIPH_BASE)
#define DmaAdcVoltageB_DST_BASE (CYDEV_SRAM_BASE)    
    DmaAdcVoltageB_Chan = DmaAdcVoltageB_DmaInitialize(DmaAdcVoltageB_BYTES_PER_BURST, DmaAdcVoltageB_REQUEST_PER_BURST, 
        HI16(DmaAdcVoltageB_SRC_BASE), HI16(DmaAdcVoltageB_DST_BASE));
    DmaAdcVoltageB_TD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(DmaAdcVoltageB_TD[0], 3 * 2, CY_DMA_DISABLE_TD, DmaAdcVoltageB__TD_TERMOUT_EN | CY_DMA_TD_INC_DST_ADR);
    CyDmaTdSetAddress(DmaAdcVoltageB_TD[0], LO16((uint32)ADC_VoltageB_SAR_WRK0_PTR), LO16((uint32)&(RegulatorObj.ChanelB.Voltage.AdcRawValues)));
    CyDmaChSetInitialTd(DmaAdcVoltageB_Chan, DmaAdcVoltageB_TD[0]);
}

void StopAdcDma() {
    CyDmaChDisable(DmaAdcVoltageA_Chan);
    CyDmaChDisable(DmaAdcVoltageB_Chan);
}

#define StartAdcVoltageA() CyDmaChEnable(DmaAdcVoltageA_Chan, 1)    
#define StartAdcVoltageB() CyDmaChEnable(DmaAdcVoltageB_Chan, 1)

void Regulator_Init() {
    PWM_VoltageA_Start();
    PWM_VoltageA_WriteCompare1(0);
    PWM_VoltageA_WriteCompare2(0);
    RegulatorObj.ChanelA.Voltage.Pwm = 0;
    PWM_VoltageB_Start();
    PWM_VoltageB_WriteCompare1(0);
    PWM_VoltageB_WriteCompare2(0);
    RegulatorObj.ChanelB.Voltage.Pwm = 0;
    ADC_Amperage_Start();
    PGA_AmperageA_Start();
    VDAC8_OverAmperageA_Start();
    Comp_OverAmperageA_Start();
    ADC_VoltageA_SetPower(ADC_VoltageA__HIGHPOWER);
    ADC_VoltageA_Start();
    VDAC8_OverVoltageA_Start();
    Comp_OverVoltageA_Start();    
    PGA_AmperageB_Start();
    VDAC8_OverAmperageB_Start();
    Comp_OverAmperageB_Start();
    VDAC8_OverVoltageB_Start();
    Comp_OverVoltageB_Start();
    ADC_VoltageB_Start();
    ADC_VoltageB_SetPower(ADC_VoltageB__HIGHPOWER);
    AMuxAmperage_Start();
    AMuxAmperage_Next(); 
    PGA_OverVoltageA_Start();
    PGA_OverVoltageB_Start();
    memset(&RegulatorObj, 0, sizeof(TRegulatorObject));  
    Count7_OverVoltageA_Start();
    Count7_OverAmperageA_Start();
    Count7_OverVoltageB_Start();
    Count7_OverAmperageB_Start();
    Count7_VoltageA_Ex_Start();
    Count7_VoltageB_Ex_Start();
	IsrPwmVoltageA_StartEx(PwmVoltageAIrqHandler);
	IsrPwmVoltageB_StartEx(PwmVoltageBIrqHandler);
    
    InitAdcDma_A();
    InitAdcDma_B();
    
    RegulatorObj.PreCalculatedValues.value10 = CalcSetPointValueAmperage(10);
    RegulatorObj.PreCalculatedValues.value100 = CalcSetPointValueVoltageA(100);
    RegulatorObj.PreCalculatedValues.value200 = CalcSetPointValueVoltageA(200);
    RegulatorObj.PreCalculatedValues.value400 = CalcSetPointValueVoltageA(400);  
    RegulatorObj.PreCalculatedValues.value500 = CalcSetPointValueAmperage(500);  
    RegulatorObj.PreCalculatedValues.value1000 = CalcSetPointValueAmperage(1000);   
}

void Regulator_Stop() {
	IsrPwmVoltageA_Stop();
	IsrPwmVoltageB_Stop();
    StopAdcDma();
    PWM_VoltageA_Stop();
    PWM_VoltageB_Stop();
    ADC_Amperage_Stop();
    PGA_AmperageA_Stop();
    VDAC8_OverAmperageA_Stop();
    Comp_OverAmperageA_Stop();
    ADC_VoltageA_Stop();
    VDAC8_OverVoltageA_Stop();
    Comp_OverVoltageA_Stop();
    PGA_AmperageB_Stop();
    VDAC8_OverAmperageB_Stop();
    Comp_OverAmperageB_Stop();    
    VDAC8_OverVoltageB_Stop();
    Comp_OverVoltageB_Stop();
    ADC_VoltageB_Stop();
    PGA_OverVoltageA_Stop();
    PGA_OverVoltageB_Stop();
    Count7_OverVoltageA_Stop();
    Count7_OverAmperageA_Stop();
    Count7_OverVoltageB_Stop();
    Count7_VoltageA_Ex_Stop();
    Count7_VoltageB_Ex_Stop();
}

void Regulator_Task() {	 
    ADC_VoltageA_StartConvert();
    StartAdcVoltageA();
    ADC_VoltageB_StartConvert();
    StartAdcVoltageB();
    ADC_Amperage_StartConvert();
    BOOL adcA = FALSE;
    BOOL adcB = FALSE;
	while (TRUE) {
        adcA = RegulatingChannelA();  
        if (adcB) {
            StartAdcVoltageB();
        }      
		TaskSleep(&RegulatorFunction, 1);
        adcB = RegulatingChannelB();
        if (adcA) {
		    StartAdcVoltageA();
        }
		TaskSleep(&RegulatorFunction, 1);	
	}
}

BYTE CalculateOverVoltageAVDACValue(TElectrValue value) {
    DWORD dw = (Voltage_ADC_MAX * 1000) / value;
    dw = (256 * 1000) / dw;
    dw += 3;
    if (dw > 255) {
        dw = 255;        
    }
    return (BYTE)dw;
}

BYTE CalculateOverVoltageBVDACValue(TElectrValue value) {
    DWORD dw = (Voltage_ADC_MAX * 1000) / value;
    dw = (256 * 1000) / dw;
    dw += 3;
    if (dw > 255) {
        dw = 255;        
    }
    return (BYTE)dw;
}

BYTE CalculateOverAmperageAVDACValue(TElectrValue value) {
    DWORD dw = (Amperage_ADC_MAX * 1000) / value;
    dw = (256 * 1000) / dw;
    dw = (dw * 1250) / 1000;
    dw += 5;
    if (dw > 255) {
        dw = 255;        
    }
    return (BYTE)dw;   
}

BYTE CalculateOverAmperageBVDACValue(TElectrValue value) {
    DWORD dw = (Amperage_ADC_MAX * 1000) / (value / 2);
    dw = (256 * 1000) / dw;
    dw = (dw * 1250) / 1000;
    dw += 5;
    if (dw > 255) {
        dw = 255;        
    }
    return (BYTE)dw;   
}

/*>>>-------------- Requests -----------------*/
void Regulator_RequestToChangeSetPointVoltageA(TElectrValue value) {
    value = CalcSetPointValueVoltageA(value);
    RegulatorObj.ChanelA.Voltage.Regulator.SetPoint = value;
   
    if (MainWorkObj.ProtectiveSensitivity == psWeak) {
        RegulatorObj.ChanelA.Voltage.Regulator.Protect = value + RegulatorObj.PreCalculatedValues.value200 /*min 2 volt*/;
        RegulatorObj.ChanelA.Voltage.Regulator.ImmediateCuttOff = value + RegulatorObj.PreCalculatedValues.value400 /*min 4 volt*/;
        VDAC8_OverVoltageA_SetValue(CalculateOverVoltageAVDACValue(value + RegulatorObj.PreCalculatedValues.value100));
    } else {
        RegulatorObj.ChanelA.Voltage.Regulator.Protect = value + RegulatorObj.PreCalculatedValues.value100 /*min 1 volt*/;
        RegulatorObj.ChanelA.Voltage.Regulator.ImmediateCuttOff = value + RegulatorObj.PreCalculatedValues.value200 /*min 2 volt*/;
        VDAC8_OverVoltageA_SetValue(CalculateOverVoltageAVDACValue(value));
    }
}

void Regulator_RequestToChangeSetPointAmperageA(TElectrValue value) {
    value = CalcSetPointValueAmperage(value);
    RegulatorObj.ChanelA.Amperage.Regulator.SetPoint = value;
    
    if (MainWorkObj.ProtectiveSensitivity == psWeak) {
        RegulatorObj.ChanelA.Amperage.Regulator.Protect = value + RegulatorObj.PreCalculatedValues.value100 /*min 100 mA*/;
        RegulatorObj.ChanelA.Amperage.Regulator.ImmediateCuttOff = value + RegulatorObj.PreCalculatedValues.value1000 /*min 1000 mA*/;
        VDAC8_OverAmperageA_SetValue(CalculateOverAmperageAVDACValue(value + RegulatorObj.PreCalculatedValues.value100));       
    } else {
        RegulatorObj.ChanelA.Amperage.Regulator.Protect = value + RegulatorObj.PreCalculatedValues.value10  /*min 10 mA*/;
        RegulatorObj.ChanelA.Amperage.Regulator.ImmediateCuttOff = value + RegulatorObj.PreCalculatedValues.value500  /*min 500 mA*/;
        VDAC8_OverAmperageA_SetValue(CalculateOverAmperageAVDACValue(value));
    }
}

void Regulator_RequestToChangeSetPointVoltageB(TElectrValue value) {
    value = CalcSetPointValueVoltageB(value);
    RegulatorObj.ChanelB.Voltage.Regulator.SetPoint = value;
      
    if (MainWorkObj.ProtectiveSensitivity == psWeak) {
        RegulatorObj.ChanelB.Voltage.Regulator.Protect = value + RegulatorObj.PreCalculatedValues.value200 /*min 2 volt*/;
        RegulatorObj.ChanelB.Voltage.Regulator.ImmediateCuttOff = value + RegulatorObj.PreCalculatedValues.value400 /*min 4 volt*/;
        VDAC8_OverVoltageB_SetValue(CalculateOverVoltageBVDACValue(value + RegulatorObj.PreCalculatedValues.value100));
    } else {
        RegulatorObj.ChanelB.Voltage.Regulator.Protect = value + RegulatorObj.PreCalculatedValues.value100 /*min 1 volt*/;
        RegulatorObj.ChanelB.Voltage.Regulator.ImmediateCuttOff = value + RegulatorObj.PreCalculatedValues.value200 /*min 2 volt*/;
        VDAC8_OverVoltageB_SetValue(CalculateOverVoltageBVDACValue(value));
    }
}


void CachedChangeSetPointAmperageB(BOOL changeImmediate) {
    TElectrValue value;
    if (changeImmediate) {        
        if (MainWorkObj.ProtectiveSensitivity == psWeak) {
            value = RegulatorObj.PreCalculatedValues.value500;
        } else {        
            value = RegulatorObj.PreCalculatedValues.value100;
        }
        RegulatorObj.ChanelBCalculatedSetPoint.SetPointWithShift = RegulatorObj.ChanelB.Amperage.Regulator.SetPoint + value; 
    } else if (RegulatorObj.ChanelA.Amperage.Regulator.Measured <= RegulatorObj.ChanelBCalculatedSetPoint.MeasuredHisMax 
            && RegulatorObj.ChanelA.Amperage.Regulator.Measured >= RegulatorObj.ChanelBCalculatedSetPoint.MeasuredHisMin) {
        return;   
    }
    RegulatorObj.ChanelBCalculatedSetPoint.Calculated = CalculateOverAmperageBVDACValue(RegulatorObj.ChanelBCalculatedSetPoint.SetPointWithShift 
        + RegulatorObj.ChanelA.Amperage.Regulator.Measured);
    value = RegulatorObj.ChanelA.Amperage.Regulator.Measured / 10;
    if (value < 0) {
        value *= -1;       
    }
    RegulatorObj.ChanelBCalculatedSetPoint.MeasuredHisMax = RegulatorObj.ChanelA.Amperage.Regulator.Measured + value;
    RegulatorObj.ChanelBCalculatedSetPoint.MeasuredHisMin = RegulatorObj.ChanelA.Amperage.Regulator.Measured - value;
    VDAC8_OverAmperageB_SetValue(RegulatorObj.ChanelBCalculatedSetPoint.Calculated); 
}
     
void Regulator_RequestToChangeSetPointAmperageB(TElectrValue value) {
    value = CalcSetPointValueAmperage(value);
    RegulatorObj.ChanelB.Amperage.Regulator.SetPoint = value;
     
    if (MainWorkObj.ProtectiveSensitivity == psWeak) {
        RegulatorObj.ChanelB.Amperage.Regulator.Protect = value + RegulatorObj.PreCalculatedValues.value100 /*min 100 mA*/;
        RegulatorObj.ChanelB.Amperage.Regulator.ImmediateCuttOff = value + RegulatorObj.PreCalculatedValues.value1000 /*min 1000 mA*/;        
    } else {
        RegulatorObj.ChanelB.Amperage.Regulator.Protect = value + RegulatorObj.PreCalculatedValues.value10  /*min 10 mA*/;
        RegulatorObj.ChanelB.Amperage.Regulator.ImmediateCuttOff = value + RegulatorObj.PreCalculatedValues.value500  /*min 500 mA*/;
    }
    CachedChangeSetPointAmperageB(TRUE);
}
/*----------------- Requests --------------<<<*/

/*>>>-------------- Measuring -----------------*/
BOOL MeasureVoltageA(PTElectrValue pValue) {
    if (!StatusAdcVoltageA_Read()) {
        return FALSE;     
    }
    *pValue = MedianFilter3(RegulatorObj.ChanelA.Voltage.AdcRawValues[0], RegulatorObj.ChanelA.Voltage.AdcRawValues[1], RegulatorObj.ChanelA.Voltage.AdcRawValues[2]);
    return TRUE;             
}
  
BOOL MeasureVoltageB(PTElectrValue pValue) {
    if (!StatusAdcVoltageB_Read()) {
        return FALSE;     
    }
    *pValue = MedianFilter3(RegulatorObj.ChanelB.Voltage.AdcRawValues[0], RegulatorObj.ChanelB.Voltage.AdcRawValues[1], RegulatorObj.ChanelB.Voltage.AdcRawValues[2]);
    return TRUE;            
}

BOOL MeasureAmperage(PTElectrValue pValue, BYTE chNum) {
    if (AMuxAmperage_GetChannel() == chNum && ADC_Amperage_IsEndConversion(ADC_Amperage_RETURN_STATUS) != 0) {
        INT value = ADC_Amperage_GetResult16();
        AMuxAmperage_Next();
        ADC_Amperage_StartConvert();
        *pValue = value; 
        return TRUE;               
    }
    return FALSE;           
}

BOOL Regulating(PTRegulatorChannel pRegulatorChannel) {
    TElectrValue voltageMeasured = pRegulatorChannel->Voltage.Regulator.Measured;
    TElectrValue voltageSetPoint = pRegulatorChannel->Voltage.Regulator.SetPoint;
    TElectrValue amperageMeasured = pRegulatorChannel->Amperage.Regulator.Measured;
    TElectrValue amperageSetPoint = pRegulatorChannel->Amperage.Regulator.SetPoint;          
    
    SHORT pwmDiff = 0;
    BOOL isLessThanSetPoint;
    INT diffValue;
    INT diffAmperageValue;
    if (pRegulatorChannel->StabilizeMode == smAmperageStab) {
    //если измеренный ток более SetPoint, то регулировать по току (уменьшать напряжение на выходе)
        diffAmperageValue = amperageMeasured - amperageSetPoint;
    } else {
        diffAmperageValue = INT_MIN;
    }
    
    if (diffAmperageValue < 0) { //если меньше чем SetPoint, то регулировать по напряжению
        diffValue = voltageMeasured - voltageSetPoint;    
        isLessThanSetPoint = diffValue < 0;
        if (isLessThanSetPoint) {
            diffValue *= -1;
        }
        if (diffValue < Voltage_Ripple_In_ADC_Counts) { 
            pRegulatorChannel->Voltage.PowerOn = FALSE;
            return FALSE;
        }
    } else {
        diffValue = diffAmperageValue;
        isLessThanSetPoint = FALSE;
        pwmDiff = 1;
    }      
    
    if (diffValue < (Voltage_Ripple_In_ADC_Counts * 2)) { //если разница менее 0.5%
        if (MainWorkObj.RiseRatePowerUp == rrpuSlow) {
            pwmDiff = 1;       
        } else {
            pwmDiff = 1;
        }
    } else if ((diffValue < (Voltage_Ripple_In_ADC_Counts * 4)) || pRegulatorChannel->Voltage.PowerOn) { //если разница менее 1.25%
        if (MainWorkObj.RiseRatePowerUp == rrpuSlow) {
            pwmDiff = 2;  
        } else {
            pwmDiff = 4;
        }
     } else if (diffValue < (Voltage_Ripple_In_ADC_Counts * 8)) { //если разница менее 2.5%
        if (MainWorkObj.RiseRatePowerUp == rrpuSlow) {
            pwmDiff = 4;  
        } else {
            pwmDiff = 16;
        }
    } else if (diffValue < (Voltage_Ripple_In_ADC_Counts * 16)) { //если разница менее 6.2%
        if (MainWorkObj.RiseRatePowerUp == rrpuSlow) {
            pwmDiff = 8;  
        } else {
            pwmDiff = 32;
        }
    } else if (diffValue < (Voltage_Ripple_In_ADC_Counts * 32)) { //если разница менее 10%
        if (MainWorkObj.RiseRatePowerUp == rrpuSlow) {
            pwmDiff = 16;  
        } else {
            pwmDiff = 80;
        }
    } else {
        if (MainWorkObj.RiseRatePowerUp == rrpuSlow) {
            pwmDiff = 64;  
        } else {
            pwmDiff = 200;
        }   
    }   
    
    if (isLessThanSetPoint) { //если напряжение меньше SetPoint        
    //если текущий ток еще замеряется, а предыдущее значение тока близко к максимуму, то pwmDiff установить на минимум. Чтобы не было скачка тока        
        if (diffAmperageValue > amperageSetPoint / -5) {  //если Measured >= 80%
            pwmDiff = 1;    
        }
    } else {
        pwmDiff *= -1;     
    }
    pRegulatorChannel->Voltage.PwmChanged = TRUE;
    pRegulatorChannel->Voltage.Pwm += pwmDiff;    
    return TRUE;    
}

BOOL CheckOverValue(TElectrValue measuredValue, PTRegulatorValue pRegulatorValue, TErrorOver errorOver, TStabilizeMode stabilizeMode) {
    BOOL res = FALSE;    
    if (MainWorkObj.State == mwsWork) {
        if (measuredValue >= pRegulatorValue->ImmediateCuttOff) {
            ThrowErrorOver(errorOver | ERROR_OVER_URGENT_OFF, ERROR_OVER_NONE);
            pRegulatorValue->ErrorOver = TRUE;
            res = TRUE;
        } else if (stabilizeMode == smVoltageStab && measuredValue >= pRegulatorValue->Protect) {
            ThrowErrorOver(errorOver, ERROR_OVER_NONE);
            pRegulatorValue->ErrorOver = TRUE;
            res = TRUE;
        } else if (pRegulatorValue->ErrorOver) {
            ThrowErrorOver(ERROR_OVER_NONE, errorOver);
            pRegulatorValue->ErrorOver = FALSE;
        }
    }      
    return res;
}

BOOL RegulatingChannelA() {
    TElectrValue voltageMeasured, amperageMeasured;
    BOOL bVoltageInConversion = !MeasureVoltageA(&voltageMeasured);
    BOOL bAmperageInConversion = !MeasureAmperage(&amperageMeasured, 0);

    if (!bVoltageInConversion && (RegulatorObj.ChanelA.Voltage.Regulator.Measured != voltageMeasured)) {
        RegulatorObj.ChanelA.Voltage.Regulator.Measured = voltageMeasured;
        if (CheckOverValue(voltageMeasured, &RegulatorObj.ChanelA.Voltage.Regulator, ERROR_OVER_SW_VOLTAGE_A, 
                RegulatorObj.ChanelA.StabilizeMode)) {
            Display_RequestToChangeVoltageA(voltageMeasured, TRUE);
            Display_RequestToChangeAmperageA(RegulatorObj.ChanelA.Amperage.Regulator.Measured, TRUE);
        } else if (MainWorkObj.State != mwsErrGlb) {
            Display_RequestToChangeVoltageA(voltageMeasured, FALSE);
        } else {
            RegulatorObj.ChanelA.Voltage.Regulator.ErrorOver = FALSE;    
        }
    }    
    if (!bAmperageInConversion && (RegulatorObj.ChanelA.Amperage.Regulator.Measured != amperageMeasured)) {
        RegulatorObj.ChanelA.Amperage.Regulator.Measured = amperageMeasured;
        if (CheckOverValue(amperageMeasured, &RegulatorObj.ChanelA.Amperage.Regulator, ERROR_OVER_SW_AMPERAGE_A, 
                RegulatorObj.ChanelA.StabilizeMode)) {
            Display_RequestToChangeVoltageA(RegulatorObj.ChanelA.Voltage.Regulator.Measured, TRUE);
            Display_RequestToChangeAmperageA(amperageMeasured, TRUE);
        } else if (MainWorkObj.State != mwsErrGlb) {
            Display_RequestToChangeAmperageA(amperageMeasured, FALSE);            
            CachedChangeSetPointAmperageB(FALSE);    
        } else {
            RegulatorObj.ChanelA.Amperage.Regulator.ErrorOver = FALSE;    
        }    
    }    
    if (!bVoltageInConversion) {
        if (MainWorkObj.State == mwsWork) {        
            Regulating(&RegulatorObj.ChanelA);
        }        
        return TRUE;
    }
    return FALSE; 
}

BOOL RegulatingChannelB() {
    TElectrValue voltageMeasured, amperageMeasured;
    BOOL bVoltageInConversion = !MeasureVoltageB(&voltageMeasured);
    BOOL bAmperageInConversion = !MeasureAmperage(&amperageMeasured, 1);

    if (!bVoltageInConversion && (RegulatorObj.ChanelB.Voltage.Regulator.Measured != voltageMeasured)) {
        RegulatorObj.ChanelB.Voltage.Regulator.Measured = voltageMeasured; 
        if (CheckOverValue(voltageMeasured, &RegulatorObj.ChanelB.Voltage.Regulator, ERROR_OVER_SW_VOLTAGE_B, 
                RegulatorObj.ChanelB.StabilizeMode)) {
            Display_RequestToChangeVoltageB(voltageMeasured, TRUE);
            Display_RequestToChangeAmperageB(RegulatorObj.ChanelB.Amperage.Regulator.Measured, TRUE);
        } else if (MainWorkObj.State != mwsErrGlb) {
            Display_RequestToChangeVoltageB(voltageMeasured, FALSE);
        }
    }
    if (!bAmperageInConversion && (RegulatorObj.ChanelB.Amperage.Regulator.Measured != amperageMeasured)) {
        RegulatorObj.ChanelB.Amperage.Regulator.Measured = amperageMeasured;
        if (CheckOverValue(amperageMeasured, &RegulatorObj.ChanelB.Amperage.Regulator, ERROR_OVER_SW_AMPERAGE_B, 
                RegulatorObj.ChanelB.StabilizeMode)) {
            Display_RequestToChangeVoltageB(RegulatorObj.ChanelB.Voltage.Regulator.Measured, TRUE);
            Display_RequestToChangeAmperageB(amperageMeasured, TRUE);
        } else if (MainWorkObj.State != mwsErrGlb) {
            Display_RequestToChangeAmperageB(amperageMeasured, FALSE);
        }  
    }  
    if (!bVoltageInConversion) {
        if (MainWorkObj.State == mwsWork) {        
            Regulating(&RegulatorObj.ChanelB);
        }        
        return TRUE;
    }
    return FALSE; 
}
/*----------------- Measuring --------------<<<*/

void Regulator_WorkStateChanged(TMainWorkState oldState, TMainWorkState newState){
    if (oldState == mwsStart && newState == mwsStandBy) {
        ADC_VoltageA_SetOffset(GetAdcOffsetVoltageA());
        ADC_VoltageA_SetScaledGain(GetAdcGainVoltageA());
        ADC_VoltageB_SetOffset(GetAdcOffsetVoltageB());
        ADC_VoltageB_SetScaledGain(GetAdcGainVoltageB());
    } else if (oldState == mwsWork) {
        PWM_VoltageA_WriteCompare1(0);
        PWM_VoltageA_WriteCompare2(0);
        RegulatorObj.ChanelA.Voltage.Pwm = 0;
        PWM_VoltageB_WriteCompare1(0);
        PWM_VoltageB_WriteCompare2(0);
        RegulatorObj.ChanelB.Voltage.Pwm = 0;
        RegulatorObj.ChanelA.Voltage.PowerOn = TRUE;
        RegulatorObj.ChanelB.Voltage.PowerOn = TRUE;
    } else if (newState == mwsWork) {
        RegulatorObj.ChanelA.Voltage.PowerOn = TRUE;
        RegulatorObj.ChanelB.Voltage.PowerOn = TRUE;
    }
    if (newState == mwsWorkStarting) {
        RegulatorObj.ChanelBCalculatedSetPoint.MeasuredHisMax = ElectrValueMin; 
        RegulatorObj.ChanelBCalculatedSetPoint.MeasuredHisMin = ElectrValueMax;
    }
}
/*>>>-------------- Change Stabilize Mode -----------------*/
void Regulator_ChangeStabilizeMode() {
    if (MainWorkObj.StabilizeModeA == smAmperageStab) {
        RegulatorObj.ChanelA.StabilizeMode = smAmperageStab; 
    } else {
        RegulatorObj.ChanelA.StabilizeMode = smVoltageStab; 
    }
    if (MainWorkObj.StabilizeModeB == smAmperageStab) {
        RegulatorObj.ChanelB.StabilizeMode = smAmperageStab; 
    } else {
        RegulatorObj.ChanelB.StabilizeMode = smVoltageStab; 
    }      
}
/*----------------- Change Stabilize Mode --------------<<<*/
/* [] END OF FILE */
