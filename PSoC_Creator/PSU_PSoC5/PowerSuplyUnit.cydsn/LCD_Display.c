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

#define VoltageACoordX 25
#define VoltageACoordY 3
#define AmperageACoordX 30
#define AmperageACoordY 4 + 56

#define StabilizeModeVoltageACoordX (VoltageACoordX - 20)
#define StabilizeModeVoltageACoordY (VoltageACoordY + 3)
#define StabilizeModeAmperageACoordX (AmperageACoordX - 25)
#define StabilizeModeAmperageACoordY (AmperageACoordY)

#define VoltageBCoordX 25 + 120
#define VoltageBCoordY 3
#define AmperageBCoordX 30 + 120
#define AmperageBCoordY 4 + 56

#define StabilizeModeVoltageBCoordX (VoltageBCoordX - 20)
#define StabilizeModeVoltageBCoordY (VoltageBCoordY + 3)
#define StabilizeModeAmperageBCoordX (AmperageBCoordX - 25)
#define StabilizeModeAmperageBCoordY (AmperageBCoordY)

#define SetPointVoltageACoordX 2
#define SetPointVoltageACoordY 35
#define SetPointAmperageACoordX 2
#define SetPointAmperageACoordY 35 + 56

#define SetPointVoltageBCoordX 2 + 120
#define SetPointVoltageBCoordY 35
#define SetPointAmperageBCoordX 2 + 120
#define SetPointAmperageBCoordY 35 + 56

TFunction DisplayFunction;
TDisplayObject DisplayObj;
BOOL ProcessRequests();
void ChangeScreen();
void ChangeSelected();
void ChangeFocused();
BOOL FlashSelected();
void ChangingStabilizeMode();
void ConfirmStabilizeMode();
BOOL FlashChangingStabilizeMode();
void ChangeMeasuredVoltageA();
void ChangeMeasuredAmperageA();
void ChangeMeasuredVoltageB();
void ChangeMeasuredAmperageB();

BOOL ChangeValues();
BOOL ChangeSelection();

void Display_Init() {    
    memset(&DisplayObj.Properties, 0, sizeof(TDisplayProperties));
    memset(&DisplayObj.Requests, 0, sizeof(TDisplayRequests));
    memset(&DisplayObj.Values, 0, sizeof(TDisplayValues));
    
    ValueIndicator_Init(&DisplayObj.Values.MeasuredVoltageA.Indicator, omVoltage, 3, VoltageACoordX, VoltageACoordY, 
        88, 22, 4, 4, VoltageACoordY + 3);
    ValueIndicator_Init(&DisplayObj.Values.MeasuredAmperageA.Indicator, omAmperage, 2, AmperageACoordX, AmperageACoordY, 
        81, 19, 4, 4, VoltageACoordY);
    
    ValueIndicator_Init(&DisplayObj.Values.MeasuredVoltageB.Indicator, omVoltage, 3, VoltageBCoordX, VoltageBCoordY, 
        88, 22, 4, 4, VoltageBCoordY + 3);
    ValueIndicator_Init(&DisplayObj.Values.MeasuredAmperageB.Indicator, omAmperage, 2, AmperageBCoordX, AmperageBCoordY, 
        81, 19, 4, 4, VoltageBCoordY);    
        
    ValueIndicator_Init(&DisplayObj.Values.SetPointVoltageA.Indicator, omVoltage, 0, SetPointVoltageACoordX, SetPointVoltageACoordY, 
        15, 10, 0, 0, SetPointVoltageACoordY);
    ValueIndicator_Init(&DisplayObj.Values.SetPointAmperageA.Indicator, omAmperage, 0, SetPointAmperageACoordX, SetPointAmperageACoordY, 
        15, 10, 0, 0, SetPointAmperageACoordY);        

    ValueIndicator_Init(&DisplayObj.Values.SetPointVoltageB.Indicator, omVoltage, 0, SetPointVoltageBCoordX, SetPointVoltageBCoordY, 
        15, 10, 0, 0, SetPointVoltageBCoordY);
    ValueIndicator_Init(&DisplayObj.Values.SetPointAmperageB.Indicator, omAmperage, 0, SetPointAmperageBCoordX, SetPointAmperageBCoordY, 
        15, 10, 0, 0, SetPointAmperageBCoordY);    
}

void Display_Task() {	
    _LCD_Init();
    _LCD_WaitReady();
    RequestToChangeScreen(dsStart);
	while (TRUE) {  
        if (!ProcessRequests()) {
            if (!FlashSelected()) {
                FlashChangingStabilizeMode();    
            }
        }
        
		TaskSleep(&DisplayFunction, SYSTICK_mS(100));		
	}
}

void RequestToChangeScreen(TDisplayScreen newValue) { 
    DisplayObj.Requests.Screen = newValue;
    DisplayObj.Requests.ScreenRequest = TRUE;
}

