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
#include <stdio.h>
#include "LCD_Display.h"

TFunction DisplayFunction;

void Display_Init() {
    
}

void Display_Task() {	
BYTE minute, second;
CHAR buffer[40];
    _LCD_Init();
    _LCD_WaitReady();
	_LCD_SetCursorPos(1, 22);
	_LCD_SetFont(3);
	minute = 0;
	second = 0;
	while (TRUE) {
        sprintf(buffer, "%02u:%02u", minute, second);
		_LCD_Print(buffer, -1);
		if (++second >= 60) {
			second = 0;
			if (++minute >= 60) {
				minute= 0;
			}
		}
		TaskSleep(&DisplayFunction, SYSTICK_mS(1000));		
	}
}

//static void DisplThread(void const * argument) {
//	BYTE minute, second;
//	Display_WaitReady();
//	_LCD_SetCursorPos(1, 22);
//	_LCD_SetFont(3);
//	minute = 0;
//	second = 0;
//	while (TRUE) {
//		printf("%02u:%02u", minute, second);
//		vTaskDelay(1000 / portTICK_PERIOD_MS);
//		if (++second >= 60) {
//			second = 0;
//			if (++minute >= 60) {
//				minute= 0;
//			}
//		}
//	}
//}


/*
write
Write a character to a file. `libc' subroutines will use this system routine for output to all files, including stdout
Returns -1 on error or number of bytes sent
*/
//int _write(int file, char *ptr, int len) {
//	Display_Print((PCHAR)ptr, len);
//	return len;		 
//}
/* [] END OF FILE */
