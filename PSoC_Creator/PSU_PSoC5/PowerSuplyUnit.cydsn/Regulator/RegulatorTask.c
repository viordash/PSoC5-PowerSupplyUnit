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
    return (BYTE)dw + 2;    
}

/*>>>-------------- Requests -----------------*/
void Regulator_RequestToChangeSetPointVoltageA(TElectrValue value) {
    value = CalcSetPointValueVoltageA(value);
    RegulatorObj.ChanelA.Voltage.SetPoint = value;
    VDAC8_OverVoltageA_SetValue(CalculateOverVoltageAVDACValue(value));
    InitRegulating(&RegulatorObj.ChanelA.Voltage.Regulating);
}

void Regulator_RequestToChangeSetPointAmperageA(TElectrValue value) {
    RegulatorObj.ChanelA.Amperage.SetPoint = value;
    VDAC8_OverAmperageA_SetValue(CalculateOverAmperageAVDACValue(value));
    InitRegulating(&RegulatorObj.ChanelA.Amperage.Regulating);
}

void Regulator_RequestToChangeSetPointVoltageB(TElectrValue value) {
    value = CalcSetPointValueVoltageB(value);
    RegulatorObj.ChanelB.Voltage.SetPoint = value;
    VDAC8_OverVoltageB_SetValue(CalculateOverVoltageBVDACValue(value));
    InitRegulating(&RegulatorObj.ChanelB.Voltage.Regulating);
}
     