void RequestToChangingStabilizeMode(TStabilizeChangingMode newValue) { 
    DisplayObj.Requests.ChangingStabilizeMode = newValue;
    DisplayObj.Requests.ChangingStabilizeModeRequest = TRUE;
}

void RequestToConfirmStabilizeMode() {     
    DisplayObj.Requests.ConfirmStabilizeModeRequest = TRUE;
}

void RequestToNextStabilizeMode() { 
    if (DisplayObj.Properties.Screen == dsBipolar) {
        if (DisplayObj.Properties.ChangingStabilizeMode == scmVoltageAStab) {
            RequestToChangingStabilizeMode(scmAmperageAStab);
        } else if (DisplayObj.Properties.ChangingStabilizeMode == scmAmperageAStab) {
            RequestToChangingStabilizeMode(scmVoltageBStab);
        } else if (DisplayObj.Properties.ChangingStabilizeMode == scmVoltageBStab) {
            RequestToChangingStabilizeMode(scmAmperageBStab);
        } else  {
            RequestToChangingStabilizeMode(scmVoltageAStab);
        }
    } else if (DisplayObj.Properties.Screen == dsUnipolar) {
        if (DisplayObj.Properties.ChangingStabilizeMode == scmVoltageAStab) {
            RequestToChangingStabilizeMode(scmAmperageAStab);
        } else  {
            RequestToChangingStabilizeMode(scmVoltageAStab);
        }
    }
}

void RequestToPrevStabilizeMode() { 
    if (DisplayObj.Properties.Screen == dsBipolar) {
        if (DisplayObj.Properties.ChangingStabilizeMode == scmVoltageAStab) {
            RequestToChangingStabilizeMode(scmAmperageBStab);
        } else if (DisplayObj.Properties.ChangingStabilizeMode == scmAmperageBStab) {
            RequestToChangingStabilizeMode(scmVoltageBStab);
        } else if (DisplayObj.Properties.ChangingStabilizeMode == scmVoltageBStab) {
            RequestToChangingStabilizeMode(scmAmperageAStab);
        } else  {
            RequestToChangingStabilizeMode(scmVoltageAStab);
        }
    } else if (DisplayObj.Properties.Screen == dsUnipolar) {
        if (DisplayObj.Properties.ChangingStabilizeMode == scmVoltageAStab) {
            RequestToChangingStabilizeMode(scmAmperageAStab);
        } else  {
            RequestToChangingStabilizeMode(scmVoltageAStab);
        }
    }
}

void RequestToSetChangingStabilizeMode() {
    RequestToChangingStabilizeMode(DisplayObj.Requests.ChangingStabilizeMode);    
}

BOOL ProcessRequests () {
BOOL res = FALSE;    
    if (DisplayObj.Requests.ScreenRequest) {
        ChangeScreen();
        DisplayObj.Requests.ScreenRequest = FALSE;
        res = TRUE;  
    } 
//    if (DisplayObj.Requests.SelectedRequest) {
//        ChangeSelected();
//        DisplayObj.Requests.SelectedRequest = FALSE;
//        res = TRUE;  
//    }     
//    if (DisplayObj.Requests.FocusedRequest) {
//        ChangeFocused();
//        DisplayObj.Requests.FocusedRequest = FALSE;
//        res = TRUE;  
//    }     
    if (DisplayObj.Requests.ChangingStabilizeModeRequest) {
        ChangingStabilizeMode();
        DisplayObj.Requests.ChangingStabilizeModeRequest = FALSE;
        res = TRUE;  
    }     
    if (DisplayObj.Requests.ConfirmStabilizeModeRequest) {
        ConfirmStabilizeMode();
        DisplayObj.Requests.ConfirmStabilizeModeRequest = FALSE;
        res = TRUE;  
    }  
    if (ChangeValues()) {
        res = TRUE;  
    } 
    if (ChangeSelection()) {
        res = TRUE;  
    }

    return res;
}

void SetScreen_Start() {   
CHAR buffer[20];    
    Display_DrawRectangle(3, 3, 237, 125, ltSolid, FALSE); 
    Display_DrawRectangle(4, 4, 236, 124, ltSolid, FALSE); 
    Display_DrawRectangle(6, 6, 234, 122, ltDoted, FALSE); 
    Display_DrawRectangle(7, 7, 234, 121, ltDoted, FALSE); 
    
    Display_SetFont(1);
    Display_Print("Power Supply", tcNorm, 75, 35 + 10, FALSE);  
    Display_Print("PSoC-5. Viordash", tcNorm, 60, 55 + 10, FALSE);   
    Display_SetFont(0);   
    ProgramVersion(buffer);
    Display_Print(buffer, tcNorm, 87, 110, FALSE);      
    Display_Flush();
}

