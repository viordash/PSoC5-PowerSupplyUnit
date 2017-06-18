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

#ifndef __SymbolIndicator_H
#define __SymbolIndicator_H
  
#include <device.h>

typedef enum {
	simStabilizeVoltage,
	simStabilizeAmperage,
} TSymbolMode;
    
typedef struct {
    TSymbolMode Mode;
	INT Font;
    BYTE Left;
    BYTE Top;
    BYTE Width;
    BYTE Height;
    BOOL Selected;
    BOOL Focused;
    BOOL Readonly;
} TSymbolIndicator, *PTSymbolIndicator;
  
extern void SymbolIndicator_Init(PTSymbolIndicator pSymbolIndicator, TSymbolMode mode, INT font, BYTE left, BYTE top, BYTE width, BYTE height, 
        BOOL readonly);
extern void SymbolIndicator_SetSelected(PTSymbolIndicator pSymbolIndicator, BOOL value);
extern BOOL SymbolIndicator_GetSelected(PTSymbolIndicator pSymbolIndicator);
extern void SymbolIndicator_SetFocused(PTSymbolIndicator pSymbolIndicator, BOOL value);
extern BOOL SymbolIndicator_GetFocused(PTSymbolIndicator pSymbolIndicator);
extern void SymbolIndicator_Repaint(PTSymbolIndicator pSymbolIndicator);

#endif /* __SymbolIndicator_H */

/* [] END OF FILE */
