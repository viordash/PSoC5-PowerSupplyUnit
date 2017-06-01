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
#ifndef __LCD_DISPLAY_H__
#define __LCD_DISPLAY_H__

#include <device.h>

extern TFunction DisplayFunction;
extern void Display_Init();
extern void Display_Task();

#define Display_TaskSleep(x) TaskSleep(&DisplayFunction, x)			
#define Display_TaskSleepZero() TaskSleep(&DisplayFunction, 0)

	//LCD driver hardware
#ifdef DISPLAY_LCD_T6963
#include "Display\LCD_T6963.h"
    
#define GLCD_H_SIZE T6963_HOR_DOTS
#define GLCD_V_SIZE T6963_VER_DOTS                

#define Display_Reset   _LCD_Reset                         
#define Display_ClearScreen   _LCD_Clear          
#define Display_Print  _LCD_Print        

#define Display_Enable _LCD_Enable
#define Display_Sleep _LCD_Sleep
#define Display_ClearLine _LCD_ClearLine
#define Display_DrawPixel _LCD_DrawPixel
#define Display_SetCursorPos _LCD_SetCursorPos
#define Display_PrintChar _LCD_PrintChar
#define Display_SetFont _LCD_SetFont
#define Display_SetContrast _LCD_SetContrast
#define Display_DrawLine _LCD_DrawLine
#define Display_DrawRectangle _LCD_DrawRectangle
#define Display_FillRectangle _LCD_FillRectangle
#define Display_Flush _LCD_Flush

#endif


typedef enum {
	dsInit = 0,
	dsStart,
	dsBipolar,
	dsUnipolar,
	dsError
} TDisplayScreen;

typedef struct {
    TDisplayScreen Screen; 
    BOOL Request;
} TDisplayRequests, * PTDisplayRequests;

typedef struct {
    TDisplayScreen Screen; 
} TDisplayProperties, * PTDisplayProperties;

typedef struct {
    TDisplayProperties Properties; 
    TDisplayRequests Requests;
} TDisplayObject, * PTDisplayObject;

extern void RequestToChangeScreen(TDisplayScreen newValue);

#endif  /* __LCD_DISPLAY_H__ */
/* [] END OF FILE */
