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

TFunction MainWorkFunction;
TMainWork_Object MainWorkObj;

void MainWork_Init() {
  MainWorkObj.pProperty = NULL;
  MainWorkObj.State = mwsInit;
}

void MainWork_Task() {	
	while (TRUE) {
		if (MainWorkObj.State == mwsInit) {  
      MainWorkObj.State = mwsStart;
		} else if (MainWorkObj.State == mwsStart) {      
      if (MainWorkObj.pProperty == NULL) {
        MainWorkObj.pProperty = malloc(sizeof(TMainWork_Property));
        if (MainWorkObj.pProperty == NULL) {
          MainWorkObj.Result = mwrErrNoMemory_Syst;
          MainWorkObj.State = mwsErrGlb;
          continue;
        }
      }			
      MainWorkObj.State = mwsWork;
		} else if (MainWorkObj.State == mwsWork) {    
			
		}
		
		TaskSleep(&MainWorkFunction, SYSTICK_mS(100));		
	}
}

/* [] END OF FILE */
