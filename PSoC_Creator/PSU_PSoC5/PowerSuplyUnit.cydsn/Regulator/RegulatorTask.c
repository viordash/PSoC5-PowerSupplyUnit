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
#include "Regulator\CalcAdcValue.h"


TFunction RegulatorFunction;
TRegulatorObject RegulatorObj;

BOOL RegulatingChannelA();
BOOL RegulatingChannelB();
void InitRegulating(PTRegulating pRegulating);

BOOL ReadCalibratedValues() {
    
    return TRUE;
}

void Regulator_Init() {
    PWM_VoltageA_Start();
    PWM_VoltageA_WriteCompare(0);
    PWM_VoltageB_Start();
    PWM_VoltageB_WriteCompare(0);
    ADC_Amperage_Start();
    PGA_AmperageA_Start();
    VDAC8_OverAmperageA_Start();
    Comp_OverAmperageA_Start();
    ADC_VoltageA_SetPower(ADC_VoltageA__HIGHPOWER);
    ADC_VoltageA_Start();
    VDAC8_OverVoltageA_Start();
    Comp_OverVoltageA_Start();
    VDAC8_OverVoltageB_Start();
    Comp_OverVoltageB_Start();
    ADC_VoltageB_Start();
    ADC_VoltageB_SetPower(ADC_VoltageB__HIGHPOWER);
    AMuxAmperage_Start();
    AMuxAmperage_Next(); 
    PGA_OverVoltageA_Start();
    PGA_OverVoltageB_Start();
    memset(&RegulatorObj, 0, sizeof(TRegulatorObject));   
    ReadCalibratedValues();
}

void Regulator_Task() {	 
    ADC_VoltageA_StartConvert();
    ADC_VoltageB_StartConvert();
    ADC_Amperage_StartConvert();
	while (TRUE) {
        RegulatingChannelA();
		TaskSleep(&RegulatorFunction, 1);	
        RegulatingChannelB();
		TaskSleep(&RegulatorFunction, 1);	
	}
}

BYTE CalculateOverVoltageAVDACValue(TElectrValue value) {
    DWORD dw = (Voltage_ADC_MAX * 1000) / value;
    dw = (256 * 1000) / dw;
    return (BYTE)dw + 3;
}

BYTE CalculateOverVoltageBVDACValue(TElectrValue value) {
    DWORD dw = (Voltage_ADC_MAX * 1000) / value;
    dw = (256 * 1000) / dw;
    return (BYTE)dw + 3;
}

BYTE CalculateOverAmperageAVDACValue(TElectrValue value) {
    DWORD dw = (Amperage_ADC_MAX * 1000) / value;
    dw = (256 * 1000) / dw;
    dw = (dw * 1250) / 1000;
    return (BYTE)dw + 5;    
}

/*>>>-------------- Requests -----------------*/
void Regulator_RequestToChangeSetPointVoltageA(TElectrValue value) {
    value = CalcSetPointValueVoltageA(value);
    RegulatorObj.ChanelA.Voltage.Regulator.SetPoint = value;
    RegulatorObj.ChanelA.Voltage.Regulator.Protect = value + CalcSetPointValueVoltageA(100) /*min 1 volt*/;
    RegulatorObj.ChanelA.Voltage.Regulator.ImmediateCuttOff = value + CalcSetPointValueVoltageA(200) /*min 2 volt*/;
    VDAC8_OverVoltageA_SetValue(CalculateOverVoltageAVDACValue(value));
    InitRegulating(&RegulatorObj.ChanelA.Voltage.Regulating);
}

void Regulator_RequestToChangeSetPointAmperageA(TElectrValue value) {
    value = CalcSetPointValueAmperage(value);
    RegulatorObj.ChanelA.Amperage.Regulator.SetPoint = value;
    RegulatorObj.ChanelA.Amperage.Regulator.Protect = value + CalcSetPointValueAmperage(10) /*min 10 mA*/;
    RegulatorObj.ChanelA.Amperage.Regulator.ImmediateCuttOff = value + CalcSetPointValueAmperage(500) /*min 500 mA*/;
    VDAC8_OverAmperageA_SetValue(CalculateOverAmperageAVDACValue(value));
}

