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
    BOOL State;
} TRegulator_Property, * PTRegulator_Property;

typedef struct {
    TRegulator_Property Properties; 	
} TRegulator_Object, * PTRegulator_Object;

extern TFunction RegulatorFunction;
extern TRegulator_Object RegulatorObj;

extern void Regulator_Init();
extern void Regulator_Task();
	
#endif  /* __RegulatorTask_H__ */
/* [] END OF FILE */
