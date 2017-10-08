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

//typedef struct { 
//    INT MinDifferenceValue;
////    TElectrValue MaxRipple; 
//} TRegulating, * PTRegulating;

//typedef struct { 
//    INT PwmDiff;
//    TElectrValue PrevMeasured; 
//    TElectrValue Value; 
//} TPwmImpact, * PTPwmImpact;
    
typedef struct { 
    TElectrValue SetPoint;  
    TElectrValue ImmediateCuttOff; 
    TElectrValue Protect; 
    TElectrValue Measured; 
    BOOL ErrorOver;    
} TRegulatorValue, * PTRegulatorValue;
    
typedef struct { 
    TRegulatorValue Regulator; 
//    TRegulating Regulating; 
    INT Pwm;
    BOOL PwmChanged;
//    TPwmImpact PwmImpact;
    BOOL PowerOn;
    TElectrValue AdcRawValues[4]; 
} TRegulatorVoltage, * PTRegulatorVoltage;
    
typedef struct { 
    TRegulatorValue Regulator; 
} TRegulatorAmperage, * PTRegulatorAmperage;

typedef struct { 
    TRegulatorVoltage Voltage; 
    TRegulatorAmperage Amperage; 
    TStabilizeMode StabilizeMode;
} TRegulatorChannel, * PTRegulatorChannel;

typedef struct {
    TRegulatorChannel ChanelA; 
    TRegulatorChannel ChanelB; 
	TCalibrateItem CalibratedVoltage[VOLTAGE_CALIBRATE_POINT_COUNT];
	TCalibrateItem CalibratedAmperage[VOLTAGE_CALIBRATE_POINT_COUNT];
} TRegulatorObject, * PTRegulatorObject;


typedef void(*TPWMWriteCompare) (uint16 compare);
typedef void (*TDisplay_RequestToChangeValue)(TElectrValue value);
typedef TElectrValue (*TMeasureAdc)();
typedef void(*TWritePwm) (uint16 compare);
typedef uint16(*TReadPwm) ();

extern TFunction RegulatorFunction;
extern TRegulatorObject RegulatorObj;

extern void Regulator_Init();
extern void Regulator_Stop();
extern void Regulator_Task();

extern void Regulator_RequestToChangeSetPointVoltageA(TElectrValue value);
extern void Regulator_RequestToChangeSetPointAmperageA(TElectrValue value);
extern void Regulator_RequestToChangeSetPointVoltageB(TElectrValue value);
extern void Regulator_RequestToChangeSetPointAmperageB(TElectrValue value);
extern void Regulator_WorkStateChanged(TMainWorkState oldState, TMainWorkState newState);
extern void Regulator_ChangeStabilizeMode();
	
#endif  /* __RegulatorTask_H__ */
/* [] END OF FILE */
