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
#include "Display\ValueIndicator.h"

void ValueIndicator_Init(PTValueIndicator pValueIndicator, TOutputMode mode, INT font, BYTE left, BYTE top, BYTE width, BYTE height, INT unitFont, 
        INT decimalPointFont, BYTE secondaryTop, BYTE unitLeftSift, BYTE decimalPointLeftSift, BOOL readonly) {
    pValueIndicator->Mode = mode;
    pValueIndicator->Font = font;
    pValueIndicator->Left = left;
    pValueIndicator->Top = top;
    pValueIndicator->Width = width;
    pValueIndicator->Height = height;
    pValueIndicator->UnitFont = unitFont;
    pValueIndicator->DecimalPointFont = decimalPointFont;
    pValueIndicator->SecondaryTop = secondaryTop;
    pValueIndicator->UnitLeftSift = unitLeftSift;
    pValueIndicator->DecimalPointLeftSift = decimalPointLeftSift;
    pValueIndicator->Readonly = readonly;  
    pValueIndicator->Selected = FALSE;
    pValueIndicator->Focused = FALSE;    
}

void ValueIndicator_SetSelected(PTValueIndicator pValueIndicator, BOOL value) {
    if (pValueIndicator->Readonly) {
        return;    
    }
    TLineType lineType = value ? ltDoted : ltInvisible;
    Display_DrawRectangle(pValueIndicator->Left - 1, pValueIndicator->Top - 1, pValueIndicator->Left + pValueIndicator->Width + 1, 
        pValueIndicator->Top + pValueIndicator->Height + 1, lineType, FALSE); 
    Display_DrawRectangle(pValueIndicator->Left - 2, pValueIndicator->Top - 2, pValueIndicator->Left + pValueIndicator->Width + 2, 
        pValueIndicator->Top + pValueIndicator->Height + 2, lineType, FALSE);
}

BOOL ValueIndicator_GetSelected(PTValueIndicator pValueIndicator) {
    return pValueIndicator->Selected;
}

void ValueIndicator_SetFocused(PTValueIndicator pValueIndicator, BOOL value) {
    if (pValueIndicator->Readonly) {
        return;    
    }    
    pValueIndicator->Focused = value;
    if (value) {
        ValueIndicator_SetSelected(pValueIndicator, FALSE);    
    }    
    TLineType lineType = value ? ltSolid : ltInvisible;
    Display_FillRectangle(pValueIndicator->Left - 1, pValueIndicator->Top - 1, pValueIndicator->Left + pValueIndicator->Width + 1, 
        pValueIndicator->Top + pValueIndicator->Height + 1, lineType, FALSE);
    ValueIndicator_Repaint(pValueIndicator);
}

BOOL ValueIndicator_GetFocused(PTValueIndicator pValueIndicator) {
    return pValueIndicator->Focused;
}

void ValueIndicator_SetValue(PTValueIndicator pValueIndicator, TElectrValue value) {
    if (pValueIndicator->Mode == omVoltage) {
        sprintf(pValueIndicator->TextMajor, "%02u", value / 100);
        sprintf(pValueIndicator->TextMinor, "%02u", value % 100);
    } else if (pValueIndicator->Mode == omAmperage) {
        sprintf(pValueIndicator->TextMajor, "%1u", value / 1000);
        sprintf(pValueIndicator->TextMinor, "%03u", value % 1000);
    }    
}

void ValueIndicator_Repaint(PTValueIndicator pValueIndicator) {
    TTextColor color = pValueIndicator->Focused ? tcInvert : tcNorm;
    Display_SetFont(pValueIndicator->Font);
    BYTE shiftX = Display_Print(pValueIndicator->TextMajor, color, pValueIndicator->Left, pValueIndicator->Top, FALSE); 
    Display_SetFont(pValueIndicator->DecimalPointFont);
    shiftX = Display_Print(".", color, shiftX + pValueIndicator->DecimalPointLeftSift, pValueIndicator->SecondaryTop, FALSE); 
    shiftX += pValueIndicator->DecimalPointLeftSift;
    Display_SetFont(pValueIndicator->Font);
    shiftX = Display_Print(pValueIndicator->TextMinor, color, shiftX, pValueIndicator->Top, FALSE);
    Display_SetFont(pValueIndicator->DecimalPointFont);
    if (pValueIndicator->Mode == omVoltage) {
        Display_Print("v", color, shiftX + pValueIndicator->UnitLeftSift, pValueIndicator->SecondaryTop, FALSE); 
    } else if (pValueIndicator->Mode == omAmperage) {
        Display_Print("a", color, shiftX + pValueIndicator->UnitLeftSift, pValueIndicator->SecondaryTop, FALSE); 
    }
}

/* [] END OF FILE */