void Regulator_RequestToChangeSetPointAmperageB(TElectrValue value) {
    RegulatorObj.ChanelB.Amperage.SetPoint = value;
    InitRegulating(&RegulatorObj.ChanelB.Amperage.Regulating);
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

BOOL Regulating(PTRegulatorChannel pRegulatorChannel, TWritePwm writePwm, TReadPwm readPwm, BOOL bAmperageInConversion, reg8 * pPWM_VoltageEx) {
    TElectrValue voltageMeasured = pRegulatorChannel->Voltage.Measured;
    TElectrValue voltageSetPoint = pRegulatorChannel->Voltage.SetPoint;
    TElectrValue amperageMeasured = pRegulatorChannel->Amperage.Measured;
    TElectrValue amperageSetPoint = pRegulatorChannel->Amperage.SetPoint;          
    
//    writePwm(voltageSetPoint);     
//    return TRUE;    
    
    INT diffValue = voltageMeasured - voltageSetPoint;
    BOOL isLessThanSetPoint = diffValue < 0;
    if (isLessThanSetPoint) {
        diffValue *= -1;
    }
    if (diffValue < pRegulatorChannel->Voltage.Regulating.MaxRipple) { 
        return FALSE;
    }
    INT pwm = readPwm();
    
    SHORT pwmDiff = 0;
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
    if (!isLessThanSetPoint) { //если напряжение меньше SetPoint        
    //если текущий ток еще замеряется, а предыдущее значение тока близко к максимуму, то pwmDiff установить на минимум. Чтобы не было скачка тока        
        INT amperageDiffValue = amperageSetPoint - amperageMeasured;
        if (bAmperageInConversion && (amperageDiffValue < amperageSetPoint / 5)) {  //если Measured >= 80%
            pwmDiff = 1;    
        }
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

BOOL RegulatingChannelA() {
    TElectrValue voltageMeasured, amperageMeasured;
    BOOL bVoltageInConversion = !MeasureVoltageA(&voltageMeasured);
    BOOL bAmperageInConversion = !MeasureAmperage(&amperageMeasured, 0);

    if (!bVoltageInConversion) {
        if (RegulatorObj.ChanelA.Voltage.Measured != voltageMeasured) {
            RegulatorObj.ChanelA.Voltage.Measured = voltageMeasured;
            Display_RequestToChangeVoltageA(voltageMeasured);
            if (MainWorkObj.State == mwsWork && RegulatorObj.ChanelA.Voltage.Measured >= RegulatorObj.ChanelA.Voltage.SetPoint) {
              //  ThrowErrorOver(ERROR_OVER_SW_VOLTAGE_A);
            }
        }
    }
    if (!bAmperageInConversion && (RegulatorObj.ChanelA.Amperage.Measured != amperageMeasured)) {
        RegulatorObj.ChanelA.Amperage.Measured = amperageMeasured;
        Display_RequestToChangeAmperageA(amperageMeasured);
        if (MainWorkObj.State == mwsWork && RegulatorObj.ChanelA.Amperage.Measured >= RegulatorObj.ChanelA.Amperage.SetPoint) {
          //  ThrowErrorOver(ERROR_OVER_SW_AMPERAGE_A);
        }
    }  
    return MainWorkObj.State == mwsWork && !bVoltageInConversion && Regulating(&RegulatorObj.ChanelA, PWM_VoltageA_WriteCompare, PWM_VoltageA_ReadCompare, 
        bAmperageInConversion, PWM_VoltageA_Ex_Control_PTR);
}

BOOL RegulatingChannelB() {
    TElectrValue voltageMeasured, amperageMeasured;
    BOOL bVoltageInConversion = !MeasureVoltageB(&voltageMeasured);
    BOOL bAmperageInConversion = !MeasureAmperage(&amperageMeasured, 1);

    if (!bVoltageInConversion && (RegulatorObj.ChanelB.Voltage.Measured != voltageMeasured)) {
        RegulatorObj.ChanelB.Voltage.Measured = voltageMeasured;
        Display_RequestToChangeVoltageB(voltageMeasured);
        if (MainWorkObj.State == mwsWork && RegulatorObj.ChanelB.Voltage.Measured >= RegulatorObj.ChanelB.Voltage.SetPoint) {
           // ThrowErrorOver(ERROR_OVER_SW_VOLTAGE_B);
        }
    }
    if (!bAmperageInConversion && (RegulatorObj.ChanelB.Amperage.Measured != amperageMeasured)) {
        RegulatorObj.ChanelB.Amperage.Measured = amperageMeasured;
        Display_RequestToChangeAmperageB(amperageMeasured);
        if (MainWorkObj.State == mwsWork && RegulatorObj.ChanelB.Amperage.Measured >= RegulatorObj.ChanelB.Amperage.SetPoint) {
          //  ThrowErrorOver(ERROR_OVER_SW_AMPERAGE_B);
        }
    }  
    return MainWorkObj.State == mwsWork && !bVoltageInConversion && Regulating(&RegulatorObj.ChanelB, PWM_VoltageB_WriteCompare, PWM_VoltageB_ReadCompare, 
        bAmperageInConversion, PWM_VoltageB_Ex_Control_PTR);
}
/*----------------- Measuring --------------<<<*/

void InitRegulating(PTRegulating pRegulating){
    pRegulating->MaxRipple = 0;
    pRegulating->MinDifferenceValue = INT_MAX;
    pRegulating->PwmValue = 0;
}

void InitAllRegulating(){
    InitRegulating(&RegulatorObj.ChanelA.Voltage.Regulating);
    InitRegulating(&RegulatorObj.ChanelA.Amperage.Regulating);
    InitRegulating(&RegulatorObj.ChanelB.Voltage.Regulating);
    InitRegulating(&RegulatorObj.ChanelB.Amperage.Regulating);
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
        RegulatorObj.ChanelA.Amperage.Regulating.PowerOn = TRUE;
        RegulatorObj.ChanelB.Voltage.Regulating.PowerOn = TRUE;
        RegulatorObj.ChanelB.Amperage.Regulating.PowerOn = TRUE;
    } else if (newState == mwsWork) {
        RegulatorObj.ChanelA.Voltage.Regulating.PowerOn = TRUE;
        RegulatorObj.ChanelA.Amperage.Regulating.PowerOn = TRUE;
        RegulatorObj.ChanelB.Voltage.Regulating.PowerOn = TRUE;
        RegulatorObj.ChanelB.Amperage.Regulating.PowerOn = TRUE;
    }
}

/* [] END OF FILE */
