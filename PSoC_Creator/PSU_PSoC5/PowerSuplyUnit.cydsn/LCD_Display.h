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
#include "Display\ValueIndicator.h"
#include "Display\ValueIndicatorHelper.h"
#include "Display\SymbolIndicator.h"
#include "Display\SymbolIndicatorHelper.h"

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
	dsWork,
	dsError
} TDisplayScreen;

typedef struct {
    TValueIndicator Indicator;
    TElectrValue NewValue;
    BOOL RequestToChangeValue;
    BOOL RequestToSelect;
    BOOL RequestToFocus;
} TVariableValue, * PTVariableValue;

typedef struct {
    TVariableValue Value;
    DWORD UpdateTickCount;
    TElectrValue PostponedValues[3];
    BYTE PostponedIndex;
} TMeasuredValue, * PTMeasuredValue;

typedef struct {
    TSymbolIndicator Indicator;
    BOOL RequestToSelect;
    BOOL RequestToFocus;
} TSymbol, * PTSymbol;

typedef struct {
    TDisplayScreen Screen; 
    BOOL ScreenRequest;   
    BOOL ShowError;
    CHAR Message[200];
} TDisplayRequests, * PTDisplayRequests;

typedef struct {
    TDisplayScreen Screen; 
    DWORD SelectedTimeout;
    DWORD SelectedFlashingTick;
    PTValueIndicator SelectedIndicator;
    DWORD SelectedSymbolTimeout;
    DWORD SelectedSymbolFlashingTick;
    PTSymbolIndicator SelectedSymbol;
} TDisplayProperties, * PTDisplayProperties;

typedef struct {   
    TVariableValue VoltageA;
    TVariableValue AmperageA;
    TVariableValue VoltageB;
    TVariableValue AmperageB;
} TDisplaySetPointValues, * PTDisplaySetPointValues;

typedef struct {   
    TMeasuredValue VoltageA;
    TMeasuredValue AmperageA;
    TMeasuredValue VoltageB;
    TMeasuredValue AmperageB;
} TDisplayMeasuredValues, * PTDisplayMeasuredValues;

typedef struct {   
    TVariableValue Radiator;
    TVariableValue Cpu;    
    BOOL Repaint;
} TDisplayTemperature, * PTDisplayTemperature;

typedef struct {   
    TSymbol VoltageStabA;
    TSymbol AmperageStabA;
    TSymbol VoltageStabB;
    TSymbol AmperageStabB;
} TDisplaySymbols, * PTDisplaySymbols;

typedef struct {   
    TSymbolIndicator MousePresent;
    BOOL MousePresentVisible;
    BOOL MousePresentRepaint;
} TDisplayStateSymbols, * PTDisplayStateSymbols;

typedef struct {
    TDisplayProperties Properties; 
    TDisplayRequests Requests;
    TDisplaySetPointValues SetPointValues;
    TDisplayMeasuredValues MeasuredValues;
    TDisplaySymbols Symbols;
    TDisplayTemperature Temperatures;
    TDisplayStateSymbols StateSymbols;
} TDisplayObject, * PTDisplayObject;

extern void RequestToChangeScreen(TDisplayScreen newValue);

extern void Display_RequestToChangeValue(TSelectValue selectValue, TElectrValue value);
extern void Display_RequestToChangeVoltageA(TElectrValue value);
extern void Display_RequestToChangeAmperageA(TElectrValue value);
extern void Display_RequestToChangeVoltageB(TElectrValue value);
extern void Display_RequestToChangeAmperageB(TElectrValue value);

extern void RequestToSelect(TSelectValue selectValue);
extern TSelectValue GetCurrentSelectedValue();
extern BOOL IsDisplayInSelectionMode();
extern void RequestToFocusing(TSelectValue selectValue);

extern void RequestToSelectStabilize(TSelectStabilizeMode selectValue);
extern TSelectStabilizeMode GetCurrentSelectedStabilize();
extern BOOL IsDisplayInChangingStabilizeMode();
extern void RequestToFocusingStabilize(TSelectStabilizeMode selectValue);

extern void RequestToChangeTemperatures(TTemperature temperatures);
extern void RequestToRepaintTemperatures();
extern BOOL RequestToVisibileMousePresent(BOOL visible);
extern void RequestToRepaintMousePresent();
extern BOOL RequestToShowError(PCHAR errorMessage);

#endif  /* __LCD_DISPLAY_H__ */
/* [] END OF FILE */
