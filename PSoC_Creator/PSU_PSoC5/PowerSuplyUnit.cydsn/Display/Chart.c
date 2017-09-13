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

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "LCD_Display.h"
#include "Display\Chart.h"

void Chart_Init(PTChart pChart, BYTE left, BYTE top, BYTE width, BYTE height, INT adcMax, INT setPointMax) {
    memset(pChart, 0, sizeof(TChart));
    pChart->Left = left;
    pChart->Top = top;
    pChart->Width = width;
    pChart->Height = height;
    pChart->SetPointPos = height;  
    pChart->AdcMax = adcMax;  
    pChart->SetPointMax = setPointMax;  
    pChart->AutoScale = FALSE;  
    pChart->_private.WorkAreaHeight = height - 2;  
    pChart->_private.WorkAreaTop = top + 1; 
    pChart->_private.WorkAreaBottom = pChart->_private.WorkAreaTop + pChart->_private.WorkAreaHeight; 
    pChart->_private.WorkAreaWidth = width - 2;   
    pChart->_private.WorkAreaLeft = left + 1;  
    pChart->_private.WorkAreaRight = pChart->_private.WorkAreaLeft + pChart->_private.WorkAreaWidth;  
    
    pChart->_private.SetPointLeft = pChart->_private.WorkAreaRight - 10;  
    pChart->_private.SetPointRight = pChart->_private.WorkAreaRight; 
    
    memset(pChart->_private.Points, pChart->_private.WorkAreaBottom, POINTS_COUNT);
}

void Chart_DrawBorder(PTChart pChart) {
    Display_DrawRectangle(pChart->Left, pChart->Top, pChart->Left + pChart->Width, pChart->Top + pChart->Height, ltDoted, FALSE); 
}

void CleanWorkSpace(PTChart pChart) {    
    Display_FillRectangle(pChart->_private.WorkAreaLeft, pChart->_private.WorkAreaTop, pChart->_private.WorkAreaRight, pChart->_private.WorkAreaBottom, 
            ltInvisible, FALSE);
}

void ShiftWorkSpace(PTChart pChart) {     
    PBYTE pBuffer = pChart->_private.Points;
    PBYTE pBufferEnd = (pBuffer + pChart->_private.WorkAreaWidth) - 1;
   // if (pChart->AutoScale) {
        pChart->_private.CoordYMax = pChart->SetPointPos + 5;
        pChart->_private.CoordYMin = HI_BYTE;    
   // }
    while (pBuffer <= pBufferEnd) { 
        BYTE val = *pBufferEnd;        
        *(pBufferEnd + 1) = val;
        pBufferEnd--;
      //  if (pChart->AutoScale) {
            if (pChart->_private.CoordYMax < val) {
                pChart->_private.CoordYMax = val + 5;
            }
            if (pChart->_private.CoordYMin > val) {
                if (val > 5) {
                    pChart->_private.CoordYMin = val - 5;
                } else {
                    pChart->_private.CoordYMin = 0;
                }
            }  
      //  }
    }
}

void DrawWorkSpace(PTChart pChart) { 
    if (!pChart->AutoScale) {
        Display_DrawLine(pChart->_private.SetPointLeft, pChart->SetPointPos, pChart->_private.SetPointRight, pChart->SetPointPos, ltDoted, FALSE);
        BYTE coordX = pChart->_private.WorkAreaRight;
        PBYTE pBuffer = pChart->_private.Points;
        PBYTE pBufferEnd = pBuffer + pChart->_private.WorkAreaWidth;
        while (pBuffer < pBufferEnd) {        
            BYTE coordY = *(pBuffer++);
            Display_DrawPixel(coordX, coordY, TRUE);
            coordX--;
        }
    } else {
        Display_DrawLine(pChart->_private.SetPointLeft, pChart->SetPointPos, pChart->_private.SetPointRight, pChart->SetPointPos, ltDoted, FALSE);
        BYTE coordX = pChart->_private.WorkAreaRight;
        PBYTE pBuffer = pChart->_private.Points;
        PBYTE pBufferEnd = pBuffer + pChart->_private.WorkAreaWidth;
        while (pBuffer < pBufferEnd) {        
            BYTE coordY = *(pBuffer++);
            Display_DrawPixel(coordX, coordY, TRUE);
            coordX--;
        }        
    }
}

void Chart_SetValue(PTChart pChart, TElectrValue value) {        
    DWORD dw = (pChart->AdcMax * 1000) / value;
    dw = (pChart->_private.WorkAreaHeight * 1000) / dw;
    BYTE coordY = pChart->_private.WorkAreaBottom - (BYTE)dw; 
    ShiftWorkSpace(pChart);
    if (coordY < pChart->_private.WorkAreaTop) {
        coordY = pChart->_private.WorkAreaTop;
    }
    pChart->_private.Points[0] = coordY;
    CleanWorkSpace(pChart);
    DrawWorkSpace(pChart);  
}


void Chart_SetPoint(PTChart pChart, TElectrValue value) {
    DWORD dw = (pChart->SetPointMax * 1000) / value;
    dw = (pChart->_private.WorkAreaHeight * 1000) / dw;
    BYTE coordY = pChart->_private.WorkAreaBottom - (BYTE)dw;  
    if (coordY < pChart->_private.WorkAreaTop) {
        coordY = pChart->_private.WorkAreaTop;
    }    
    pChart->SetPointPos = coordY;    
    Chart_AutoScale(pChart, pChart->AutoScale);
}

void Chart_AutoScale(PTChart pChart, BOOL enable) {
    pChart->AutoScale = enable;    
}
/* [] END OF FILE */
