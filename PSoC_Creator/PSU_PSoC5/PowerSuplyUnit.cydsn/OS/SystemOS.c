/*****************************************************************************
 *   Платежный терминал Штрих-MiniPAY
 *   2012.04 VIOR/viordash@mail.ru
 *   SystemOS.c, совместно с portasm.s79
 *   Ядро мини операционной системы реального времени (мОСРВ).
 *   мОСРВ многозадачная, временная база 1 мс.  
 *   Переключение между задачами, по переводу текущей задачи в режим Sleep.
 *   Встроенной синхронизации между потоками нет.
 *   Изменение приоритета задач нет. Возможно изменить приоритет при помощи изменения положения функции TaskResume нужной задачи в Main.TaskShedul
 *   Иницилизация TIMER0 в качестве счетчика тиков системы. Период инкремента 1 мС.
 *   Внешние объявления: 
 *      InitSysTick(void);                                      //задержка в uS
 *      TaskResume(PTFunction AFunction, void*);                //Проверяет не наступил ли момент для возобновления работы потока AFunction
 *      TaskSleep(PTFunction AFunction, DWORD AWaitMilliSec);   //Останавливает работу потока на AWaitMilliSec миллисекунд
 *      TaskExecInit(PTFunction AFunction, POINTER AGoAdress, DWORD AStackStrt);    //Иницилизирует параметры задачи, 
 *              AGoAdress    - адрес функции основного цикла задачи, 
 *              AStackStrt   - Начальное значение стека для задачи
 *      void Delay_uS (DWORD ACount_uS);                        //задержка в uS
 *      DWORD SysTickCount;                                     //счетчик системных тиков
 *   TFunction - описывает данные для работы задачи
 *   struct TFunction{
 *     DWORD Size;        //Размер структуры
 *     DWORD OnStartTick; //Момент запуска задачи (SysTickCount + AWaitMilliSec)
 *     DWORD RegSP;       //Содержимое регистр связи
 *     DWORD RegLR;       //Содержимое указатель стека
 *     DWORD RegContext[REG_FILE_SIZE];       //Содержимое регистрового файла
 *   };
******************************************************************************/

#include <device.h>
#include "SystemOS.h"

volatile DWORD SysTickCount; /*inc on every 100uS (SYSTICK_PERIOD_uS)*/

void TaskExecInit(PTFunction AFunction, POINTER AGoAdress, DWORD AStackStrt) {
  (*AFunction).Size = sizeof(TFunction);
  DWORD i;
  for(i = 0; i < REG_FILE_SIZE; ++i) {
    (*AFunction).RegContext[i] = 0;
  }
  (*AFunction).RegLR = (DWORD)AGoAdress;
  (*AFunction).RegSP = AStackStrt;
}

void SysTick_Handler(void) {
  SysTickCount++;
}

void SystemOS_Init(void) {
  SysTickCount = 0;
  (void) CyIntSetSysVector(CY_INT_SYSTICK_IRQN, &SysTick_Handler);
  CySysTickSetClockSource(CY_SYS_SYST_CSR_CLK_SRC_SYSCLK);
  CySysTickSetReload(cydelay_freq_hz / (1000000 / SYSTICK_PERIOD_uS));
  CySysTickClear();
  CyIntEnable(CY_INT_SYSTICK_IRQN);  
  CySysTickEnable();
}



