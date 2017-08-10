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
#include "MainWork.h"
#include "Regulator\CalcAdcValue.h"

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
#define SetPointVoltageACoordY 33
#define OverVoltageACoordX (SetPointVoltageACoordX - 1)
#define OverVoltageACoordY (SetPointVoltageACoordY + 10)
#define OverVoltageAWidth 31
#define OverVoltageAHeight 10

#define SetPointAmperageACoordX 2
#define SetPointAmperageACoordY 33 + 54
#define OverAmperageACoordX (SetPointAmperageACoordX - 1)
#define OverAmperageACoordY (SetPointAmperageACoordY + 10)
#define OverAmperageAWidth 31
#define OverAmperageAHeight 10

#define SetPointVoltageBCoordX 2 + 120
#define SetPointVoltageBCoordY 33
#define OverVoltageBCoordX (SetPointVoltageBCoordX - 1)
#define OverVoltageBCoordY (SetPointVoltageBCoordY + 10)
#define OverVoltageBWidth 31
#define OverVoltageBHeight 10

#define SetPointAmperageBCoordX 2 + 120
#define SetPointAmperageBCoordY 33 + 54
#define OverAmperageBCoordX (SetPointAmperageBCoordX - 1)
#define OverAmperageBCoordY (SetPointAmperageBCoordY + 10)
#define OverAmperageBWidth 31
#define OverAmperageBHeight 10

#define TemperatureCoordX 195
#define TemperatureCoordY 112
#define TemperatureCpuCoordX 195
#define TemperatureCpuCoordY 121

#define MousePresentCoordX 175
#define MousePresentCoordY 112

#define MessageCoordX 1
#define MessageCoordY 112

#define WorkstateCoordX 1
#define WorkstateCoordY 120

TFunction DisplayFunction;
TDisplayObject DisplayObj;
static BOOL ProcessRequests();
void ChangeScreen();
void ChangeSelected();
void ChangeFocused();
BOOL FlashSelected();
PTValueIndicator GetCurrentFocused();

BOOL ChangeMeasuredValues();
BOOL ChangeSetPointValues();
BOOL ChangeSelection();
BOOL ChangeFocusing();
PTVariableValue GetVariableValue(TSelectValue selectValue);

BOOL ChangeStabilizeSelection();
BOOL FlashSelectedStabilize();
BOOL ChangeFocusingStabilize();

BOOL ChangeTemperatures();
BOOL ChangeMousePresentVisibility();
BOOL ShowMessage();
BOOL ClearMessage();
BOOL ShowErrorOver();
BOOL FlashErrorOver();

void Display_Init() {    
    memset(&DisplayObj.Properties, 0, sizeof(TDisplayProperties));
    memset(&DisplayObj.Requests, 0, sizeof(TDisplayRequests));
    memset(&DisplayObj.SetPointValues, 0, sizeof(TDisplaySetPointValues));
    memset(&DisplayObj.MeasuredValues, 0, sizeof(TDisplayMeasuredValues));
    
    ValueIndicator_Init(&DisplayObj.MeasuredValues.VoltageA.Value.Indicator, omVoltageMeasure, 3, VoltageACoordX, VoltageACoordY, 
        89, 22, 4, 4, VoltageACoordY + 3, 3, 1, FALSE, CalcDisplayValueVoltageA);
    ValueIndicator_Init(&DisplayObj.MeasuredValues.AmperageA.Value.Indicator, omAmperageMeasure, 2, AmperageACoordX, AmperageACoordY, 
        81, 19, 4, 4, AmperageACoordY, 3, 1, FALSE, CalcDisplayValueAmperageA);
    
    ValueIndicator_Init(&DisplayObj.MeasuredValues.VoltageB.Value.Indicator, omVoltageMeasure, 3, VoltageBCoordX, VoltageBCoordY, 
        89, 22, 4, 4, VoltageBCoordY + 3, 3, 1, FALSE, CalcDisplayValueVoltageB);
    ValueIndicator_Init(&DisplayObj.MeasuredValues.AmperageB.Value.Indicator, omAmperageMeasure, 2, AmperageBCoordX, AmperageBCoordY, 
        81, 19, 4, 4, AmperageBCoordY, 3, 1, FALSE, CalcDisplayValueAmperageB);    
        
    ValueIndicator_Init(&DisplayObj.SetPointValues.VoltageA.Indicator, omVoltageSetPoint, 5, SetPointVoltageACoordX, SetPointVoltageACoordY, 
        15, 10, 0, 0, SetPointVoltageACoordY + 2, 1, 1, TRUE, NULL);
    ValueIndicator_Init(&DisplayObj.SetPointValues.AmperageA.Indicator, omAmperageSetPoint, 5, SetPointAmperageACoordX, SetPointAmperageACoordY, 
        15, 10, 0, 0, SetPointAmperageACoordY + 2, 1, 1, TRUE, NULL);        

    ValueIndicator_Init(&DisplayObj.SetPointValues.VoltageB.Indicator, omVoltageSetPoint, 5, SetPointVoltageBCoordX, SetPointVoltageBCoordY, 
        15, 10, 0, 0, SetPointVoltageBCoordY + 2, 1, 1, TRUE, NULL);
    ValueIndicator_Init(&DisplayObj.SetPointValues.AmperageB.Indicator, omAmperageSetPoint, 5, SetPointAmperageBCoordX, SetPointAmperageBCoordY, 
        15, 10, 0, 0, SetPointAmperageBCoordY + 2, 1, 1, TRUE, NULL);   

    ValueIndicator_Init(&DisplayObj.Temperatures.Radiator.Indicator, omTemperature, 6, TemperatureCoordX, TemperatureCoordY, 
        43, 6, 0, 0, TemperatureCoordY, 1, 1, FALSE, NULL);
    ValueIndicator_Init(&DisplayObj.Temperatures.Cpu.Indicator, omTemperatureCpu, 6, TemperatureCpuCoordX, TemperatureCpuCoordY, 
        43, 6, 0, 0, TemperatureCpuCoordY, 1, 1, TRUE, NULL);   
    DisplayObj.Properties.SelectedIndicator = NULL;    
    
    
    SymbolIndicator_Init(&DisplayObj.Symbols.VoltageStabA.Indicator, simStabilizeVoltage, 4, StabilizeModeVoltageACoordX, StabilizeModeVoltageACoordY, 
        14, 19, FALSE);  
    SymbolIndicator_Init(&DisplayObj.Symbols.AmperageStabA.Indicator, simStabilizeAmperage, 4, StabilizeModeAmperageACoordX, StabilizeModeAmperageACoordY, 
        12, 19, FALSE);  
    SymbolIndicator_Init(&DisplayObj.Symbols.VoltageStabB.Indicator, simStabilizeVoltage, 4, StabilizeModeVoltageBCoordX, StabilizeModeVoltageBCoordY, 
        14, 19, FALSE);  
    SymbolIndicator_Init(&DisplayObj.Symbols.AmperageStabB.Indicator, simStabilizeAmperage, 4, StabilizeModeAmperageBCoordX, StabilizeModeAmperageBCoordY, 
        12, 19, FALSE); 
    DisplayObj.Properties.SelectedSymbol = NULL;
    
    SymbolIndicator_Init(&DisplayObj.StateSymbols.MousePresent, simMousePresent, 4, MousePresentCoordX, MousePresentCoordY, 
        14, 13, FALSE);   
}