void SetScreen_Bipolar() {    
    Display_DrawLine(119, 0, 119, 110, ltSolid, FALSE);
    Display_DrawLine(120, 0, 120, 110, ltSolid, FALSE);
    Display_DrawLine(0, 55, 239, 55, ltSolid, FALSE);
    Display_DrawLine(0, 110, 239, 110, ltSolid, FALSE);

//    Display_SetFont(3);
//    Display_Print("  .  ", -1, tcNorm, 30, 0, FALSE);        
//    Display_SetFont(2);
//    Display_Print("v", -1, tcNorm, 100 + 4, 5, FALSE);   
    
    Display_DrawLine(35, 28, 119, 28, ltDoted, FALSE);  
    Display_DrawLine(35, 28, 35, 54, ltDoted, FALSE); 
    Display_DrawLine(119, 28, 119, 54, ltDoted, FALSE);   
    Display_DrawLine(12 + 23, 32, 40 + 23, 38, ltSolid, FALSE);  
    Display_DrawLine(40 + 23, 38, 80 + 23, 30, ltSolid, FALSE);    
    Display_SetFont(0); 
    Display_Print("44.44v ", tcNorm, 4, 37, FALSE); 
    
//    Display_SetFont(3);
//    Display_Print("  .  ", -1, tcNorm, 30 + 120, 0, FALSE);        
//    Display_SetFont(2);
//    Display_Print("v", -1, tcNorm, 100 + 120 + 4, 5, FALSE);  
          
    Display_DrawLine(35 + 120, 28, 119 + 120, 28, ltDoted, FALSE);  
    Display_DrawLine(35 + 120, 28, 35 + 120, 54, ltDoted, FALSE); 
    Display_DrawLine(119 + 120, 28, 119 + 120, 54, ltDoted, FALSE); 
    Display_DrawLine(12 + 23 + 120, 36, 40 + 23 + 120, 42, ltSolid, FALSE);  
    Display_DrawLine(40 + 23 + 120, 42, 80 + 23 + 120, 38, ltSolid, FALSE);
    Display_SetFont(0); 
    Display_Print("11.11v ", tcNorm, 4 + 120, 37, FALSE); 

//    Display_SetFont(2);
//    Display_Print(" .   ", -1, tcNorm, 30, 4 + 56, FALSE);        
//    Display_SetFont(2);
//    Display_Print("a", -1, tcNorm, 104, 4 + 56, FALSE);  
    
    Display_DrawLine(35, 28 + 56, 119, 28 + 56, ltDoted, FALSE);  
    Display_DrawLine(35, 28 + 56, 35, 54 + 56, ltDoted, FALSE); 
    Display_DrawLine(119, 28 + 56, 119, 54 + 56, ltDoted, FALSE);  
    Display_DrawLine(12 + 23, 36 + 56, 40 + 23, 44 + 56, ltSolid, FALSE);  
    Display_DrawLine(40 + 23, 44 + 56, 80 + 23, 42 + 56, ltSolid, FALSE);
    Display_SetFont(0); 
    Display_Print("3.250a ", tcNorm, 4, 37 + 56, FALSE); 

//    Display_SetFont(2);
//    Display_Print(" .   ", -1, tcNorm, 30 + 120, 4 + 56, FALSE);        
//    Display_SetFont(2);
//    Display_Print("a", -1, tcNorm, 104 + 120, 4 + 56, FALSE);  
    
    Display_DrawLine(35 + 120, 28 + 56, 119 + 120, 28 + 56, ltDoted, FALSE);  
    Display_DrawLine(35 + 120, 28 + 56, 35 + 120, 54 + 56, ltDoted, FALSE); 
    Display_DrawLine(119 + 120, 28 + 56, 119 + 120, 54 + 56, ltDoted, FALSE); 
    Display_DrawLine(12 + 23 + 120, 30 + 56, 40 + 23 + 120, 32 + 56, ltSolid, FALSE);  
    Display_DrawLine(40 + 23 + 120, 32 + 56, 80 + 23 + 120, 37 + 56, ltSolid, FALSE);
    Display_SetFont(0); 
    Display_Print("0.754a ", tcNorm, 4 + 120, 37 + 56, FALSE);
    
    Display_Flush();
}

