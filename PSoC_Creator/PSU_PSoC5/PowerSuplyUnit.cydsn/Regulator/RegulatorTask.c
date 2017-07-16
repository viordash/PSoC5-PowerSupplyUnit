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

static BOOL ProcessRequests();
void Measure();

BOOL ReadCalibratedValues() {
    
    return TRUE;
}

void Regulator_Init() {
    RegulatorControl_Write(0);
    PWM_VoltageA_Start();
    PWM_VoltageA_WritePeriod(0);
    PWM_VoltageB_Start();
    PWM_VoltageB_WritePeriod(0);
    ADC_AmperageA_Start();
    PGA_AmperageA_Start();
    PGA_AmperageB_Start();
    VDAC8_OverAmperageA_Start();
    Comp_OverAmperageA_Start();
    VDAC8_OverAmperageB_Start();
    Comp_OverAmperageB_Start();
    PGA_VoltageA_Start();
    ADC_VoltageA_Start();
    VDAC8_OverVoltageA_Start();
    Comp_OverVoltageA_Start();
    VDAC8_OverVoltageB_Start();
    Comp_OverVoltageB_Start();
    ADC_VoltageB_Start();
    AMuxChanelB_Start();
    memset(&RegulatorObj, 0, sizeof(TRegulatorObject));   
    ReadCalibratedValues();
}

void Regulator_Task(){	    

	while (TRUE) {
        if (!ProcessRequests()) {

        }
        Measure();
		TaskSleep(&RegulatorFunction, SYSTICK_mS(100));	
	}
}


BOOL IsFallingSetPoint(TElectrValue voltageMeasured, TElectrValue valueExpected) {
    INT diffValue = voltageMeasured - valueExpected;
    TElectrValue minValue = voltageMeasured / 16;     //минимальное значение для моментального сброса напряжения
    return (diffValue > minValue);
}


BOOL RequestToChangeSetPointVoltage(PTRegulatorVoltage pRegulatorVoltage, TPWMWriteCompare PWMWriteCompare) {
    if (!pRegulatorVoltage->SetPoint.Changed) {
        return FALSE;
    }
    
    pRegulatorVoltage->Expected = pRegulatorVoltage->SetPoint.Value; 
    if (IsFallingSetPoint(pRegulatorVoltage->Measured, pRegulatorVoltage->Expected)) {//если новое значение меньше, то установить сразу
        TElectrValue pwmNew = GetCalibratedPwmValue(pRegulatorVoltage->SetPoint.Value); 
        PWMWriteCompare(pwmNew);    
    }
    pRegulatorVoltage->SetPoint.Changed = FALSE;
    return TRUE;
}

BOOL RequestToChangeSetPointAmperage(PTRegulatorAmperage pRegulatorAmperage) {
    if (!pRegulatorAmperage->SetPoint.Changed) {
        return FALSE;
    }    
    pRegulatorAmperage->Expected = pRegulatorAmperage->SetPoint.Value; 
    pRegulatorAmperage->SetPoint.Changed = FALSE;
    return TRUE;
}

static BOOL ProcessRequests() {
BOOL res = FALSE;    
    if (RequestToChangeSetPointVoltage(&RegulatorObj.ChanelA.Voltage, PWM_VoltageA_WriteCompare)) {
        res = TRUE;    
    }
    if (RequestToChangeSetPointVoltage(&RegulatorObj.ChanelB.Voltage, PWM_VoltageA_WriteCompare)) {
        res = TRUE;    
    } 
    if (RequestToChangeSetPointAmperage(&RegulatorObj.ChanelA.Amperage)) {
        res = TRUE;    
    }
    if (RequestToChangeSetPointAmperage(&RegulatorObj.ChanelB.Amperage)) {
        res = TRUE;    
    }
    return res;
}
/*>>>-------------- Requests -----------------*/
void Regulator_RequestToChangeSetPointVoltageA(TElectrValue value) {
    RegulatorObj.ChanelA.Voltage.SetPoint.Value = value;
    RegulatorObj.ChanelA.Voltage.SetPoint.Changed = TRUE;
}

void Regulator_RequestToChangeCuttOffVoltageA(TElectrValue value) {
    RegulatorObj.ChanelA.Voltage.CuttOff.Value = value;
    RegulatorObj.ChanelA.Voltage.CuttOff.Changed = TRUE;
}

