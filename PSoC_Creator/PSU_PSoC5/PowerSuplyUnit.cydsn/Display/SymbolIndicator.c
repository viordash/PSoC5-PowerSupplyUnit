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
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "LCD_Display.h"
#include "Display\SymbolIndicator.h"

void SymbolIndicator_Init(PTSymbolIndicator pSymbolIndicator, TSymbolMode mode, INT font, BYTE left, BYTE top, BYTE width, BYTE height, 
        BOOL readonly) {
    pSymbolIndicator->Mode = mode;
    pSymbolIndicator->Font = font;
    pSymbolIndicator->Left = left;
    pSymbolIndicator->Top = top;
    pSymbolIndicator->Width = width;
    pSymbolIndicator->Height = height;
    pSymbolIndicator->Readonly = readonly;  
    pSymbolIndicator->Selected = FALSE;
    pSymbolIndicator->Focused = FALSE;    
}

void SymbolIndicator_SetSelected(PTSymbolIndicator pSymbolIndicator, BOOL value) {
    if (pSymbolIndicator->Readonly) {
        return;    
    }
    TLineType lineType = value ? ltDoted : ltInvisible;
    Display_DrawRectangle(pSymbolIndicator->Left - 1, pSymbolIndicator->Top - 1, pSymbolIndicator->Left + pSymbolIndicator->Width + 1, 
        pSymbolIndicator->Top + pSymbolIndicator->Height + 1, lineType, FALSE); 
    Display_DrawRectangle(pSymbolIndicator->Left - 2, pSymbolIndicator->Top - 2, pSymbolIndicator->Left + pSymbolIndicator->Width + 2, 
        pSymbolIndicator->Top + pSymbolIndicator->Height + 2, lineType, FALSE);
}

BOOL SymbolIndicator_GetSelected(PTSymbolIndicator pSymbolIndicator) {
    return pSymbolIndicator->Selected;
}

void SymbolIndicator_SetFocused(PTSymbolIndicator pSymbolIndicator, BOOL value) {
    if (pSymbolIndicator->Readonly) {
        return;    
    }    
    pSymbolIndicator->Focused = value;
    if (value) {
        SymbolIndicator_SetSelected(pSymbolIndicator, FALSE);    
    }    
    SymbolIndicator_Repaint(pSymbolIndicator);
}

BOOL SymbolIndicator_GetFocused(PTSymbolIndicator pSymbolIndicator) {
    return pSymbolIndicator->Focused;
}

void SymbolIndicator_Repaint(PTSymbolIndicator pSymbolIndicator) {
    TTextColor color = pSymbolIndicator->Focused ? tcNorm : tcInvisible;
    Display_SetFont(pSymbolIndicator->Font);
    if (pSymbolIndicator->Mode == simStabilizeVoltage) {
        Display_Print("S", color, pSymbolIndicator->Left, pSymbolIndicator->Top, FALSE);
    } else if (pSymbolIndicator->Mode == simStabilizeAmperage) {
        Display_Print("s", color, pSymbolIndicator->Left, pSymbolIndicator->Top, FALSE);
    } else if (pSymbolIndicator->Mode == simMousePresent) {
        Display_Print("d", color, pSymbolIndicator->Left, pSymbolIndicator->Top, FALSE);
    }  
}

/* [] END OF FILE */
