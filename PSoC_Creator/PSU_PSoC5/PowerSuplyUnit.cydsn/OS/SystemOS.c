/*****************************************************************************
 *   ��������� �������� �����-MiniPAY
 *   2012.04 VIOR/viordash@mail.ru
 *   SystemOS.c, ��������� � portasm.s79
 *   ���� ���� ������������ ������� ��������� ������� (�����).
 *   ����� �������������, ��������� ���� 1 ��.  
 *   ������������ ����� ��������, �� �������� ������� ������ � ����� Sleep.
 *   ���������� ������������� ����� �������� ���.
 *   ��������� ���������� ����� ���. �������� �������� ��������� ��� ������ ��������� ��������� ������� TaskResume ������ ������ � Main.TaskShedul
 *   ������������ TIMER0 � �������� �������� ����� �������. ������ ���������� 1 ��.
 *   ������� ����������: 
 *      InitSysTick(void);                                      //�������� � uS
 *      TaskResume(PTFunction AFunction, void*);                //��������� �� �������� �� ������ ��� ������������� ������ ������ AFunction
 *      TaskSleep(PTFunction AFunction, DWORD AWaitMilliSec);   //������������� ������ ������ �� AWaitMilliSec �����������
 *      TaskExecInit(PTFunction AFunction, POINTER AGoAdress, DWORD AStackStrt);    //������������� ��������� ������, 
 *              AGoAdress    - ����� ������� ��������� ����� ������, 
 *              AStackStrt   - ��������� �������� ����� ��� ������
 *      void Delay_uS (DWORD ACount_uS);                        //�������� � uS
 *      DWORD SysTickCount;                                     //������� ��������� �����
 *   TFunction - ��������� ������ ��� ������ ������
 *   struct TFunction{
 *     DWORD Size;        //������ ���������
 *     DWORD OnStartTick; //������ ������� ������ (SysTickCount + AWaitMilliSec)
 *     DWORD RegSP;       //���������� ������� �����
 *     DWORD RegLR;       //���������� ��������� �����
 *     DWORD RegContext[REG_FILE_SIZE];       //���������� ������������ �����
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



