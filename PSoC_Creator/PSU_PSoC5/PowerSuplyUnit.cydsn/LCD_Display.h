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

typedef enum {
	dslNone = 0,
	dslVoltageA,
	dslAmperageA,
	dslVoltageB,
	dslAmperageB,
} TDisplaySelected;

typedef struct {
    WORD Voltage;   /*voltage * 100*/
    WORD Amperage;   /*amperage * 1000*/
} TDisplayChannelData, * PTDisplayChannelData;

typedef enum {
	scmNone = 0,
	scmVoltageAStab,
	scmAmperageAStab,
	scmVoltageBStab,
	scmAmperageBStab,
} TStabilizeChangingMode;

typedef BOOL(*TEventSetPointChanged) (TDisplaySelected changedType, WORD newValue);

typedef struct {
    TDisplayScreen Screen; 
    BOOL ScreenRequest;
    
    TDisplayChannelData ChannelA;
    TDisplayChannelData ChannelB;
    BOOL ChannelARequest;
    BOOL ChannelBRequest;
    
    TDisplaySelected Selected;
    BOOL SelectedRequest;
    TDisplaySelected Focused;
    BOOL FocusedRequest;
    
    TStabilizeChangingMode ChangingStabilizeMode;
    BOOL ChangingStabilizeModeRequest;
    
    BOOL ConfirmStabilizeModeRequest;
} TDisplayRequests, * PTDisplayRequests;

typedef struct {
    TDisplayScreen Screen; 
    TDisplayChannelData ChannelA;
    TDisplayChannelData ChannelB;
    DWORD SelectedTimeout;
    DWORD SelectedFlashingTick;
    TDisplaySelected Selected;
    TDisplaySelected Focused;
    
    TStabilizeChangingMode ChangingStabilizeMode;
    DWORD ChangingStabilizeModeTimeout;
    DWORD ChangingStabilizeModeFlashingTick;
    TStabilizeMode StabilizeModeA;
    TStabilizeMode StabilizeModeB;
} TDisplayProperties, * PTDisplayProperties;

typedef struct {
    TEventSetPointChanged OnSetPointChanged; 
} TDisplayEvents, * PTDisplayEvents;

typedef struct {
    TDisplayProperties Properties; 
    TDisplayRequests Requests;
    TDisplayEvents Events;
} TDisplayObject, * PTDisplayObject;

extern void RequestToChangeScreen(TDisplayScreen newValue);
extern void RequestToChannelA(TDisplayChannelData newValue);
extern void RequestToChannelB(TDisplayChannelData newValue);
extern void RequestToNextSelect();
extern void RequestToPrevSelect();
extern void RequestToSetSelection();
extern void RequestToConfirmSelection();
extern void RequestToSelected(TDisplaySelected newValue);
extern BOOL IsDisplayInSelectionMode();
//extern void RequestToFocused(TDisplaySelected newValue);
//extern void RequestToStabilizeModeA(TStabilizeMode newValue);
//extern void RequestToStabilizeModeB(TStabilizeMode newValue);
extern void RequestToChangingStabilizeMode(TStabilizeChangingMode newValue);
extern void RequestToConfirmStabilizeMode();
extern void RequestToNextStabilizeMode();
extern void RequestToPrevStabilizeMode();
extern void RequestToSetChangingStabilizeMode();
extern BOOL IsDisplayInChangingStabilizeMode();

#endif  /* __LCD_DISPLAY_H__ */
/* [] END OF FILE */
