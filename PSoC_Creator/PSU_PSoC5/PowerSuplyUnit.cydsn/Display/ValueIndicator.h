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

#ifndef __ValueIndicator_H
#define __ValueIndicator_H
  
#include <device.h>

typedef enum {
	omVoltageSetPoint,
	omVoltageMeasure,
	omAmperageSetPoint,
	omAmperageMeasure,
	omTemperature,
	omTemperatureCpu
} TOutputMode;
    
typedef struct {
    TOutputMode Mode;
	INT Font;
    BYTE Left;
    BYTE Top;
    BYTE Width;
    BYTE Height;
    BOOL Selected;
    BOOL Focused;
    BOOL Readonly;
	INT UnitFont;
	INT DecimalPointFont;    
    BYTE SecondaryTop; 
    BYTE UnitLeftSift;
    BYTE DecimalPointLeftSift;
    CHAR TextMajor[5];
    CHAR TextMinor[5];
    TCalcDisplayValueFunction CalcDisplayValueFunction;
} TValueIndicator, *PTValueIndicator;
  
extern void ValueIndicator_Init(PTValueIndicator pValueIndicator, TOutputMode mode, INT font, BYTE left, BYTE top, BYTE width, BYTE height, INT unitFont, 
        INT decimalPointFont, BYTE secondaryTop, BYTE unitLeftSift, BYTE decimalPointLeftSift, BOOL readonly, TCalcDisplayValueFunction calcDisplayValueFunction);
extern void ValueIndicator_SetSelected(PTValueIndicator pValueIndicator, BOOL value);
extern BOOL ValueIndicator_GetSelected(PTValueIndicator pValueIndicator);
extern void ValueIndicator_SetFocused(PTValueIndicator pValueIndicator, BOOL value);
extern BOOL ValueIndicator_GetFocused(PTValueIndicator pValueIndicator);
extern void ValueIndicator_SetValue(PTValueIndicator pValueIndicator, TElectrValue value);
extern void ValueIndicator_Repaint(PTValueIndicator pValueIndicator);


#endif /* __ValueIndicator_H */

/* [] END OF FILE */
