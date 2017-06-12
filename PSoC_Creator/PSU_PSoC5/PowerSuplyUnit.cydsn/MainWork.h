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
	
#define NETWORK_BUFFER_SIZE 4096
	
typedef enum {
	mwsInit = 0,
	mwsStart,
	mwsStandBy,
	mwsWork,
	mwsChangeSetPoint,
	mwsChangeStabilize,
	mwsErrGlb
} TMainWorkState;

typedef struct {
  TMainWorkState State;
  TPolarMode PolarMode;
} TMainWork_Property, * PTMainWork_Property;

typedef struct {
    TMainWork_Property Properties; 	
} TMainWork_Object, * PTMainWork_Object;

extern TFunction MainWorkFunction;
extern TMainWork_Object MainWorkObj;

extern void MainWork_Init();
extern void MainWork_Task();
	
#endif  /* __MAINWORK_H__ */
/* [] END OF FILE */
