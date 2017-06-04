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
#include <stdio.h>
#include "LCD_Display.h"

TFunction DisplayFunction;
TDisplayObject DisplayObj;
BOOL ProcessRequests();
void ChangeScreen();
void UpdateChannelA();
void UpdateChannelB();
void ChangeSelected();
void ChangeStabilizeModeA();
void ChangeStabilizeModeB();

void Display_Init() {    
    DisplayObj.Requests.ScreenRequest = FALSE;    
    DisplayObj.Requests.Screen = dsInit;    
    DisplayObj.Requests.ChannelARequest = FALSE;    
    DisplayObj.Requests.ChannelA.Voltage = 0; 
    DisplayObj.Requests.ChannelA.Amperage = 0;
    DisplayObj.Requests.ChannelBRequest = FALSE;   
    DisplayObj.Requests.ChannelB.Voltage = 0; 
    DisplayObj.Requests.ChannelB.Amperage = 0;
    DisplayObj.Requests.SelectedRequest = FALSE;    
    DisplayObj.Requests.Selected = dslNone;    
    DisplayObj.Requests.StabilizeModeARequest = FALSE;    
    DisplayObj.Requests.StabilizeModeA = smVoltageStab;    
    DisplayObj.Requests.StabilizeModeBRequest = FALSE;    
    DisplayObj.Requests.StabilizeModeB = smVoltageStab; 
}

void Display_Task() {	
    _LCD_Init();
    _LCD_WaitReady();
    RequestToChangeScreen(dsStart);
    {
        TDisplayChannelData newValueA = {1210, 561};
        RequestToChannelA(newValueA);
        TDisplayChannelData newValueB = {0, 0};
        RequestToChannelB(newValueB);
        TDisplaySelected selected = dslVoltageB;
        RequestToSelected(selected);
        
        TStabilizeMode stabilizeModeA = smVoltageStab;
        RequestToStabilizeModeA(stabilizeModeA);
        TStabilizeMode stabilizeModeB = smAmperageStab;
        RequestToStabilizeModeB(stabilizeModeB);
    }
    INT yyy = 100;
	while (TRUE) {  
        ProcessRequests();
        if (yyy-- <= 50) {
            TStabilizeMode stabilizeModeB = smVoltageStab;
            RequestToStabilizeModeB(stabilizeModeB);            
        }
        if (yyy <= 0) {
            TStabilizeMode stabilizeModeA = smAmperageStab;
            RequestToStabilizeModeA(stabilizeModeA);           
        }
		TaskSleep(&DisplayFunction, SYSTICK_mS(100));		
	}
}

void RequestToChangeScreen(TDisplayScreen newValue) { 
    DisplayObj.Requests.Screen = newValue;
    DisplayObj.Requests.ScreenRequest = TRUE;
}

void RequestToChannelA(TDisplayChannelData newValue) { 
    DisplayObj.Requests.ChannelA = newValue;
    DisplayObj.Requests.ChannelARequest = TRUE;
}

void RequestToChannelB(TDisplayChannelData newValue) { 
    DisplayObj.Requests.ChannelB = newValue;
    DisplayObj.Requests.ChannelBRequest = TRUE;
}

void RequestToSelected(TDisplaySelected newValue) { 
    DisplayObj.Requests.Selected = newValue;
    DisplayObj.Requests.SelectedRequest = TRUE;
}

void RequestToStabilizeModeA(TStabilizeMode newValue) { 
    DisplayObj.Requests.StabilizeModeA = newValue;
    DisplayObj.Requests.StabilizeModeARequest = TRUE;
}

void RequestToStabilizeModeB(TStabilizeMode newValue) { 
    DisplayObj.Requests.StabilizeModeB = newValue;
    DisplayObj.Requests.StabilizeModeBRequest = TRUE;
}

BOOL ProcessRequests () {
BOOL res = FALSE;    
    if (DisplayObj.Requests.ScreenRequest) {
        ChangeScreen();
        DisplayObj.Requests.ScreenRequest = FALSE;
        res = TRUE;  
    } 
    if (DisplayObj.Requests.ChannelARequest) {
        UpdateChannelA();
        DisplayObj.Requests.ChannelARequest = FALSE;
        res = TRUE;  
    }
    if (DisplayObj.Requests.ChannelBRequest) {
        UpdateChannelB();
        DisplayObj.Requests.ChannelBRequest = FALSE;
        res = TRUE;  
    }
    if (DisplayObj.Requests.SelectedRequest) {
        ChangeSelected();
        DisplayObj.Requests.SelectedRequest = FALSE;
        res = TRUE;  
    } 
    if (DisplayObj.Requests.StabilizeModeARequest) {
        ChangeStabilizeModeA();
        DisplayObj.Requests.StabilizeModeARequest = FALSE;
        res = TRUE;  
    } 
    if (DisplayObj.Requests.StabilizeModeBRequest) {
        ChangeStabilizeModeB();
        DisplayObj.Requests.StabilizeModeBRequest = FALSE;
        res = TRUE;  
    } 
    return res;
}

