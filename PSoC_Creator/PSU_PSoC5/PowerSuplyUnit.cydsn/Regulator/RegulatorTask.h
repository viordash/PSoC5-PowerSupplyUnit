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
#ifndef __RegulatorTask_H__
#define __RegulatorTask_H__
	
#include <device.h>

    
typedef struct { 
    BOOL Changed;   
    TElectrValue Value;  
} TRegulatorValue, * PTRegulatorValue;

typedef struct { 
    TRegulatorValue SetPoint;  
    TRegulatorValue CuttOff; 
    TElectrValue Measured; 
} TRegulatorVoltage, * PTRegulatorVoltage;

typedef struct { 
    TRegulatorValue SetPoint;  
    TRegulatorValue CuttOff; 
    TElectrValue Measured; 
} TRegulatorAmperage, * PTRegulatorAmperage;

typedef struct {
    TRegulatorVoltage VoltageA; 
    TRegulatorAmperage AmperageA; 
    TRegulatorVoltage VoltageB; 
    TRegulatorAmperage AmperageB; 
} TRegulatorObject, * PTRegulatorObject;

extern TFunction RegulatorFunction;
extern TRegulatorObject RegulatorObj;

extern void Regulator_Init();
extern void Regulator_Task();

extern void Regulator_RequestToChangeSetPointVoltageA(TElectrValue value);
extern void Regulator_RequestToChangeCuttOffVoltageA(TElectrValue value);
extern void Regulator_RequestToChangeSetPointAmperageA(TElectrValue value);
extern void Regulator_RequestToChangeCuttOffAmperageA(TElectrValue value);
extern void Regulator_RequestToChangeSetPointVoltageB(TElectrValue value);
extern void Regulator_RequestToChangeCuttOffVoltageB(TElectrValue value);
extern void Regulator_RequestToChangeSetPointAmperageB(TElectrValue value);
extern void Regulator_RequestToChangeCuttOffAmperageB(TElectrValue value);
	
#endif  /* __RegulatorTask_H__ */
/* [] END OF FILE */
