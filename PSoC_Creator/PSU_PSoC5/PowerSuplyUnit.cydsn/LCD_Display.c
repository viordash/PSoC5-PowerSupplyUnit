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
	_LCD_SetCursorPos(2, 0);
	_LCD_SetFont(3);
	minute = 0;
	second = 0;
    BYTE x = 0;
    BYTE y = 0;
	while (TRUE) {  
        sprintf(buffer, "%02u.%02uv ", minute, second);
		_LCD_Print(buffer, -1, x & 8);
		if (++second >= 60) {
			second = 0;
			if (++minute >= 60) {
				minute= 0;
			}
		}
        
        T6963_FillRectangle(x + 0, y + 32, x + 64, y + 64 + 32, FALSE, TRUE);
        x += 2;
        if (x >= 240 - 64) {
            x = 0;
            y += 3;
            if(y > 128 - 64) {
                y = 0;
            }
        }
        T6963_FillRectangle(x + 0, y + 32, x + 64, y + 64 + 32, TRUE, TRUE);
        
        
		TaskSleep(&DisplayFunction, SYSTICK_mS(300));		
	}
}