void SetScreen_Bipolar();
void SetScreen_Start() {   
    SetScreen_Bipolar();
}

void SetScreen_Bipolar() {    
    Display_DrawLine(119, 0, 119, 110, ltSolid, FALSE);
    Display_DrawLine(120, 0, 120, 110, ltSolid, FALSE);
    Display_DrawLine(0, 55, 239, 55, ltSolid, FALSE);
    Display_DrawLine(0, 110, 239, 110, ltSolid, FALSE);

    Display_SetFont(3);
    Display_Print("  .  ", -1, tcNorm, 30, 0, FALSE);        
    Display_SetFont(2);
    Display_Print("v", -1, tcNorm, 100, 4, FALSE); 
    
    Display_DrawLine(12, 28, 119, 28, ltDoted, FALSE);  
    Display_DrawLine(12, 28, 12, 54, ltDoted, FALSE); 
    Display_DrawLine(119, 28, 119, 54, ltDoted, FALSE);   
    Display_DrawLine(12, 32, 40, 38, ltSolid, FALSE);  
    Display_DrawLine(40, 38, 80, 30, ltSolid, FALSE);
    
    Display_SetFont(3);
    Display_Print("  .  ", -1, tcNorm, 30 + 120, 0, FALSE);        
    Display_SetFont(2);
    Display_Print("v", -1, tcNorm, 100 + 120, 4, FALSE);  
          
    Display_DrawLine(12 + 120, 28, 119 + 120, 28, ltDoted, FALSE);  
    Display_DrawLine(12 + 120, 28, 12 + 120, 54, ltDoted, FALSE); 
    Display_DrawLine(119 + 120, 28, 119 + 120, 54, ltDoted, FALSE); 
    Display_DrawLine(12 + 120, 36, 40 + 120, 42, ltSolid, FALSE);  
    Display_DrawLine(40 + 120, 42, 80 + 120, 38, ltSolid, FALSE);

    Display_SetFont(2);
    Display_Print(" .   ", -1, tcNorm, 30, 4 + 56, FALSE);        
    Display_SetFont(2);
    Display_Print("a", -1, tcNorm, 104, 4 + 56, FALSE);  
    
    Display_DrawLine(12, 28 + 56, 119, 28 + 56, ltDoted, FALSE);  
    Display_DrawLine(12, 28 + 56, 12, 54 + 56, ltDoted, FALSE); 
    Display_DrawLine(119, 28 + 56, 119, 54 + 56, ltDoted, FALSE);  
    Display_DrawLine(12, 36 + 56, 40, 44 + 56, ltSolid, FALSE);  
    Display_DrawLine(40, 44 + 56, 80, 42 + 56, ltSolid, FALSE);

    Display_SetFont(2);
    Display_Print(" .   ", -1, tcNorm, 30 + 120, 4 + 56, FALSE);        
    Display_SetFont(2);
    Display_Print("a", -1, tcNorm, 104 + 120, 4 + 56, FALSE);  
    
    Display_DrawLine(12 + 120, 28 + 56, 119 + 120, 28 + 56, ltDoted, FALSE);  
    Display_DrawLine(12 + 120, 28 + 56, 12 + 120, 54 + 56, ltDoted, FALSE); 
    Display_DrawLine(119 + 120, 28 + 56, 119 + 120, 54 + 56, ltDoted, FALSE); 
    Display_DrawLine(12 + 120, 30 + 56, 40 + 120, 32 + 56, ltSolid, FALSE);  
    Display_DrawLine(40 + 120, 32 + 56, 80 + 120, 37 + 56, ltSolid, FALSE);
    
    Display_Flush();
}

void SetScreen_Unipolar() {    

}

void SetScreen_Error() {    

}

void ChangeScreen() {  
    DisplayObj.Properties.Screen = DisplayObj.Requests.Screen;          
    if (DisplayObj.Properties.Screen == dsStart) {
        SetScreen_Start();
    } else if (DisplayObj.Properties.Screen == dsBipolar) {
        SetScreen_Bipolar();
    } else if (DisplayObj.Properties.Screen == dsUnipolar) {
        SetScreen_Unipolar();
    } else if (DisplayObj.Properties.Screen == dsError) {
        SetScreen_Error();
    }
}

void UpdateChannelVoltage(WORD voltage, TTextColor color, BYTE coordX, BYTE coordY) {
CHAR buffer[10];
    WORD valueMajor = voltage / 100;
    WORD valueMinor = voltage % 100;
    sprintf(buffer, "%2u.%02u ", valueMajor, valueMinor);
    Display_SetFont(3);
    Display_Print(buffer, -1, color, coordX, coordY, FALSE);
}