void Regulator_RequestToChangeSetPointAmperageA(TElectrValue value) {
    RegulatorObj.ChanelA.Amperage.SetPoint.Value = value;
    RegulatorObj.ChanelA.Amperage.SetPoint.Changed = TRUE;
}

void Regulator_RequestToChangeCuttOffAmperageA(TElectrValue value) {
    RegulatorObj.ChanelA.Amperage.CuttOff.Value = value;
    RegulatorObj.ChanelA.Amperage.CuttOff.Changed = TRUE;
}

void Regulator_RequestToChangeSetPointVoltageB(TElectrValue value) {
    RegulatorObj.ChanelB.Voltage.SetPoint.Value = value;
    RegulatorObj.ChanelB.Voltage.SetPoint.Changed = TRUE;
}
     
void Regulator_RequestToChangeCuttOffVoltageB(TElectrValue value) {
    RegulatorObj.ChanelB.Voltage.CuttOff.Value = value;
    RegulatorObj.ChanelB.Voltage.CuttOff.Changed = TRUE;
}
     
void Regulator_RequestToChangeSetPointAmperageB(TElectrValue value) {
    RegulatorObj.ChanelB.Amperage.SetPoint.Value = value;
    RegulatorObj.ChanelB.Amperage.SetPoint.Changed = TRUE;
}

void Regulator_RequestToChangeCuttOffAmperageB(TElectrValue value) {
    RegulatorObj.ChanelB.Amperage.CuttOff.Value = value;
    RegulatorObj.ChanelB.Amperage.CuttOff.Changed = TRUE;
}
/*----------------- Requests --------------<<<*/

/*>>>-------------- Measuring -----------------*/
TElectrValue MeasureVoltageA() {
    return 0;    
}

TElectrValue MeasureAmperageA() {
    return 0;    
}

TElectrValue MeasureVoltageB() {
    return 0;    
}

TElectrValue MeasureAmperageB() {
    return 0;    
}

BOOL Regulating(PTRegulatorChannel pRegulatorChannel, TWritePwm writePwm, TReadPwm readPwm) {
    TElectrValue voltageMeasured = pRegulatorChannel->Voltage.Measured;
    TElectrValue amperageMeasured = pRegulatorChannel->Amperage.Measured;
        
    INT diffValue = voltageMeasured - pRegulatorChannel->Voltage.SetPoint.Value;
    BOOL isNegative = diffValue < 0;
    if (isNegative) {
        diffValue *= -1;
    }
    if (diffValue < voltageMeasured / 1024) { //если несоответсвие менее 0.1% не регулировать
        return FALSE;
    }
    TElectrValue pwmDiff;
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
    } else {
        if (!isNegative) { //если новое значение резко уменьшилось, то установить сразу
            TElectrValue pwmNew = GetCalibratedPwmValue(pRegulatorChannel->Voltage.SetPoint.Value); 
            writePwm(pwmNew); 
            return TRUE;
        } else {
            if (MainWorkObj.RiseRatePowerUp == rrpuSlow) {
                pwmDiff = 64;  
            } else {
                pwmDiff = 128;
            }            
        }
    }

    TElectrValue pwmOld = readPwm();
    if (!isNegative) {
        pwmDiff *= -1;     
    }
    writePwm(pwmOld + pwmDiff);     
    return TRUE;    
}

BOOL RegulatingChannelA() {
    TElectrValue voltageMeasured = MeasureVoltageA();
    if (RegulatorObj.ChanelA.Voltage.Measured != voltageMeasured) {
        RegulatorObj.ChanelA.Voltage.Measured = voltageMeasured;
        Display_RequestToChangeVoltageA(voltageMeasured);
    }
    TElectrValue amperageMeasured = MeasureAmperageA();
    if (RegulatorObj.ChanelA.Amperage.Measured != amperageMeasured) {
        RegulatorObj.ChanelA.Amperage.Measured = amperageMeasured;
        Display_RequestToChangeAmperageA(amperageMeasured);
    }  
    return Regulating(&RegulatorObj.ChanelA, PWM_VoltageA_WriteCompare, PWM_VoltageA_ReadCompare);
}

void Measure() {
//    CheckMeasuredVoltageA();
//    CheckMeasuredAmperageA();
//    CheckMeasuredVoltageB();
//    CheckMeasuredAmperageB();
}
/*----------------- Measuring --------------<<<*/
/* [] END OF FILE */
