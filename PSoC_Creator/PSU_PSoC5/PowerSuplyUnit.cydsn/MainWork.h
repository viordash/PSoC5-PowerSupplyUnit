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
		

typedef struct {
    DWORD WorkStartingPeriod;
    TMainWorkState State;
    TRiseRatePowerUp RiseRatePowerUp;
    TStabilizeMode StabilizeModeA;
    TStabilizeMode StabilizeModeB;
    TChangedValue ChangedValue;
    TElectrValue SetPointVoltageA;
    TElectrValue SetPointAmperageA;
    TElectrValue SetPointVoltageB;
    TElectrValue SetPointAmperageB;
    BOOL HwPrSupressed;
    TEepromStrorage Storage;
    TProtectiveBehavior ProtectiveBehavior;
} TMainWork_Object, * PTMainWork_Object;

extern TFunction MainWorkFunction;
extern TMainWork_Object MainWorkObj;

extern void MainWork_Init();
extern void MainWork_Task();
extern void SuppressProtection(BOOL withOn);
extern void ChangeOutputState();
extern void MouseState(BOOL present); 
extern void MouseChangingValue (INT value);
extern void ResetErrorState();
extern void ThrowException(PCHAR message);
extern void ThrowErrorOver(TErrorOver setErrorOver, TErrorOver resetErrorOver);
	
#endif  /* __MAINWORK_H__ */
/* [] END OF FILE */
