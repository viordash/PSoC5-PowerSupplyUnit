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
#include "Regulator\RegulatorTask.h"
#include "LCD_Display.h"


TFunction RegulatorFunction;
TRegulatorObject RegulatorObj;

static BOOL ProcessRequests();
void Measure();


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
    
}

void Regulator_Task(){	    

	while (TRUE) {
        if (!ProcessRequests()) {

        }
        Measure();
		TaskSleep(&RegulatorFunction, SYSTICK_mS(100));	
	}
}

static BOOL ProcessRequests() {
BOOL res = FALSE;    


    return res;
}

/*>>>-------------- Requests -----------------*/
void Regulator_RequestToChangeSetPointVoltageA(TElectrValue value) {
    RegulatorObj.VoltageA.SetPoint.Value = value;
    RegulatorObj.VoltageA.SetPoint.Changed = TRUE;
}

void Regulator_RequestToChangeCuttOffVoltageA(TElectrValue value) {
    RegulatorObj.VoltageA.CuttOff.Value = value;
    RegulatorObj.VoltageA.CuttOff.Changed = TRUE;
}

void Regulator_RequestToChangeSetPointAmperageA(TElectrValue value) {
    RegulatorObj.AmperageA.SetPoint.Value = value;
    RegulatorObj.AmperageA.SetPoint.Changed = TRUE;
}

void Regulator_RequestToChangeCuttOffAmperageA(TElectrValue value) {
    RegulatorObj.AmperageA.CuttOff.Value = value;
    RegulatorObj.AmperageA.CuttOff.Changed = TRUE;
}

void Regulator_RequestToChangeSetPointVoltageB(TElectrValue value) {
    RegulatorObj.VoltageB.SetPoint.Value = value;
    RegulatorObj.VoltageB.SetPoint.Changed = TRUE;
}

void Regulator_RequestToChangeCuttOffVoltageB(TElectrValue value) {
    RegulatorObj.VoltageB.CuttOff.Value = value;
    RegulatorObj.VoltageB.CuttOff.Changed = TRUE;
}

void RequestToChangeSetPointAmperageB(TElectrValue value) {
    RegulatorObj.AmperageB.SetPoint.Value = value;
    RegulatorObj.AmperageB.SetPoint.Changed = TRUE;
}

void RequestToChangeCuttOffAmperageB(TElectrValue value) {
    RegulatorObj.AmperageB.CuttOff.Value = value;
    RegulatorObj.AmperageB.CuttOff.Changed = TRUE;
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

void CheckMeasuredVoltageA() {
    TElectrValue value = MeasureVoltageA();
    if (RegulatorObj.VoltageA.Measured != value) {
        RegulatorObj.VoltageA.Measured = value;
        Display_RequestToChangeVoltageA(value);
    }
}

void CheckMeasuredAmperageA() {
    TElectrValue value = MeasureAmperageA();
    if (RegulatorObj.AmperageA.Measured != value) {
        RegulatorObj.AmperageA.Measured = value;
        Display_RequestToChangeAmperageA(value);
    }
}

void CheckMeasuredVoltageB() {
    TElectrValue value = MeasureVoltageB();
    if (RegulatorObj.VoltageB.Measured != value) {
        RegulatorObj.VoltageB.Measured = value;
        Display_RequestToChangeVoltageB(value);
    }
}

void CheckMeasuredAmperageB() {
    TElectrValue value = MeasureAmperageB();
    if (RegulatorObj.AmperageB.Measured != value) {
        RegulatorObj.AmperageB.Measured = value;
        Display_RequestToChangeAmperageB(value);
    }
}

void Measure() {
    CheckMeasuredVoltageA();
    CheckMeasuredAmperageA();
    CheckMeasuredVoltageB();
    CheckMeasuredAmperageB();
}
/*----------------- Measuring --------------<<<*/
/* [] END OF FILE */
