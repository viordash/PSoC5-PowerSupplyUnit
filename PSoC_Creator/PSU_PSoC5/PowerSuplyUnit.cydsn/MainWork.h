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
#ifndef __MAINWORK_H__
#define __MAINWORK_H__
	
#include <device.h>
		
typedef enum {
	mwsInit = 0,
	mwsStart,
	mwsStandBy,
	mwsWork,
	mwsErrGlb
} TMainWorkState;

typedef struct {
    TMainWorkState State;
    TPolarMode PolarMode;
    TStabilizeMode StabilizeModeA;
    TStabilizeMode StabilizeModeB;
    TChangedValue ChangedValue;
    TElectrValue SetPointVoltageA;
    TElectrValue SetPointAmperageA;
    TElectrValue SetPointVoltageB;
    TElectrValue SetPointAmperageB;
    BOOL HwPrSupressed;
} TMainWork_Property, * PTMainWork_Property;

typedef struct {
    TMainWork_Property Properties; 	
} TMainWork_Object, * PTMainWork_Object;

extern TFunction MainWorkFunction;
extern TMainWork_Object MainWorkObj;

extern void MainWork_Init();
extern void MainWork_Task();
extern void ResetErrorState();
extern void SuppressProtection(BOOL withOn);
extern void ChangeOutputState();
extern void MouseState(BOOL present); 
extern void MouseChangingValue (INT value);
	
#endif  /* __MAINWORK_H__ */
/* [] END OF FILE */