void UpdateChannelAmperage(WORD amperage, TTextColor color, BYTE coordX, BYTE coordY) {
CHAR buffer[10];
    WORD valueMajor = amperage / 1000;
    WORD valueMinor = amperage % 1000;
    sprintf(buffer, "%1u.%03u ", valueMajor, valueMinor);
    Display_SetFont(2);
    Display_Print(buffer, -1, color, coordX, coordY, FALSE);
}

#define VoltageACoordX 30
#define VoltageACoordY 0
#define AmperageACoordX 30
#define AmperageACoordY 4 + 56

#define VoltageBCoordX 30 + 120
#define VoltageBCoordY 0
#define AmperageBCoordX 30 + 120
#define AmperageBCoordY 4 + 56

void UpdateChannelA() {         
    DisplayObj.Properties.ChannelA = DisplayObj.Requests.ChannelA; 
    UpdateChannelVoltage(DisplayObj.Properties.ChannelA.Voltage, DisplayObj.Properties.Selected == dslVoltageA ? tcInvert : tcNorm, 
            VoltageACoordX, VoltageACoordY);
    UpdateChannelAmperage(DisplayObj.Properties.ChannelA.Amperage, DisplayObj.Properties.Selected == dslAmperageA ? tcInvert : tcNorm, 
            AmperageACoordX, AmperageACoordY);
    Display_Flush();
}

void UpdateChannelB() {   
    DisplayObj.Properties.ChannelB = DisplayObj.Requests.ChannelB;   
    UpdateChannelVoltage(DisplayObj.Properties.ChannelB.Voltage, DisplayObj.Properties.Selected == dslVoltageB ? tcInvert : tcNorm, 
            VoltageBCoordX, VoltageBCoordY);
    UpdateChannelAmperage(DisplayObj.Properties.ChannelB.Amperage, DisplayObj.Properties.Selected == dslAmperageB ? tcInvert : tcNorm, 
            AmperageBCoordX, AmperageBCoordY);
    Display_Flush();
}

void UpdateSelect(BOOL selected) {    
    if (DisplayObj.Properties.Selected == dslVoltageA) {
        UpdateChannelVoltage(DisplayObj.Properties.ChannelA.Voltage, selected ? tcInvert : tcNorm, VoltageACoordX, VoltageACoordY);;
    } else if (DisplayObj.Properties.Selected == dslAmperageA) {
        UpdateChannelAmperage(DisplayObj.Properties.ChannelA.Amperage, selected ? tcInvert : tcNorm, AmperageACoordX, AmperageACoordY);
    } else if (DisplayObj.Properties.Selected == dslVoltageB) {
        UpdateChannelVoltage(DisplayObj.Properties.ChannelB.Voltage, selected ? tcInvert : tcNorm, VoltageBCoordX, VoltageBCoordY);;
    } else if (DisplayObj.Properties.Selected == dslAmperageB) {
        UpdateChannelAmperage(DisplayObj.Properties.ChannelB.Amperage, selected ? tcInvert : tcNorm, AmperageBCoordX, AmperageBCoordY);
    }
}

void ChangeSelected() {  
    UpdateSelect(FALSE);
    DisplayObj.Properties.Selected = DisplayObj.Requests.Selected;      
    UpdateSelect(TRUE);
    Display_Flush();
}

void ChangeStabilizeMode(BOOL show, TStabilizeMode stabilizeMode, 
        BYTE voltCoordX, BYTE voltCoordY, BYTE amperCoordX, BYTE amperCoordY) {   
    if (stabilizeMode == smVoltageStab) {
        Display_SetFont(3);
        Display_Print("#", -1, show ? tcNorm : tcInvisible, voltCoordX, voltCoordY, FALSE);
    } else if (stabilizeMode == smAmperageStab) {
        Display_SetFont(2);
        Display_Print("#", -1, show ? tcNorm : tcInvisible, amperCoordX, amperCoordY, FALSE);
    }    
}

void ChangeStabilizeModeA() {   
    ChangeStabilizeMode(FALSE, DisplayObj.Properties.StabilizeModeA, 
            VoltageACoordX - 25, VoltageACoordY, AmperageACoordX - 27, AmperageACoordY);   
    DisplayObj.Properties.StabilizeModeA = DisplayObj.Requests.StabilizeModeA; 
    ChangeStabilizeMode(TRUE, DisplayObj.Properties.StabilizeModeA, 
            VoltageACoordX - 25, VoltageACoordY, AmperageACoordX - 27, AmperageACoordY); 
    Display_Flush();
}

void ChangeStabilizeModeB() {  
    ChangeStabilizeMode(FALSE, DisplayObj.Properties.StabilizeModeB, 
            VoltageBCoordX - 25, VoltageBCoordY, AmperageBCoordX - 27, AmperageBCoordY);   
    DisplayObj.Properties.StabilizeModeB = DisplayObj.Requests.StabilizeModeB; 
    ChangeStabilizeMode(TRUE, DisplayObj.Properties.StabilizeModeB, 
            VoltageBCoordX - 25, VoltageBCoordY, AmperageBCoordX - 27, AmperageBCoordY); 
    Display_Flush();
}