void SetScreen_Unipolar() {  
    Display_DrawLine(119, 0, 119, 110, ltSolid, FALSE);
    Display_DrawLine(120, 0, 120, 110, ltSolid, FALSE);
    Display_DrawLine(0, 55, 239, 55, ltSolid, FALSE);
    Display_DrawLine(0, 110, 239, 110, ltSolid, FALSE);

//    Display_SetFont(3);
//    Display_Print("  .  ", -1, tcNorm, 30, 0, FALSE);        
//    Display_SetFont(2);
//    Display_Print("v", -1, tcNorm, 100, 4, FALSE);   
    
    Display_DrawLine(35, 28, 119, 28, ltDoted, FALSE);  
    Display_DrawLine(35, 28, 35, 54, ltDoted, FALSE); 
    Display_DrawLine(119, 28, 119, 54, ltDoted, FALSE);   
    Display_DrawLine(12 + 23, 32, 40 + 23, 38, ltSolid, FALSE);  
    Display_DrawLine(40 + 23, 38, 80 + 23, 30, ltSolid, FALSE);    
    Display_SetFont(0); 
    Display_Print("11.11v ", tcNorm, 4, 37, FALSE); 

//    Display_SetFont(2);
//    Display_Print(" .   ", -1, tcNorm, 30, 4 + 56, FALSE);        
//    Display_SetFont(2);
//    Display_Print("a", -1, tcNorm, 104, 4 + 56, FALSE);  
    
    Display_DrawLine(35, 28 + 56, 119, 28 + 56, ltDoted, FALSE);  
    Display_DrawLine(35, 28 + 56, 35, 54 + 56, ltDoted, FALSE); 
    Display_DrawLine(119, 28 + 56, 119, 54 + 56, ltDoted, FALSE);  
    Display_DrawLine(12 + 23, 36 + 56, 40 + 23, 44 + 56, ltSolid, FALSE);  
    Display_DrawLine(40 + 23, 44 + 56, 80 + 23, 42 + 56, ltSolid, FALSE);
    Display_SetFont(0); 
    Display_Print("7.000a ", tcNorm, 4, 37 + 56, FALSE); 
    
    Display_Flush();  
}

void SetScreen_Error() {    

}

