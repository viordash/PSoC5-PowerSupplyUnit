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


TFunction RegulatorFunction;
TRegulator_Object RegulatorObj;


void Regulator_Init() {
    RegulatorObj.Properties.State = mwsInit;
    PWM_VoltageA_Start();
    PWM_VoltageA_WritePeriod(0);
    PWM_VoltageB_Start();
    PWM_VoltageB_WritePeriod(0);
}

void Regulator_Task(){	    

	while (TRUE) {

		TaskSleep(&RegulatorFunction, SYSTICK_mS(100));	
	}
}

/* [] END OF FILE */
