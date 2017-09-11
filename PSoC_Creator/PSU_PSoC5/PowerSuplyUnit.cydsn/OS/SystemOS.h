

#ifndef __SYSTEM_OS_H__
#define __SYSTEM_OS_H__
  
#include "type.h"

#define REG_FILE_SIZE 11
typedef struct _TFunction{
  DWORD Size;        //Размер структуры
  DWORD OnStartTick; //Момент запуска задачи (SysTickCount + AWaitMilliSec)
  DWORD RegSP;       //Содержимое регистр связи
  DWORD RegLR;       //Содержимое указатель стека
  DWORD RegContext[REG_FILE_SIZE];         //Содержимое регистрового файла
} TFunction, * PTFunction;

#define SYSTICK_PERIOD_uS (100)
#define SYSTICK_mS(x) (x * (1000 / SYSTICK_PERIOD_uS))
#define GetTickCount() SysTickCount
#define GetElapsedPeriod(fromTickCount) ((GetTickCount() >= fromTickCount) ? GetTickCount() - fromTickCount : (HI_DWORD - fromTickCount) + GetTickCount())

typedef void(*TProcessTasks) (void);

extern volatile DWORD SysTickCount;
extern void TaskSleep(PTFunction AFunction, DWORD ADelayTicks);
extern void TaskResume(PTFunction AFunction, void *);
extern void SystemOS_Init(void);
extern void TaskExecInit(PTFunction AFunction, POINTER AGoAdress, DWORD AStackStrt);




#endif /*__SYSTEM_OS_H__*/