void Display_Task() {	
    _LCD_Init();
    _LCD_WaitReady();
    RequestToChangeScreen(dsStart);
	while (TRUE) {  
        if (!ProcessRequests()) {
            if (!FlashSelected()) {
                if (!FlashSelectedStabilize()) {
                    if (!FlashErrorOver()) {  
                    }
                }
            }
        }        
		TaskSleep(&DisplayFunction, SYSTICK_mS(100));		
	}
}

PTVariableValue GetVariableValue(TSelectValue selectValue) {
    PTVariableValue pVariableValue;
    switch(selectValue) {
        case svMeasuredVoltageA : pVariableValue = &DisplayObj.MeasuredValues.VoltageA.Value; break;
        case svMeasuredAmperageA : pVariableValue = &DisplayObj.MeasuredValues.AmperageA.Value; break;
        case svMeasuredVoltageB : pVariableValue = &DisplayObj.MeasuredValues.VoltageB.Value; break;
        case svMeasuredAmperageB : pVariableValue = &DisplayObj.MeasuredValues.AmperageB.Value; break;
        case svSetPointVoltageA : pVariableValue = &DisplayObj.SetPointValues.VoltageA; break;
        case svSetPointAmperageA : pVariableValue = &DisplayObj.SetPointValues.AmperageA; break;
        case svSetPointVoltageB : pVariableValue = &DisplayObj.SetPointValues.VoltageB; break;
        case svSetPointAmperageB : pVariableValue = &DisplayObj.SetPointValues.AmperageB; break;
        default : pVariableValue = NULL; break;        
    }
    return pVariableValue;
}

INT GetSetPointValuesCount() {
    return ((INT)sizeof(DisplayObj.SetPointValues)) / ((INT)sizeof(TVariableValue));
}

INT GetMeasuredValuesCount() {
    return ((INT)sizeof(DisplayObj.MeasuredValues)) / ((INT)sizeof(TMeasuredValue));
}

PTSymbol GetStabilizeSymbol(TSelectStabilizeMode selectValue) {
    PTSymbol pSymbol;
    switch(selectValue) {
        case ssmVoltageA : pSymbol = &DisplayObj.Symbols.VoltageStabA; break;
        case ssmAmperageA : pSymbol = &DisplayObj.Symbols.AmperageStabA; break;
        case ssmVoltageB : pSymbol = &DisplayObj.Symbols.VoltageStabB; break;
        case ssmAmperageB : pSymbol = &DisplayObj.Symbols.AmperageStabB; break;
        default : pSymbol = NULL; break;        
    }
    return pSymbol;
}

INT GetSymbolsCount() {
    return ((INT)sizeof(DisplayObj.Symbols)) / ((INT)sizeof(TSymbol));
}

void RequestToChangeScreen(TDisplayScreen newValue) { 
    DisplayObj.Requests.Screen = newValue;
    DisplayObj.Requests.ScreenRequest = TRUE;
}