void Regulator_RequestToChangeSetPointVoltageB(TElectrValue value) {
    value = CalcSetPointValueVoltageB(value);
    RegulatorObj.ChanelB.Voltage.Regulator.SetPoint = value;
    RegulatorObj.ChanelB.Voltage.Regulator.Protect = value + CalcSetPointValueVoltageB(100) /*min 1 volt*/;
    RegulatorObj.ChanelB.Voltage.Regulator.ImmediateCuttOff = value + CalcSetPointValueVoltageB(200) /*min 2 volt*/;
    VDAC8_OverVoltageB_SetValue(CalculateOverVoltageBVDACValue(value));
    InitRegulating(&RegulatorObj.ChanelB.Voltage.Regulating);
}
     
void Regulator_RequestToChangeSetPointAmperageB(TElectrValue value) {
    value = CalcSetPointValueAmperage(value);
    RegulatorObj.ChanelB.Amperage.Regulator.SetPoint = value;
    RegulatorObj.ChanelB.Amperage.Regulator.Protect = value + CalcSetPointValueAmperage(10) /*min 10 mA*/;
    RegulatorObj.ChanelB.Amperage.Regulator.ImmediateCuttOff = value + CalcSetPointValueAmperage(500) /*min 500 mA*/;
}
/*----------------- Requests --------------<<<*/

/*>>>-------------- Measuring -----------------*/
BOOL MeasureVoltageA(PTElectrValue pValue) {
    if (ADC_VoltageA_IsEndConversion(ADC_VoltageA_RETURN_STATUS) == 0) {
        return FALSE;    
    }       
    INT value = ADC_VoltageA_GetResult16();
    *pValue = value;
    return TRUE;             
}
  
