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
TDisplayObject DisplayObj;
void ChangeScreen();

void Display_Init() {
    DisplayObj.Properties.Screen = dsInit;
    
    DisplayObj.Requests.Request = FALSE;    
    DisplayObj.Requests.Screen = dsInit;
}

void Display_Task() {	
    _LCD_Init();
    _LCD_WaitReady();
    RequestToChangeScreen(dsStart);
	while (TRUE) {  
        if (DisplayObj.Requests.Request) {
            if (DisplayObj.Properties.Screen != DisplayObj.Requests.Screen) {
                ChangeScreen();
            }
            DisplayObj.Requests.Request = FALSE;
        }
		TaskSleep(&DisplayFunction, SYSTICK_mS(100));		
	}
}

void RequestToChangeScreen(TDisplayScreen newValue) { 
    DisplayObj.Requests.Screen = newValue;
    DisplayObj.Requests.Request = TRUE;
}

void SetScreen_Bipolar();
void SetScreen_Start() {   
    SetScreen_Bipolar();
}

void SetScreen_Bipolar() {    
    Display_DrawLine(119, 0, 119, 110, TRUE, FALSE);
    Display_DrawLine(120, 0, 120, 110, TRUE, FALSE);
    Display_DrawLine(0, 55, 239, 55, TRUE, FALSE);
    Display_DrawLine(0, 110, 239, 110, TRUE, FALSE);

    Display_SetFont(3);
    Display_Print("12.62", -1, FALSE, 30, 0, FALSE);        
    Display_SetFont(2);
    Display_Print("v", -1, FALSE, 100, 4, FALSE);  
    Display_DrawRectangle(12, 28, 118, 54, TRUE, FALSE);    
    Display_DrawLine(12, 32, 40, 38, TRUE, FALSE);  
    Display_DrawLine(40, 38, 80, 30, TRUE, FALSE);
    
    Display_SetFont(3);
    Display_Print("08.10", -1, FALSE, 30 + 120, 0, FALSE);        
    Display_SetFont(2);
    Display_Print("v", -1, FALSE, 100 + 120, 4, FALSE);  
    Display_DrawRectangle(12 + 120, 28, 118 + 120, 54, TRUE, FALSE);    
    Display_DrawLine(12 + 120, 36, 40 + 120, 42, TRUE, FALSE);  
    Display_DrawLine(40 + 120, 42, 80 + 120, 38, TRUE, FALSE);

    Display_SetFont(2);
    Display_Print("2.503", -1, FALSE, 34, 4 + 56, FALSE);        
    Display_SetFont(2);
    Display_Print("a", -1, FALSE, 104, 4 + 56, FALSE);  
    Display_DrawRectangle(12, 28 + 56, 118, 54 + 56, TRUE, FALSE);    
    Display_DrawLine(12, 36 + 56, 40, 44 + 56, TRUE, FALSE);  
    Display_DrawLine(40, 44 + 56, 80, 42 + 56, TRUE, FALSE);

    Display_SetFont(2);
    Display_Print("4.815", -1, FALSE, 34 + 120, 4 + 56, FALSE);        
    Display_SetFont(2);
    Display_Print("a", -1, FALSE, 104 + 120, 4 + 56, FALSE);  
    Display_DrawRectangle(12 + 120, 28 + 56, 118 + 120, 54 + 56, TRUE, FALSE);    
    Display_DrawLine(12 + 120, 30 + 56, 40 + 120, 32 + 56, TRUE, FALSE);  
    Display_DrawLine(40 + 120, 32 + 56, 80 + 120, 37 + 56, TRUE, FALSE);
    
    Display_Flush();
}

void SetScreen_Unipolar() {    

}

void SetScreen_Error() {    

}


void ChangeScreen() {    
    DisplayObj.Properties.Screen = DisplayObj.Requests.Screen;    
    if (DisplayObj.Properties.Screen == dsStart) {
        SetScreen_Start();
    } else if (DisplayObj.Properties.Screen == dsBipolar) {
        SetScreen_Bipolar();
    } else if (DisplayObj.Properties.Screen == dsUnipolar) {
        SetScreen_Unipolar();
    } else if (DisplayObj.Properties.Screen == dsError) {
        SetScreen_Error();
    }
}