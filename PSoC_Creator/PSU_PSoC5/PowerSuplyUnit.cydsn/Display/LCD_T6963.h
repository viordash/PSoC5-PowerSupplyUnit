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
  
typedef struct {
	WORD coordY;
	WORD coordX;
	PFONT_INFO font;
} TDisplay, *PTDisplay;

extern BOOL T6963_DrawLine(BYTE ACoordX1, BYTE ACoordY1, BYTE ACoordX2, BYTE ACoordY2, BOOL APixelVal);
extern BOOL T6963_DrawRectangle(BYTE ACoordX1, BYTE ACoordY1, BYTE ACoordX2, BYTE ACoordY2, BOOL APixelVal);
extern BOOL T6963_FillRectangle(BYTE ACoordX1, BYTE ACoordY1, BYTE ACoordX2, BYTE ACoordY2, BOOL APixelVal);
  
extern void _LCD_Init(void);
extern void _LCD_WaitReady();
extern void _LCD_Enable(void);
extern void _LCD_Sleep(void);
extern void _LCD_Reset(void);
extern void _LCD_Clear(void);
extern void _LCD_ClearLine(BYTE Line);
extern BOOL _LCD_DrawPixel(BYTE ACoordX, BYTE ACoordY, BOOL APixelVal);
extern void _LCD_SetCursorPos(WORD ACoordX, WORD ACoordY);
extern void _LCD_PrintChar(CHAR ch);
extern void _LCD_Print(PCHAR buffer, INT size);
extern void _LCD_SetFont(INT size);	 

#endif /* __LCD_T6963_H */

/* [] END OF FILE */
