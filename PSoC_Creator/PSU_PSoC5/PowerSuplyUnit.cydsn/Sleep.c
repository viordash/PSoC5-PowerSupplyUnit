
#include "MainWork.h"
#include "Regulator\RegulatorTask.h"
#include "Sleep.h"

CY_ISR(WakeupIsr);

void IdleTimer_Init() {
    IdleTimer_Reset();    
    I_BtnOk_ClearInterrupt(); 
    IsrWakeup_StartEx(WakeupIsr);
}

void IdleTimer_Reset() {    
    MainWorkObj.IdleTimer = GetTickCount(); 
}

BOOL IdleTimer_Handle() {   
    if (GetElapsedPeriod(MainWorkObj.IdleTimer) < SYSTICK_mS(600000)) {
        return FALSE;
    }
    if (!MainWork_EnteringToSleepMode()) {
        IdleTimer_Reset();
        return FALSE;
    }
    O_Led_Error_Write(TRUE);
    CySysTickStop();
    Regulator_Stop();
    I_BtnOk_ClearInterrupt(); 
    CyPmSaveClocks();
    CyPmHibernate();
    CyPmRestoreClocks();
    CySysTickEnable();
    CySoftwareReset();
    return TRUE;
}

CY_ISR(WakeupIsr) {
    I_BtnOk_ClearInterrupt();
}