void ChangeScreen() {  
    DisplayObj.Properties.Screen = DisplayObj.Requests.Screen;    
    Display_ClearScreen();
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


//void UpdateFocused(BOOL focused) {   
//    if (DisplayObj.Properties.Focused == dslVoltageA) {
//        UpdateChannelVoltage(DisplayObj.Properties.MeasuredVoltageA, focused ? tcInvert : tcNorm, VoltageACoordX, VoltageACoordY);
//    } else if (DisplayObj.Properties.Focused == dslAmperageA) {
//        UpdateChannelAmperage(DisplayObj.Properties.MeasuredAmperageA, focused ? tcInvert : tcNorm, AmperageACoordX, AmperageACoordY);
//    } else if (DisplayObj.Properties.Focused == dslVoltageB) {
//        UpdateChannelVoltage(DisplayObj.Properties.MeasuredVoltageB, focused ? tcInvert : tcNorm, VoltageBCoordX, VoltageBCoordY);
//    } else if (DisplayObj.Properties.Focused == dslAmperageB) {
//        UpdateChannelAmperage(DisplayObj.Properties.MeasuredAmperageB, focused ? tcInvert : tcNorm, AmperageBCoordX, AmperageBCoordY);
//    }    
//}

//void ChangeFocused() {  
//    UpdateFocused(FALSE);
//    DisplayObj.Properties.Focused = DisplayObj.Requests.Focused;      
//    UpdateFocused(TRUE);
//    UpdateSelect(FALSE);
//    DisplayObj.Properties.Selected = dslNone;   
//    Display_Flush();
//}


/*>>>-------------- StabilizeMode -----------------*/

void ChangeStabilizeMode(BOOL show, TStabilizeMode stabilizeMode, 
        BYTE voltCoordX, BYTE voltCoordY, BYTE amperCoordX, BYTE amperCoordY) {   
    Display_SetFont(4);
    if (stabilizeMode == smVoltageStab) {
        Display_Print("S", show ? tcNorm : tcInvisible, voltCoordX, voltCoordY, FALSE);
    } else if (stabilizeMode == smAmperageStab) {
        Display_Print("s", show ? tcNorm : tcInvisible, amperCoordX, amperCoordY, FALSE);
    }    
}
        
void ChangeStabilizeModeA(TStabilizeMode newValue) {   
    ChangeStabilizeMode(FALSE, DisplayObj.Properties.StabilizeModeA, 
            StabilizeModeVoltageACoordX, StabilizeModeVoltageACoordY, StabilizeModeAmperageACoordX, StabilizeModeAmperageACoordY);   
    DisplayObj.Properties.StabilizeModeA = newValue; 
    ChangeStabilizeMode(TRUE, DisplayObj.Properties.StabilizeModeA, 
            StabilizeModeVoltageACoordX, StabilizeModeVoltageACoordY, StabilizeModeAmperageACoordX, StabilizeModeAmperageACoordY); 
    Display_Flush();
}

void ChangeStabilizeModeB(TStabilizeMode newValue) {  
    ChangeStabilizeMode(FALSE, DisplayObj.Properties.StabilizeModeB, 
            StabilizeModeVoltageBCoordX, StabilizeModeVoltageBCoordY, StabilizeModeAmperageBCoordX, StabilizeModeAmperageBCoordY);   
    DisplayObj.Properties.StabilizeModeB = newValue; 
    ChangeStabilizeMode(TRUE, DisplayObj.Properties.StabilizeModeB, 
            StabilizeModeVoltageBCoordX, StabilizeModeVoltageBCoordY, StabilizeModeAmperageBCoordX, StabilizeModeAmperageBCoordY); 
    Display_Flush();
}

void UpdateSelectedStabilizeMode(BOOL selected) {    
    if (DisplayObj.Properties.ChangingStabilizeMode == scmVoltageAStab) {
        Display_DrawRectangle(StabilizeModeVoltageACoordX - 1, StabilizeModeVoltageACoordY - 1, 
            StabilizeModeVoltageACoordX + 16, StabilizeModeVoltageACoordY + 20, selected ? ltDoted : ltInvisible, FALSE); 
        Display_DrawRectangle(StabilizeModeVoltageACoordX - 2, StabilizeModeVoltageACoordY - 2, 
            StabilizeModeVoltageACoordX + 17, StabilizeModeVoltageACoordY + 21, selected ? ltDoted : ltInvisible, FALSE); 
    } else if (DisplayObj.Properties.ChangingStabilizeMode == scmAmperageAStab) {        
        Display_DrawRectangle(StabilizeModeAmperageACoordX - 1, StabilizeModeAmperageACoordY - 1, 
            StabilizeModeAmperageACoordX + 13, StabilizeModeAmperageACoordY + 20, selected ? ltDoted : ltInvisible, FALSE); 
        Display_DrawRectangle(StabilizeModeAmperageACoordX - 2, StabilizeModeAmperageACoordY - 2, 
            StabilizeModeAmperageACoordX + 14, StabilizeModeAmperageACoordY + 21, selected ? ltDoted : ltInvisible, FALSE);         
    } else if (DisplayObj.Properties.ChangingStabilizeMode == scmVoltageBStab) {
        Display_DrawRectangle(StabilizeModeVoltageBCoordX - 1, StabilizeModeVoltageBCoordY - 1, 
            StabilizeModeVoltageBCoordX + 16, StabilizeModeVoltageBCoordY + 20, selected ? ltDoted : ltInvisible, FALSE); 
        Display_DrawRectangle(StabilizeModeVoltageBCoordX - 2, StabilizeModeVoltageBCoordY - 2, 
            StabilizeModeVoltageBCoordX + 17, StabilizeModeVoltageBCoordY + 21, selected ? ltDoted : ltInvisible, FALSE); 
    } else if (DisplayObj.Properties.ChangingStabilizeMode == scmAmperageBStab) {        
        Display_DrawRectangle(StabilizeModeAmperageBCoordX - 1, StabilizeModeAmperageBCoordY - 1, 
            StabilizeModeAmperageBCoordX + 13, StabilizeModeAmperageBCoordY + 20, selected ? ltDoted : ltInvisible, FALSE); 
        Display_DrawRectangle(StabilizeModeAmperageBCoordX - 2, StabilizeModeAmperageBCoordY - 2, 
            StabilizeModeAmperageBCoordX + 14, StabilizeModeAmperageBCoordY + 21, selected ? ltDoted : ltInvisible, FALSE); 
    } 
}

void ChangingStabilizeMode() {  
    UpdateSelectedStabilizeMode(FALSE);
    DisplayObj.Properties.ChangingStabilizeMode = DisplayObj.Requests.ChangingStabilizeMode; 
    UpdateSelectedStabilizeMode(TRUE);
    Display_Flush();
    DisplayObj.Properties.ChangingStabilizeModeTimeout = GetTickCount();
    DisplayObj.Properties.ChangingStabilizeModeFlashingTick = 0;
}

void ConfirmStabilizeMode() { 
    if (DisplayObj.Properties.ChangingStabilizeMode == scmVoltageAStab) {
        ChangeStabilizeModeA(smVoltageStab);
    } else if (DisplayObj.Properties.ChangingStabilizeMode == scmAmperageAStab) {
        ChangeStabilizeModeA(smAmperageStab);
    } else if (DisplayObj.Properties.ChangingStabilizeMode == scmVoltageBStab) {
        ChangeStabilizeModeB(smVoltageStab);
    } else if (DisplayObj.Properties.ChangingStabilizeMode == scmAmperageBStab) {
        ChangeStabilizeModeB(smAmperageStab);
    }
    UpdateSelectedStabilizeMode(FALSE);
    Display_Flush();
    DisplayObj.Properties.ChangingStabilizeMode = scmNone; 
}

BOOL FlashChangingStabilizeMode() {  
static BOOL state = FALSE;    
    if (DisplayObj.Properties.ChangingStabilizeMode == scmNone) {
        return FALSE;    
    } else if (GetElapsedPeriod(DisplayObj.Properties.ChangingStabilizeModeTimeout) >= SYSTICK_mS(5000)) {    
        UpdateSelectedStabilizeMode(FALSE);
        Display_Flush();
        DisplayObj.Properties.ChangingStabilizeMode = scmNone; 
        return FALSE;
    } else if (GetElapsedPeriod(DisplayObj.Properties.ChangingStabilizeModeFlashingTick) < SYSTICK_mS(500)) {
        return FALSE;
    } else {    
        DisplayObj.Properties.ChangingStabilizeModeFlashingTick = GetTickCount();   
        UpdateSelectedStabilizeMode(state);
        Display_Flush();
        state = !state;  
        return TRUE;
    }
}

BOOL IsDisplayInChangingStabilizeMode() {    
    return DisplayObj.Properties.ChangingStabilizeMode != scmNone;
}
/*----------------- StabilizeMode --------------<<<*/


/*>>>-------------- Change ElectrValue -----------------*/

BOOL ChangeValues() {
    INT size = sizeof(DisplayObj.Values) / sizeof(TVariableValue);
    PTVariableValue pVariableValue = (PTVariableValue)&DisplayObj.Values;
    BOOL request = FALSE;
    while(size-- > 0){
        if (!pVariableValue->RequestToChangeValue) {
            request = TRUE;
            break;    
        }  
        pVariableValue++;
    }
    if (!request) {
        return FALSE;    
    }    
    ValueIndicator_SetValue(&(pVariableValue->Indicator), pVariableValue->NewValue);
    pVariableValue->RequestToChangeValue = FALSE;
    ValueIndicator_Repaint(&(pVariableValue->Indicator));
    Display_Flush();    
    return TRUE;  
}

void RequestToChangeMeasuredVoltageA(TElectrValue value) {
    DisplayObj.Values.MeasuredVoltageA.NewValue = value;
    DisplayObj.Values.MeasuredVoltageA.RequestToChangeValue = TRUE;  
}
void RequestToChangeMeasuredAmperageA(TElectrValue value) {
    DisplayObj.Values.MeasuredAmperageA.NewValue = value;
    DisplayObj.Values.MeasuredAmperageA.RequestToChangeValue = TRUE;  
}
void RequestToChangeMeasuredVoltageB(TElectrValue value) {
    DisplayObj.Values.MeasuredVoltageB.NewValue = value;
    DisplayObj.Values.MeasuredVoltageB.RequestToChangeValue = TRUE;  
}
void RequestToChangeMeasuredAmperageB(TElectrValue value) {
    DisplayObj.Values.MeasuredAmperageB.NewValue = value;
    DisplayObj.Values.MeasuredAmperageB.RequestToChangeValue = TRUE;  
}

void RequestToChangeSetPointVoltageA(TElectrValue value) {
    DisplayObj.Values.SetPointVoltageA.NewValue = value;
    DisplayObj.Values.SetPointVoltageA.RequestToChangeValue = TRUE;  
}
void RequestToChangeSetPointAmperageA(TElectrValue value) {
    DisplayObj.Values.SetPointAmperageA.NewValue = value;
    DisplayObj.Values.SetPointAmperageA.RequestToChangeValue = TRUE;  
}
void RequestToChangeSetPointVoltageB(TElectrValue value) {
    DisplayObj.Values.SetPointVoltageB.NewValue = value;
    DisplayObj.Values.SetPointVoltageB.RequestToChangeValue = TRUE;  
}
void RequestToChangeSetPointAmperageB(TElectrValue value) {
    DisplayObj.Values.SetPointAmperageB.NewValue = value;
    DisplayObj.Values.SetPointAmperageB.RequestToChangeValue = TRUE;  
}
/*----------------- Change ElectrValue --------------<<<*/


/*>>>-------------- Selecting -----------------*/
BOOL ChangeSelection() {
    INT size = sizeof(DisplayObj.Values) / sizeof(TVariableValue);
    PTVariableValue pVariableValue = (PTVariableValue)&DisplayObj.Values;
    BOOL request = FALSE;
    while(size-- > 0){
        if (!pVariableValue->RequestToSelect) {
            request = TRUE;
            break;    
        }  
        pVariableValue++;
    }
    if (!request) {
        return FALSE;    
    }  
    
    size = sizeof(DisplayObj.Values) / sizeof(TVariableValue);
    PTVariableValue pDeselectVariableValue = (PTVariableValue)&DisplayObj.Values;
    while(size-- > 0){
        if (pVariableValue != pDeselectVariableValue && ValueIndicator_GetSelected(&(pDeselectVariableValue->Indicator))) {
            ValueIndicator_SetSelected(&(pDeselectVariableValue->Indicator), FALSE);   
        }  
        pDeselectVariableValue++;
    }    
    ValueIndicator_SetSelected(&(pVariableValue->Indicator), TRUE);
    pVariableValue->RequestToSelect = FALSE;
    Display_Flush();    
    return TRUE;  
}

void RequestToNextSelect() { 
    if (DisplayObj.Properties.Screen == dsBipolar) {
        if (ValueIndicator_GetSelected(&DisplayObj.Values.MeasuredVoltageA.Indicator)) {
            DisplayObj.Values.MeasuredAmperageA.RequestToChangeValue = TRUE; 
        } else if (ValueIndicator_GetSelected(&DisplayObj.Values.MeasuredAmperageA.Indicator)) {
            DisplayObj.Values.MeasuredVoltageB.RequestToChangeValue = TRUE; 
        } else if (ValueIndicator_GetSelected(&DisplayObj.Values.MeasuredVoltageB.Indicator)) {
            DisplayObj.Values.MeasuredAmperageB.RequestToChangeValue = TRUE; 
        } else  {
            DisplayObj.Values.MeasuredVoltageA.RequestToChangeValue = TRUE; 
        }
    } else if (DisplayObj.Properties.Screen == dsUnipolar) {
        if (ValueIndicator_GetSelected(&DisplayObj.Values.MeasuredVoltageA.Indicator)) {
            DisplayObj.Values.MeasuredAmperageA.RequestToChangeValue = TRUE; 
        } else  {
            DisplayObj.Values.MeasuredVoltageA.RequestToChangeValue = TRUE;
        }
    }
}

void RequestToPrevSelect() { 
    if (DisplayObj.Properties.Screen == dsBipolar) {
        if (ValueIndicator_GetSelected(&DisplayObj.Values.MeasuredVoltageA.Indicator)) {
            DisplayObj.Values.MeasuredAmperageB.RequestToChangeValue = TRUE; 
        } else if (ValueIndicator_GetSelected(&DisplayObj.Values.MeasuredAmperageB.Indicator)) {
            DisplayObj.Values.MeasuredVoltageB.RequestToChangeValue = TRUE; 
        } else if (ValueIndicator_GetSelected(&DisplayObj.Values.MeasuredVoltageB.Indicator)) {
            DisplayObj.Values.MeasuredAmperageA.RequestToChangeValue = TRUE; 
        } else  {
            DisplayObj.Values.MeasuredVoltageA.RequestToChangeValue = TRUE; 
        }
    } else if (DisplayObj.Properties.Screen == dsUnipolar) {
        if (ValueIndicator_GetSelected(&DisplayObj.Values.MeasuredVoltageA.Indicator)) {
            DisplayObj.Values.MeasuredAmperageA.RequestToChangeValue = TRUE; 
        } else  {
            DisplayObj.Values.MeasuredVoltageA.RequestToChangeValue = TRUE;
        }
    }
}

void RequestToSetSelection() { 
    if (DisplayObj.Properties.Screen == dsBipolar) {        
        if (DisplayObj.Properties.StabilizeModeA == smVoltageStab) {  
            if (DisplayObj.Properties.StabilizeModeB == smVoltageStab) {
               if (ValueIndicator_GetFocused(&DisplayObj.Values.MeasuredVoltageA.Indicator)) {
                    DisplayObj.Values.MeasuredVoltageB.RequestToChangeValue = TRUE;
                } else {
                    DisplayObj.Values.MeasuredVoltageA.RequestToChangeValue = TRUE;
                } 
            } else if (DisplayObj.Properties.StabilizeModeB == smAmperageStab) {
               if (ValueIndicator_GetFocused(&DisplayObj.Values.MeasuredVoltageA.Indicator)) {
                    DisplayObj.Values.MeasuredAmperageB.RequestToChangeValue = TRUE;
                } else {
                    DisplayObj.Values.MeasuredVoltageA.RequestToChangeValue = TRUE;
                } 
            }
        } else if (DisplayObj.Properties.StabilizeModeA == smAmperageStab) {  
            if (DisplayObj.Properties.StabilizeModeB == smVoltageStab) {
               if (ValueIndicator_GetFocused(&DisplayObj.Values.MeasuredAmperageA.Indicator)) {
                    DisplayObj.Values.MeasuredVoltageB.RequestToChangeValue = TRUE;
                } else {
                    DisplayObj.Values.MeasuredAmperageA.RequestToChangeValue = TRUE;
                } 
            } else if (DisplayObj.Properties.StabilizeModeB == smAmperageStab) {
               if (ValueIndicator_GetFocused(&DisplayObj.Values.MeasuredAmperageA.Indicator)) {
                    DisplayObj.Values.MeasuredAmperageB.RequestToChangeValue = TRUE;
                } else {
                    DisplayObj.Values.MeasuredAmperageA.RequestToChangeValue = TRUE;
                } 
            }
        }
    } else if (DisplayObj.Properties.Screen == dsUnipolar) {
        if (ValueIndicator_GetFocused(&DisplayObj.Values.MeasuredVoltageA.Indicator)) {
            DisplayObj.Values.MeasuredAmperageA.RequestToChangeValue = TRUE;
        } else {
            DisplayObj.Values.MeasuredVoltageA.RequestToChangeValue = TRUE;
        }
    }
} 

void RequestToConfirmSelection() { 
    INT size = sizeof(DisplayObj.Values) / sizeof(TVariableValue);
    PTVariableValue pVariableValue = (PTVariableValue)&DisplayObj.Values;
    BOOL request = FALSE;
    while(size-- > 0){
        if (ValueIndicator_GetSelected(&(pVariableValue->Indicator))) {
            ValueIndicator_SetFocused(&(pVariableValue->Indicator), TRUE);  
        } else if (ValueIndicator_GetFocused(&(pVariableValue->Indicator))) {
            ValueIndicator_SetFocused(&(pVariableValue->Indicator), FALSE);  
        } 
        pVariableValue++;
    }
}

//void UpdateSelect(BOOL selected) {    
//    if (DisplayObj.Properties.Selected == dslVoltageA) {
//        Display_DrawRectangle(VoltageACoordX - 1, VoltageACoordY - 1, VoltageACoordX + 89, VoltageACoordY + 23, 
//            selected ? ltDoted : ltInvisible, FALSE); 
//        Display_DrawRectangle(VoltageACoordX - 2, VoltageACoordY - 2, VoltageACoordX + 90, VoltageACoordY + 24, 
//            selected ? ltDoted : ltInvisible, FALSE); 
//    } else if (DisplayObj.Properties.Selected == dslAmperageA) {        
//        Display_DrawRectangle(AmperageACoordX - 1, AmperageACoordY - 1, AmperageACoordX + 82, AmperageACoordY + 20, 
//            selected ? ltDoted : ltInvisible, FALSE); 
//        Display_DrawRectangle(AmperageACoordX - 2, AmperageACoordY - 2, AmperageACoordX + 83, AmperageACoordY + 21, 
//            selected ? ltDoted : ltInvisible, FALSE);
//    } else if (DisplayObj.Properties.Selected == dslVoltageB) {
//        Display_DrawRectangle(VoltageBCoordX - 1, VoltageBCoordY - 1, VoltageBCoordX + 89, VoltageBCoordY + 23, 
//            selected ? ltDoted : ltInvisible, FALSE); 
//        Display_DrawRectangle(VoltageBCoordX - 2, VoltageBCoordY - 2, VoltageBCoordX + 90, VoltageBCoordY + 24, 
//            selected ? ltDoted : ltInvisible, FALSE); 
//    } else if (DisplayObj.Properties.Selected == dslAmperageB) {    
//        Display_DrawRectangle(AmperageBCoordX - 1, AmperageBCoordY - 1, AmperageBCoordX + 82, AmperageBCoordY + 20, 
//            selected ? ltDoted : ltInvisible, FALSE); 
//        Display_DrawRectangle(AmperageBCoordX - 2, AmperageBCoordY - 2, AmperageBCoordX + 83, AmperageBCoordY + 21, 
//            selected ? ltDoted : ltInvisible, FALSE);
//    }
//}
//
//void ChangeSelected() {  
//    UpdateSelect(FALSE);
//    DisplayObj.Properties.Selected = DisplayObj.Requests.Selected;      
//    UpdateSelect(TRUE);
//    Display_Flush();
//    DisplayObj.Properties.SelectedTimeout = GetTickCount();
//    DisplayObj.Properties.SelectedFlashingTick = 0;
//}

BOOL FlashSelected() {  
static BOOL state = FALSE;    
    if (DisplayObj.Properties.Selected == dslNone) {
        return FALSE;    
    } else if (GetElapsedPeriod(DisplayObj.Properties.SelectedTimeout) >= SYSTICK_mS(5000)) {    
        UpdateSelect(FALSE);
        Display_Flush();
        DisplayObj.Properties.Selected = dslNone; 
        return FALSE;
    } else if (GetElapsedPeriod(DisplayObj.Properties.SelectedFlashingTick) < SYSTICK_mS(500)) {
        return FALSE;
    } else {    
        DisplayObj.Properties.SelectedFlashingTick = GetTickCount();   
        UpdateSelect(state);
        Display_Flush();
        state = !state;  
        return TRUE;
    }
}

BOOL IsDisplayInSelectionMode() {    
    return DisplayObj.Properties.Selected != dslNone;
}
/*----------------- Selecting --------------<<<*/

