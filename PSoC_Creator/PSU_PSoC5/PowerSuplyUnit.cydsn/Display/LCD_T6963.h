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

#ifndef __LCD_T6963_H
#define __LCD_T6963_H
  
#include <device.h>
#include "Display\Fonts\font_0.h"
#include "Display\Fonts\font_1.h"
#include "Display\Fonts\font_2.h"		 
#include "Display\Fonts\font_3.h"
  
#define T6963_HOR_DOTS 240
#define T6963_VER_DOTS 128
#define T6963_FONT_WIDTH 8	/*ширина символа в битах у выбранного шрифта*/
#define T6963_GRPHIC_HOME 0x0000 /*((T6963_RAM_END / 2) + 1)	*/
#define T6963_GRPHIC_AREA ((T6963_HOR_DOTS / T6963_FONT_WIDTH) + 0)	/*(240 hor. dot / T6963_FONT_WIDTH) + 1 = 40 char per line*/
    
typedef struct {
	PFONT_INFO font;
    PBYTE GraphicBuffer;//[T6963_GRPHIC_AREA * T6963_VER_DOTS];
    BYTE GraphicHome;
} TDisplay, *PTDisplay;
  
extern void _LCD_Init(void);
extern void _LCD_WaitReady();
extern void _LCD_Enable(void);
extern void _LCD_Sleep(void);
extern void _LCD_Reset(void);
extern void _LCD_Clear(void);
extern void _LCD_DrawPixel(BYTE ACoordX, BYTE ACoordY, BOOL APixelVal);
extern void _LCD_Print(PCHAR buffer, INT size, BOOL invertColor, BYTE coordX, BYTE coordY, BOOL flush);
extern void _LCD_SetFont(INT size);	 
extern void _LCD_DrawLine(BYTE coordX1, BYTE coordY1, BYTE coordX2, BYTE coordY2, BOOL value, BOOL flush);
extern void _LCD_DrawRectangle(BYTE coordX1, BYTE coordY1, BYTE coordX2, BYTE coordY2, BOOL value, BOOL flush);
extern void _LCD_FillRectangle(BYTE coordX1, BYTE coordY1, BYTE coordX2, BYTE coordY2, BOOL value, BOOL flush);
extern void _LCD_Flush();

#endif /* __LCD_T6963_H */

/* [] END OF FILE */