BOOL MeasureVoltageB(PTElectrValue pValue) {
    if (ADC_VoltageB_IsEndConversion(ADC_VoltageB_RETURN_STATUS) == 0) {
        return FALSE;    
    }       
    INT value = ADC_VoltageB_GetResult16();
    *pValue = value;
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

BOOL Regulating(PTRegulatorChannel pRegulatorChannel, TWritePwm writePwm, TReadPwm readPwm, reg8 * pPWM_VoltageEx) {
    TElectrValue voltageMeasured = pRegulatorChannel->Voltage.Regulator.Measured;
    TElectrValue voltageSetPoint = pRegulatorChannel->Voltage.Regulator.SetPoint;
    TElectrValue amperageMeasured = pRegulatorChannel->Amperage.Regulator.Measured;
    TElectrValue amperageSetPoint = pRegulatorChannel->Amperage.Regulator.SetPoint;          
    
//    writePwm(voltageSetPoint);     
//    return TRUE;    
    
    SHORT pwmDiff = 0;
    BOOL isLessThanSetPoint;
    INT diffValue;
    INT diffAmperageValue;
    if (pRegulatorChannel->StabilizeMode == smAmperageStab) {
    //если измеренный ток более SetPoint, то регулировать по току (уменьшать напряжение на выходе)
        diffAmperageValue = amperageMeasured - amperageSetPoint;
    } else {
        diffAmperageValue = -1;
    }
    
    if (diffAmperageValue < 0) { //если меньше чем SetPoint, то регулировать по напряжению
        diffValue = voltageMeasured - voltageSetPoint;    
        isLessThanSetPoint = diffValue < 0;
        if (isLessThanSetPoint) {
            diffValue *= -1;
        }
        if (diffValue < pRegulatorChannel->Voltage.Regulating.MaxRipple) { 
            return FALSE;
        }
    } else {
        diffValue = diffAmperageValue;
        InitRegulating(&(pRegulatorChannel->Voltage.Regulating));
        isLessThanSetPoint = FALSE;
        pwmDiff = 1;
    }    
    
    INT pwm = readPwm();    
    
    if (diffValue < /*5*/Voltage_Ripple_In_ADC_Counts) { //если разница менее 0.25%        
        if (pRegulatorChannel->Voltage.Regulating.MinDifferenceValue > diffValue) {
            pRegulatorChannel->Voltage.Regulating.MinDifferenceValue = diffValue;    
            pRegulatorChannel->Voltage.Regulating.PwmValue = pwm; 
        } else {
            pRegulatorChannel->Voltage.Regulating.MaxRipple = amperageMeasured / 10;
            if (pRegulatorChannel->Voltage.Regulating.MaxRipple < Voltage_Ripple_In_ADC_Counts) {
                pRegulatorChannel->Voltage.Regulating.MaxRipple = Voltage_Ripple_In_ADC_Counts;    
            }
            pwm = pRegulatorChannel->Voltage.Regulating.PwmValue;
            pRegulatorChannel->Voltage.Regulating.PowerOn = FALSE;
        }        
    } else if (diffValue < /*20*/(Voltage_Ripple_In_ADC_Counts * 2)) { //если разница менее 0.5%
        if (MainWorkObj.RiseRatePowerUp == rrpuSlow) {
            pwmDiff = 1;       
        } else {
            pwmDiff = 1;
        }
    } else if ((diffValue < /*60*/(Voltage_Ripple_In_ADC_Counts * 4)) || pRegulatorChannel->Voltage.Regulating.PowerOn) { //если разница менее 1.25%
        if (MainWorkObj.RiseRatePowerUp == rrpuSlow) {
            pwmDiff = 1;  
        } else {
            pwmDiff = 8;
        }
     } else if (diffValue < /*100*/(Voltage_Ripple_In_ADC_Counts * 8)) { //если разница менее 2.5%
        if (MainWorkObj.RiseRatePowerUp == rrpuSlow) {
            pwmDiff = 4;  
        } else {
            pwmDiff = 16;
        }
    } else if (diffValue < /*200*/(Voltage_Ripple_In_ADC_Counts * 16)) { //если разница менее 6.2%
        if (MainWorkObj.RiseRatePowerUp == rrpuSlow) {
            pwmDiff = 8;  
        } else {
            pwmDiff = 25;
        }
    } else {
        InitRegulating(&(pRegulatorChannel->Voltage.Regulating));
        if (diffValue < /*500*/(Voltage_Ripple_In_ADC_Counts * 32)) { //если разница менее 10%
            if (MainWorkObj.RiseRatePowerUp == rrpuSlow) {
                pwmDiff = 16;  
            } else {
                pwmDiff = 50;
            }
        } else {
            if (MainWorkObj.RiseRatePowerUp == rrpuSlow) {
                pwmDiff = 32;  
            } else {
                pwmDiff = 80;
            }   
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
    
    pwm <<= 1;
    pwm += *pPWM_VoltageEx;
    pwm += pwmDiff;
    
    if (pwm > PWM_MAX_PERIOD * 2) {
        pwm = PWM_MAX_PERIOD * 2;    
    } else if (pwm < 0) {
        pwm = 0;    
    }
    *pPWM_VoltageEx = pwm & 0x01;
    pwm >>= 1;
    writePwm(pwm);     
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
        } else {
            RegulatorObj.ChanelA.Amperage.Regulator.ErrorOver = FALSE;    
        }    
    }  
    return MainWorkObj.State == mwsWork 
    && !bVoltageInConversion 
    && Regulating(&RegulatorObj.ChanelA, PWM_VoltageA_WriteCompare, PWM_VoltageA_ReadCompare, PWM_VoltageA_Ex_Control_PTR); //*/
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
    return MainWorkObj.State == mwsWork 
        && !bVoltageInConversion 
        && Regulating(&RegulatorObj.ChanelB, PWM_VoltageB_WriteCompare, PWM_VoltageB_ReadCompare, PWM_VoltageB_Ex_Control_PTR); //*/
}
/*----------------- Measuring --------------<<<*/

void InitRegulating(PTRegulating pRegulating){
    pRegulating->MaxRipple = 0;
    pRegulating->MinDifferenceValue = INT_MAX;
    pRegulating->PwmValue = 0;
}

void InitAllRegulating(){
    InitRegulating(&RegulatorObj.ChanelA.Voltage.Regulating);
    InitRegulating(&RegulatorObj.ChanelB.Voltage.Regulating);
}

void Regulator_WorkStateChanged(TMainWorkState oldState, TMainWorkState newState){
    if (oldState == mwsStart && newState == mwsStandBy) {
        ADC_VoltageA_SetOffset(GetAdcOffsetVoltageA());
        ADC_VoltageA_SetScaledGain(GetAdcGainVoltageA());
        ADC_VoltageB_SetOffset(GetAdcOffsetVoltageB());
        ADC_VoltageB_SetScaledGain(GetAdcGainVoltageB());
    } else if (oldState == mwsWork) {
        PWM_VoltageA_WriteCompare(0);
        PWM_VoltageB_WriteCompare(0);
        InitAllRegulating();
        RegulatorObj.ChanelA.Voltage.Regulating.PowerOn = TRUE;
        RegulatorObj.ChanelB.Voltage.Regulating.PowerOn = TRUE;
    } else if (newState == mwsWork) {
        RegulatorObj.ChanelA.Voltage.Regulating.PowerOn = TRUE;
        RegulatorObj.ChanelB.Voltage.Regulating.PowerOn = TRUE;
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
