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
#include <device.h>
#include <stdlib.h>
#include <stdio.h>
#include "LCD_Display.h"
#include "MainWork.h"
#include "Regulator\RegulatorTask.h"

DWORD SysTickCountWDG = 0;
void TaskShedul(void) {
	while (TRUE) {//Функция расположенная выше имеет больший приоритет
		if (SysTickCountWDG < SysTickCount) {
			SysTickCountWDG = SysTickCount + SYSTICK_mS(100); /*100 mS, CYWDT_128_TICKS   -   256 - 384   ms*/
#ifdef WDT_ENABLE
			CyWdtClear();
#endif  
		}
		TaskResume(&RegulatorFunction, NULL);
		TaskResume(&MainWorkFunction, NULL);
		TaskResume(&DisplayFunction, NULL);
	}
}

void TasksInit(void) {
	DWORD stack = __get_MSP();
	stack -= 0x500; //стек для основного цикла

	TaskExecInit(&DisplayFunction, (POINTER)Display_Task, stack);
	stack -= 0x700;

	TaskExecInit(&MainWorkFunction, (POINTER)MainWork_Task, stack);
	stack -= 0x800;
    
	TaskExecInit(&RegulatorFunction, (POINTER)Regulator_Task, stack);
	stack -= 0x500;
}

void DeviceInit() {
    MultiJog_Start();       
    MultiJog_SetCounter(0);
    MultiJog_FreqMeter_Start();
    MultiJog_Reset_Start();
    BtnOk_Reset_Start();
    FanCtrl_Start();
}

int main() {
	/* Place your initialization/startup code here (e.g. MyInst_Start()) */
	__disable_irq();
    DeviceInit();
	SystemOS_Init();
#ifdef WDT_ENABLE
	CyWdtStart(CYWDT_128_TICKS, CYWDT_LPMODE_MAXINTER);
#endif 
    Regulator_Init();
	Display_Init();
	MainWork_Init();
	TasksInit();
	//  __enable_irq();
	CyGlobalIntEnable;
	TaskShedul();
	return 0;
}


/* [] END OF FILE */