static BOOL ProcessRequests() {
BOOL res = FALSE;    
    if (DisplayObj.Requests.ScreenRequest) {
        ChangeScreen();
        DisplayObj.Requests.ScreenRequest = FALSE;
        res = TRUE;  
    }   

    if (MainWorkObj.State != mwsStart) {
        if (ChangeSetPointValues()) {
            res = TRUE;  
        } 
        if (ChangeMeasuredValues()) {
            res = TRUE;  
        }
        if (ChangeSelection()) {
            res = TRUE;  
        }
        if (ChangeFocusing()) {
            res = TRUE;  
        }
        if (ChangeStabilizeSelection()) {
            res = TRUE;  
        }
        if (ChangeFocusingStabilize()) {
            res = TRUE;  
        }
        if (ChangeTemperatures()) {
            res = TRUE;  
        }
        if (ChangeMousePresentVisibility()) {
            res = TRUE;  
        }
        if (ClearMessage() || ShowMessage()) {
            res = TRUE;  
        }
        if (ShowErrorOver()) {
            res = TRUE;  
        }
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

void SetScreen_WorkMode() {    
    Display_DrawLine(119, 0, 119, 109, ltSolid, FALSE);
    Display_DrawLine(120, 0, 120, 109, ltSolid, FALSE);
    Display_DrawLine(0, 55, 239, 55, ltSolid, FALSE);
    Display_DrawLine(0, 109, 239, 109, ltSolid, FALSE);   
    
    Display_DrawLine(35, 28, 119, 28, ltDoted, FALSE);  
    Display_DrawLine(35, 28, 35, 54, ltDoted, FALSE); 
    Display_DrawLine(119, 28, 119, 54, ltDoted, FALSE);   
    Display_DrawLine(12 + 23, 32, 40 + 23, 38, ltSolid, FALSE);  
    Display_DrawLine(40 + 23, 38, 80 + 23, 30, ltSolid, FALSE);    
          
    Display_DrawLine(35 + 120, 28, 119 + 120, 28, ltDoted, FALSE);  
    Display_DrawLine(35 + 120, 28, 35 + 120, 54, ltDoted, FALSE); 
    Display_DrawLine(119 + 120, 28, 119 + 120, 54, ltDoted, FALSE); 
    Display_DrawLine(12 + 23 + 120, 36, 40 + 23 + 120, 42, ltSolid, FALSE);  
    Display_DrawLine(40 + 23 + 120, 42, 80 + 23 + 120, 38, ltSolid, FALSE);
    
    Display_DrawLine(35, 28 + 54, 119, 28 + 54, ltDoted, FALSE);  
    Display_DrawLine(35, 28 + 54, 35, 54 + 54, ltDoted, FALSE); 
    Display_DrawLine(119, 28 + 54, 119, 54 + 54, ltDoted, FALSE);  
    Display_DrawLine(12 + 23, 36 + 54, 40 + 23, 44 + 54, ltSolid, FALSE);  
    Display_DrawLine(40 + 23, 44 + 54, 80 + 23, 42 + 54, ltSolid, FALSE);
    
    Display_DrawLine(35 + 120, 28 + 54, 119 + 120, 28 + 54, ltDoted, FALSE);  
    Display_DrawLine(35 + 120, 28 + 54, 35 + 120, 54 + 54, ltDoted, FALSE); 
    Display_DrawLine(119 + 120, 28 + 54, 119 + 120, 54 + 54, ltDoted, FALSE); 
    Display_DrawLine(12 + 23 + 120, 30 + 54, 40 + 23 + 120, 32 + 54, ltSolid, FALSE);  
    Display_DrawLine(40 + 23 + 120, 32 + 54, 80 + 23 + 120, 37 + 54, ltSolid, FALSE);    
    Display_DrawLine(TemperatureCoordX - 2, 109, TemperatureCoordX - 2, GLCD_H_SIZE - 1, ltSolid, FALSE);     
    Display_Flush();
}

void SetScreen_Error() {    

}

void ChangeScreen() {  
    DisplayObj.Properties.Screen = DisplayObj.Requests.Screen;    
    Display_ClearScreen();
    if (DisplayObj.Properties.Screen == dsStart) {
        SetScreen_Start();        
    } else if (DisplayObj.Properties.Screen == dsWork) {
        DisplayObj.MeasuredValues.VoltageB.Value.Indicator.Readonly = FALSE;
        DisplayObj.MeasuredValues.AmperageB.Value.Indicator.Readonly = FALSE;
        SetScreen_WorkMode();
    } else if (DisplayObj.Properties.Screen == dsError) {
        SetScreen_Error();
    }
}

/*>>>-------------- Change ElectrValue -----------------*/
BOOL ChangeSetPointValues() {
    INT size = GetSetPointValuesCount();
    PTVariableValue pVariableValue = (PTVariableValue)&DisplayObj.SetPointValues;
    BOOL request = FALSE;
    while(size-- > 0){
        if (pVariableValue->RequestToChangeValue) {
            ValueIndicator_SetValue(&(pVariableValue->Indicator), pVariableValue->NewValue);
            pVariableValue->RequestToChangeValue = FALSE;
            ValueIndicator_Repaint(&(pVariableValue->Indicator));
            request = TRUE;
        }  
        pVariableValue++;
    }
    if (request) {
        Display_Flush();    
        return TRUE;        
    }    
    return FALSE;      
}

BOOL ChangeMeasuredValues() {
    INT size = GetMeasuredValuesCount();
    PTMeasuredValue pVariableValue = (PTMeasuredValue)&DisplayObj.MeasuredValues;
    BOOL request = FALSE;
    while(size-- > 0){
        if (pVariableValue->Value.RequestToChangeValue) {
            ValueIndicator_SetValue(&(pVariableValue->Value.Indicator), pVariableValue->Value.NewValue);
            pVariableValue->Value.RequestToChangeValue = FALSE;
            ValueIndicator_Repaint(&(pVariableValue->Value.Indicator));
            request = TRUE;
        }  
        pVariableValue++;
    }
    if (request) {
        Display_Flush();    
        return TRUE;        
    }    
    return FALSE;      
}

void Display_RequestToChangeValue(TSelectValue selectValue, TElectrValue value) {
    PTVariableValue pVariableValue = GetVariableValue(selectValue);
    if (pVariableValue != NULL) {
        pVariableValue->NewValue = value;
        pVariableValue->RequestToChangeValue = TRUE;
    }
}

void RequestToChangeMeasured(PTMeasuredValue pMeasuredValue, TElectrValue value) {
    MedianFilter3_Push(&(pMeasuredValue->MedianFilter3), value);
    if (GetElapsedPeriod(pMeasuredValue->UpdateTickCount) >= SYSTICK_mS(500)) {         
        pMeasuredValue->Value.NewValue = MedianFilter3_Calc(&(pMeasuredValue->MedianFilter3));
        pMeasuredValue->Value.RequestToChangeValue = TRUE;
        pMeasuredValue->UpdateTickCount = GetTickCount();
    }
}


void Display_RequestToChangeVoltageA(TElectrValue value) {
    RequestToChangeMeasured(&DisplayObj.MeasuredValues.VoltageA, value);
}

void Display_RequestToChangeAmperageA(TElectrValue value) {
    RequestToChangeMeasured(&DisplayObj.MeasuredValues.AmperageA, value);
}

void Display_RequestToChangeVoltageB(TElectrValue value) {
    RequestToChangeMeasured(&DisplayObj.MeasuredValues.VoltageB, value);
}

void Display_RequestToChangeAmperageB(TElectrValue value) {
    RequestToChangeMeasured(&DisplayObj.MeasuredValues.AmperageB, value);
}
/*----------------- Change ElectrValue --------------<<<*/


/*>>>-------------- Selecting -----------------*/
BOOL ChangeSelection() {
    INT size = GetMeasuredValuesCount();
    PTMeasuredValue pVariableValue = (PTMeasuredValue)&DisplayObj.MeasuredValues;
    BOOL request = FALSE;
    while(size-- > 0){
        if (pVariableValue->Value.RequestToSelect) {
            request = TRUE;
            break;  
        }  
        pVariableValue++;
    }
    if (!request) {
        return FALSE;    
    }   
    
    size = GetMeasuredValuesCount();
    PTMeasuredValue pDeselectVariableValue = (PTMeasuredValue)&DisplayObj.MeasuredValues;
    while(size-- > 0){
        if (pVariableValue != pDeselectVariableValue && ValueIndicator_GetSelected(&(pDeselectVariableValue->Value.Indicator))) {
            ValueIndicator_SetSelected(&(pDeselectVariableValue->Value.Indicator), FALSE);   
        }  
        pDeselectVariableValue++;
    }    
    ValueIndicator_SetSelected(&(pVariableValue->Value.Indicator), TRUE);
    pVariableValue->Value.RequestToSelect = FALSE;
    DisplayObj.Properties.SelectedTimeout = GetTickCount();
    DisplayObj.Properties.SelectedFlashingTick = 0;
    DisplayObj.Properties.SelectedIndicator = &(pVariableValue->Value.Indicator);
    Display_Flush();    
    return TRUE;
}

void RequestToSelect(TSelectValue selectValue) {
    PTVariableValue pVariableValue = GetVariableValue(selectValue);
    if (pVariableValue != NULL) {
        pVariableValue->RequestToSelect = TRUE;
    }
}

void InternalSelect(BOOL state) {
    INT size = GetMeasuredValuesCount();
    PTMeasuredValue pVariableValue = (PTMeasuredValue)&DisplayObj.MeasuredValues;
    while(size-- > 0) {
        PTValueIndicator pValueIndicator = &(pVariableValue->Value.Indicator);
        if (pValueIndicator == DisplayObj.Properties.SelectedIndicator) {
            ValueIndicator_SetSelected(pValueIndicator, state);
        } else {
            ValueIndicator_SetSelected(pValueIndicator, FALSE);
        }
        pVariableValue++;
    }    
}

BOOL FlashSelected() {  
static BOOL state = FALSE;    
    if (DisplayObj.Properties.SelectedIndicator == NULL) {
        return FALSE;    
    } else if (GetElapsedPeriod(DisplayObj.Properties.SelectedTimeout) >= SYSTICK_mS(5000)) {   
        InternalSelect(FALSE);
        PTValueIndicator pCurrentFocused = GetCurrentFocused();
        if (pCurrentFocused != NULL) {
            ValueIndicator_SetFocused(pCurrentFocused, TRUE);
        }
        Display_Flush();
        DisplayObj.Properties.SelectedIndicator = NULL; 
        return FALSE;
    } else if (GetElapsedPeriod(DisplayObj.Properties.SelectedFlashingTick) < SYSTICK_mS(500)) {
        return FALSE;
    } else {    
        DisplayObj.Properties.SelectedFlashingTick = GetTickCount();   
        InternalSelect(state);
        Display_Flush();
        state = !state;  
        return TRUE;
    }
}

TSelectValue GetCurrentSelectedValue() {
    PTValueIndicator pValueIndicator = DisplayObj.Properties.SelectedIndicator;   
    if (pValueIndicator == &DisplayObj.MeasuredValues.VoltageA.Value.Indicator) {
        return svMeasuredVoltageA;
    } else if (pValueIndicator == &DisplayObj.MeasuredValues.AmperageA.Value.Indicator) {
        return svMeasuredAmperageA;
    } else if (pValueIndicator == &DisplayObj.MeasuredValues.VoltageB.Value.Indicator) {
        return svMeasuredVoltageB;
    } else if (pValueIndicator == &DisplayObj.MeasuredValues.AmperageB.Value.Indicator) {
        return svMeasuredAmperageB;
    } else if (pValueIndicator == &DisplayObj.SetPointValues.VoltageA.Indicator) {
        return svSetPointVoltageA;
    } else if (pValueIndicator == &DisplayObj.SetPointValues.AmperageA.Indicator) {
        return svSetPointAmperageA;
    } else if (pValueIndicator == &DisplayObj.SetPointValues.VoltageB.Indicator) {
        return svSetPointVoltageB;
    } else if (pValueIndicator == &DisplayObj.SetPointValues.AmperageB.Indicator) {
        return svSetPointAmperageB;
    } else {
        return svNone;    
    }
}

BOOL IsDisplayInSelectionMode() {    
    return DisplayObj.Properties.SelectedIndicator != NULL;
}
/*----------------- Selecting --------------<<<*/

/*>>>-------------- Focusing -----------------*/
BOOL ChangeFocusing() {
    INT size = GetMeasuredValuesCount();
    PTMeasuredValue pVariableValue = (PTMeasuredValue)&DisplayObj.MeasuredValues;
    BOOL request = FALSE;
    while(size-- > 0){
        if (pVariableValue->Value.RequestToFocus) {
            request = TRUE;
            break;    
        }  
        pVariableValue++;
    }
    if (!request) {
        return FALSE;    
    }  
    
    size = GetMeasuredValuesCount();
    PTMeasuredValue pDeselectVariableValue = (PTMeasuredValue)&DisplayObj.MeasuredValues;
    while(size-- > 0){
        if (pVariableValue != pDeselectVariableValue && ValueIndicator_GetFocused(&(pDeselectVariableValue->Value.Indicator))) {
            ValueIndicator_SetFocused(&(pDeselectVariableValue->Value.Indicator), FALSE);   
        }  
        pDeselectVariableValue++;
    }    
    ValueIndicator_SetFocused(&(pVariableValue->Value.Indicator), TRUE);
    DisplayObj.Properties.SelectedIndicator = NULL;
    pVariableValue->Value.RequestToFocus = FALSE;
    Display_Flush();    
    return TRUE;
}

void RequestToFocusing(TSelectValue selectValue) {
    PTVariableValue pVariableValue = GetVariableValue(selectValue);
    if (pVariableValue != NULL) {
        pVariableValue->RequestToFocus = TRUE;
    }
}

PTValueIndicator GetCurrentFocused() {
    INT size = GetMeasuredValuesCount();
    PTMeasuredValue pVariableValue = (PTMeasuredValue)&DisplayObj.MeasuredValues;
    while(size-- > 0) {
        PTValueIndicator pValueIndicator = &(pVariableValue->Value.Indicator);
        if (ValueIndicator_GetFocused(pValueIndicator)) {
            return pValueIndicator;
        }
        pVariableValue++;
    }   
    return NULL;
}
/*----------------- Focusing --------------<<<*/

/*>>>-------------- Stabilize Selecting -----------------*/
BOOL ChangeStabilizeSelection() {
    INT size = GetSymbolsCount();
    PTSymbol pSymbol = (PTSymbol)&DisplayObj.Symbols;
    BOOL request = FALSE;
    while(size-- > 0){
        if (pSymbol->RequestToSelect) {
            request = TRUE;
            break;  
        }  
        pSymbol++;
    }
    if (!request) {
        return FALSE;    
    }   
    
    size = GetMeasuredValuesCount();
    PTSymbol pDeselectSymbol = (PTSymbol)&DisplayObj.Symbols;
    while(size-- > 0){
        if (pSymbol != pDeselectSymbol && SymbolIndicator_GetSelected(&(pDeselectSymbol->Indicator))) {
            SymbolIndicator_SetSelected(&(pDeselectSymbol->Indicator), FALSE);   
        }  
        pDeselectSymbol++;
    }    
    SymbolIndicator_SetSelected(&(pSymbol->Indicator), TRUE);
    pSymbol->RequestToSelect = FALSE;
    DisplayObj.Properties.SelectedSymbolTimeout = GetTickCount();
    DisplayObj.Properties.SelectedSymbolFlashingTick = 0;
    DisplayObj.Properties.SelectedSymbol = &(pSymbol->Indicator);
    Display_Flush();    
    return TRUE;
}

void RequestToSelectStabilize(TSelectStabilizeMode selectValue) {
    PTSymbol pSymbol = GetStabilizeSymbol(selectValue);
    if (pSymbol != NULL) {
        pSymbol->RequestToSelect = TRUE;
    }
}

void InternalSelectStabilize(BOOL state) {
    INT size = GetSymbolsCount();
    PTSymbol pSymbol = (PTSymbol)&DisplayObj.Symbols;
    while(size-- > 0) {
        PTSymbolIndicator pSymbolIndicator = &(pSymbol->Indicator);
        if (pSymbolIndicator == DisplayObj.Properties.SelectedSymbol) {
            SymbolIndicator_SetSelected(pSymbolIndicator, state);
        } else {
            SymbolIndicator_SetSelected(pSymbolIndicator, FALSE);
        }
        pSymbol++;
    }    
}

BOOL FlashSelectedStabilize() {  
static BOOL state = FALSE;    
    if (DisplayObj.Properties.SelectedSymbol == NULL) {
        return FALSE;    
    } else if (GetElapsedPeriod(DisplayObj.Properties.SelectedSymbolTimeout) >= SYSTICK_mS(5000)) {   
        InternalSelectStabilize(FALSE);
        Display_Flush();
        DisplayObj.Properties.SelectedSymbol = NULL; 
        return FALSE;
    } else if (GetElapsedPeriod(DisplayObj.Properties.SelectedSymbolFlashingTick) < SYSTICK_mS(500)) {
        return FALSE;
    } else {    
        DisplayObj.Properties.SelectedSymbolFlashingTick = GetTickCount();   
        InternalSelectStabilize(state);
        Display_Flush();
        state = !state;  
        return TRUE;
    }
}

TSelectStabilizeMode GetCurrentSelectedStabilize() {
    PTSymbolIndicator pSymbolIndicator = DisplayObj.Properties.SelectedSymbol;   
    if (pSymbolIndicator == &DisplayObj.Symbols.VoltageStabA.Indicator) {
        return ssmVoltageA;
    } else if (pSymbolIndicator == &DisplayObj.Symbols.AmperageStabA.Indicator) {
        return ssmAmperageA;
    } else if (pSymbolIndicator == &DisplayObj.Symbols.VoltageStabB.Indicator) {
        return ssmVoltageB;
    } else if (pSymbolIndicator == &DisplayObj.Symbols.AmperageStabB.Indicator) {
        return ssmAmperageB;
    } else {
        return ssmNone;    
    }
}

BOOL IsDisplayInChangingStabilizeMode() {    
    return DisplayObj.Properties.SelectedSymbol != NULL;
}
/*----------------- Stabilize Selecting --------------<<<*/

/*>>>-------------- Stabilize Focusing -----------------*/
BOOL ChangeFocusingStabilize() {
    INT size = GetSymbolsCount();
    PTSymbol pSymbol = (PTSymbol)&DisplayObj.Symbols;
    BOOL request = FALSE;
    while(size-- > 0){
        if (pSymbol->RequestToFocus) {
            request = TRUE;
            break;    
        }  
        pSymbol++;
    }
    if (!request) {
        return FALSE;    
    }  
    
    size = GetMeasuredValuesCount();
    PTSymbol pDeselectSymbol = (PTSymbol)&DisplayObj.Symbols;
    while(size-- > 0){
        if (pSymbol != pDeselectSymbol && SymbolIndicator_GetFocused(&(pDeselectSymbol->Indicator))) {
            if ((pSymbol == &DisplayObj.Symbols.VoltageStabA && pDeselectSymbol == &DisplayObj.Symbols.AmperageStabA) 
            || (pSymbol == &DisplayObj.Symbols.AmperageStabA && pDeselectSymbol == &DisplayObj.Symbols.VoltageStabA) 
            || (pSymbol == &DisplayObj.Symbols.VoltageStabB && pDeselectSymbol == &DisplayObj.Symbols.AmperageStabB) 
            || (pSymbol == &DisplayObj.Symbols.AmperageStabB && pDeselectSymbol == &DisplayObj.Symbols.VoltageStabB)) {
                SymbolIndicator_SetFocused(&(pDeselectSymbol->Indicator), FALSE);   
            }
        }  
        pDeselectSymbol++;
    }    
    SymbolIndicator_SetFocused(&(pSymbol->Indicator), TRUE);
    DisplayObj.Properties.SelectedSymbol = NULL;
    pSymbol->RequestToFocus = FALSE;
    Display_Flush();    
    return TRUE;
}

void RequestToFocusingStabilize(TSelectStabilizeMode selectValue) {
    PTSymbol pSymbol = GetStabilizeSymbol(selectValue);
    if (pSymbol != NULL) {
        pSymbol->RequestToFocus = TRUE;
    }
}
/*----------------- Stabilize Focusing --------------<<<*/

/*>>>-------------- Change Temperature -----------------*/
BOOL ChangeTemperatures() {
    if (DisplayObj.Temperatures.Repaint) { 
        if (DisplayObj.Temperatures.Radiator.RequestToFocus != ValueIndicator_GetFocused(&DisplayObj.Temperatures.Radiator.Indicator)) {
            ValueIndicator_SetFocused(&DisplayObj.Temperatures.Radiator.Indicator, DisplayObj.Temperatures.Radiator.RequestToFocus);  
            DisplayObj.Temperatures.Radiator.RequestToFocus = FALSE; 
        }        
        if (DisplayObj.Temperatures.Radiator.RequestToChangeValue) {
            ValueIndicator_SetValue(&DisplayObj.Temperatures.Radiator.Indicator, DisplayObj.Temperatures.Radiator.NewValue);
            DisplayObj.Temperatures.Radiator.RequestToChangeValue = FALSE;
            ValueIndicator_Repaint(&DisplayObj.Temperatures.Radiator.Indicator); 
        }     
        if (DisplayObj.Temperatures.Cpu.RequestToChangeValue) {
            ValueIndicator_SetValue(&DisplayObj.Temperatures.Cpu.Indicator, DisplayObj.Temperatures.Cpu.NewValue);
            DisplayObj.Temperatures.Cpu.RequestToChangeValue = FALSE;
            ValueIndicator_Repaint(&DisplayObj.Temperatures.Cpu.Indicator);
        }
        DisplayObj.Temperatures.Repaint = FALSE;
        Display_Flush();    
        return TRUE;  
    }  
    return FALSE;      
}

void RequestToChangeTemperatures(TTemperature temperatures) {
static BYTE RadiatorErrCnt = 0;
static BYTE CpuErrCnt = 0;
BOOL isNorm = TemperatureSensorIsNorm(temperatures.Radiator);
    if (temperatures.Radiator != DisplayObj.Temperatures.Radiator.NewValue || !isNorm) {
        if (isNorm) {
            RadiatorErrCnt = 0;  
            DisplayObj.Temperatures.Radiator.RequestToChangeValue = TRUE;              
        } else if (RadiatorErrCnt++ >= 10) {
            DisplayObj.Temperatures.Radiator.RequestToChangeValue = TRUE;     
        }
        DisplayObj.Temperatures.Radiator.NewValue = temperatures.Radiator;  
        DisplayObj.Temperatures.Repaint = TRUE;
    }
    
    isNorm = TemperatureSensorIsNorm(temperatures.Cpu);
    if (temperatures.Cpu != DisplayObj.Temperatures.Cpu.NewValue || !isNorm) {
        if (isNorm) {
            CpuErrCnt = 0;  
            DisplayObj.Temperatures.Cpu.RequestToChangeValue = TRUE;              
        } else if (CpuErrCnt++ >= 10) {
            DisplayObj.Temperatures.Cpu.RequestToChangeValue = TRUE;     
        }   
        DisplayObj.Temperatures.Cpu.NewValue = temperatures.Cpu;  
        DisplayObj.Temperatures.Repaint = TRUE;
    }
    if (temperatures.FanIsOn) {
        DisplayObj.Temperatures.Radiator.RequestToFocus = TRUE;     
    }
}

void RequestToRepaintTemperatures() {
    DisplayObj.Temperatures.Repaint = TRUE;
    DisplayObj.Temperatures.Radiator.RequestToChangeValue = TRUE; 
    DisplayObj.Temperatures.Cpu.RequestToChangeValue = TRUE;
    DisplayObj.Temperatures.Radiator.RequestToFocus = ValueIndicator_GetFocused(&DisplayObj.Temperatures.Radiator.Indicator); 
}
/*----------------- Change Temperature --------------<<<*/

/*>>>-------------- MousePresent Visibility -----------------*/
BOOL ChangeMousePresentVisibility() {    
    if (DisplayObj.StateSymbols.MousePresentRepaint) {  
        if (DisplayObj.StateSymbols.MousePresentVisible) { 
            SymbolIndicator_SetSelected(&DisplayObj.StateSymbols.MousePresent, FALSE);
            SymbolIndicator_SetFocused(&DisplayObj.StateSymbols.MousePresent, TRUE); 
        } else {
            SymbolIndicator_SetFocused(&DisplayObj.StateSymbols.MousePresent, FALSE);
            SymbolIndicator_SetSelected(&DisplayObj.StateSymbols.MousePresent, TRUE); 
        }          
        Display_Flush();
        DisplayObj.StateSymbols.MousePresentRepaint = FALSE;
        return TRUE;
    } else {
        return FALSE; 
    }    
}

BOOL RequestToVisibileMousePresent(BOOL visible) {
    if (DisplayObj.StateSymbols.MousePresentRepaint) {
        return FALSE;
    }
    DisplayObj.StateSymbols.MousePresentVisible = visible;
    DisplayObj.StateSymbols.MousePresentRepaint = TRUE;
    return TRUE;
}

void RequestToRepaintMousePresent() {
    DisplayObj.StateSymbols.MousePresentRepaint = TRUE;
}
/*----------------- MousePresent Focusing --------------<<<*/

/*>>>-------------- Show error -----------------*/
void OutputMessage(PCHAR message) {    
    Display_SetFont(1);
    ClipStringAlignMid(message, ' ', 20);    
    Display_Print(message, DisplayObj.Requests.MessageColor, MessageCoordX, MessageCoordY, TRUE); 
}

BOOL RequestToShowMessage(PCHAR message, TTextColor messageColor) {
    memcpy(DisplayObj.Requests.Message, message, strlen(message) + 1);
    DisplayObj.Requests.MessageColor = messageColor;
    DisplayObj.Requests.ShowMessage = TRUE;
    return TRUE;
}

BOOL ShowMessage() {    
    if (!DisplayObj.Requests.ShowMessage) {
        return FALSE;
    }
    OutputMessage(DisplayObj.Requests.Message);
    DisplayObj.Requests.ShowMessage = FALSE;
    return TRUE;
}

BOOL RequestToClearMessage() {
    DisplayObj.Requests.ClearMessage = TRUE;
    return TRUE;
}

BOOL ClearMessage() {    
    if (!DisplayObj.Requests.ClearMessage) {
        return FALSE;
    }    
    CHAR buffer[45];
    buffer[0] = 0;
    OutputMessage(buffer);
    DisplayObj.Requests.ClearMessage = FALSE;
    return TRUE;
}
/*----------------- Show error --------------<<<*/

/*>>>-------------- Show error for Over Voltage/Amperage -----------------*/
BOOL Display_RequestToErrorOver(TErrorOver errorOver) {
    DisplayObj.Requests.ErrorOver = errorOver;
    DisplayObj.Requests.ErrorOverRequest = TRUE;
    return TRUE;
}

void ErrorOverVoltageA(TLineType lineType, BOOL showFrame) {  
    Display_FillRectangle(OverVoltageACoordX + 2, OverVoltageACoordY + 2, OverVoltageACoordX - 2 + OverVoltageAWidth, 
        OverVoltageACoordY - 2 + OverVoltageAHeight, lineType, FALSE);
    Display_DrawRectangle(OverVoltageACoordX, OverVoltageACoordY, OverVoltageACoordX + OverVoltageAWidth, 
        OverVoltageACoordY + OverVoltageAHeight, showFrame ? ltSolid : ltInvisible, FALSE);
}

void ErrorOverAmperageA(TLineType lineType, BOOL showFrame) {  
    Display_FillRectangle(OverAmperageACoordX, OverAmperageACoordY, OverAmperageACoordX + OverAmperageAWidth, 
        OverAmperageACoordY + OverAmperageAHeight, lineType, FALSE);
    Display_DrawRectangle(OverAmperageACoordX, OverAmperageACoordY, OverAmperageACoordX + OverAmperageAWidth, 
        OverAmperageACoordY + OverAmperageAHeight, showFrame ? ltSolid : ltInvisible, FALSE);
}

void ErrorOverVoltageB(TLineType lineType, BOOL showFrame) {  
    Display_FillRectangle(OverVoltageBCoordX, OverVoltageBCoordY, OverVoltageBCoordX + OverVoltageBWidth, 
        OverVoltageBCoordY + OverVoltageBHeight, lineType, FALSE);
    Display_DrawRectangle(OverVoltageBCoordX, OverVoltageBCoordY, OverVoltageBCoordX + OverVoltageBWidth, 
        OverVoltageBCoordY + OverVoltageBHeight, showFrame ? ltSolid : ltInvisible, FALSE);
}

void ErrorOverAmperageB(TLineType lineType, BOOL showFrame) {  
    Display_FillRectangle(OverAmperageBCoordX, OverAmperageBCoordY, OverAmperageBCoordX + OverAmperageBWidth, 
        OverAmperageBCoordY + OverAmperageBHeight, lineType, FALSE);
    Display_DrawRectangle(OverAmperageBCoordX, OverAmperageBCoordY, OverAmperageBCoordX + OverAmperageBWidth, 
        OverAmperageBCoordY + OverAmperageBHeight, showFrame ? ltSolid : ltInvisible, FALSE);
}

BOOL ShowErrorOver() {    
    if (!DisplayObj.Requests.ErrorOverRequest) {
        return FALSE;
    }
    DisplayObj.Properties.ErrorOver = DisplayObj.Requests.ErrorOver;
    DisplayObj.Properties.ErrorOverFlashingTick = 0; 
    DisplayObj.Requests.ErrorOverRequest = FALSE;
    if (DisplayObj.Properties.ErrorOver == ERROR_OVER_NONE) {
        ErrorOverVoltageA(ltInvisible, FALSE);
        ErrorOverAmperageA(ltInvisible, FALSE);
        ErrorOverVoltageB(ltInvisible, FALSE);
        ErrorOverAmperageB(ltInvisible, FALSE);
        Display_Flush();
    }
    return TRUE;
}

BOOL FlashErrorOver() {  
static BOOL state = FALSE;     
    if (DisplayObj.Properties.ErrorOver == ERROR_OVER_NONE) {
        return FALSE;    
    } else if (GetElapsedPeriod(DisplayObj.Properties.ErrorOverFlashingTick) < SYSTICK_mS(300)) {
        return FALSE;
    } else {    
        DisplayObj.Properties.ErrorOverFlashingTick = GetTickCount();   
        TLineType hwOver;
        TLineType swOver;
        if (state) {
            hwOver = ltSolid;   
            swOver = ltDoted;
        } else {
            hwOver = ltInvisible;   
            swOver = ltInvisible;
        }
        if (DisplayObj.Properties.ErrorOver & ERROR_OVER_HW_VOLTAGE_A) {
            ErrorOverVoltageA(hwOver, TRUE);
        } else if (DisplayObj.Properties.ErrorOver & ERROR_OVER_SW_VOLTAGE_A) {
            ErrorOverVoltageA(swOver, TRUE);
        }
        if (DisplayObj.Properties.ErrorOver & ERROR_OVER_HW_AMPERAGE_A) {
            ErrorOverAmperageA(hwOver, TRUE);
        } else if (DisplayObj.Properties.ErrorOver & ERROR_OVER_SW_AMPERAGE_A) {
            ErrorOverAmperageA(swOver, TRUE);
        }
        if (DisplayObj.Properties.ErrorOver & ERROR_OVER_HW_VOLTAGE_B) {
            ErrorOverVoltageB(hwOver, TRUE);
        } else if (DisplayObj.Properties.ErrorOver & ERROR_OVER_SW_VOLTAGE_B) {
            ErrorOverVoltageB(swOver, TRUE);
        }
        if (DisplayObj.Properties.ErrorOver & ERROR_OVER_HW_AMPERAGE_B) {
            ErrorOverAmperageB(hwOver, TRUE);
        } else if (DisplayObj.Properties.ErrorOver & ERROR_OVER_SW_AMPERAGE_B) {
            ErrorOverAmperageB(swOver, TRUE);
        }        
        Display_Flush();
        state = !state;  
        return TRUE;
    }
}
/*----------------- Show error for Over Voltage/Amperage --------------<<<*/

void Display_WorkStateChanged(TMainWorkState oldState, TMainWorkState newState){
    if (newState == mwsStart) {
        Display_Backlight(50);
    } else if (newState == mwsStandBy) {
        Display_Backlight(140);
    } else if (newState == mwsWork) {
        Display_Backlight(210);
    } else if (newState == mwsErrGlb) {
        Display_Backlight(255);
    }
}
