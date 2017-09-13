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

#ifndef __Chart_H
#define __Chart_H
  
#include <device.h>
    
#define POINTS_COUNT 128    
typedef struct {
    BYTE WorkAreaWidth;
    BYTE WorkAreaHeight;
    BYTE WorkAreaBottom;
    BYTE WorkAreaTop;
    BYTE WorkAreaLeft;
    BYTE WorkAreaRight;
    BYTE SetPointLeft;
    BYTE SetPointRight;    
    TElectrValue CoordYMax;
    TElectrValue CoordYMin;
    BYTE Points[POINTS_COUNT];
} TChartPrivate, *PTChartPrivate;
    
typedef struct {
    BYTE Left;
    BYTE Top;
    BYTE Width;
    BYTE Height;
    BYTE SetPointPos;
    INT AdcMax;
    INT SetPointMax;
    BOOL AutoScale;
    TChartPrivate _private;
} TChart, *PTChart;
  
extern void Chart_Init(PTChart pChart, BYTE left, BYTE top, BYTE width, BYTE height, INT adcMax, INT valueMax);
extern void Chart_DrawBorder(PTChart pChart);
extern void Chart_SetValue(PTChart pChart, TElectrValue value);
extern void Chart_SetPoint(PTChart pChart, TElectrValue value);
extern void Chart_AutoScale(PTChart pChart, BOOL enable);
#endif /* __Chart_H */

/* [] END OF FILE */
