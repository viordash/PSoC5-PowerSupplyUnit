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

.syntax unified
.text

.global TaskSleep
.func TaskSleep, TaskSleep
.thumb_func
TaskSleep:
  STR	R2, [R0, #+16]      /*Сохранить регистр R2, в первую позицию файла регистров*/

  LDR   R2, =SysTickCount   /*вычислить новое значение момента запуска процедуры*/
  LDR   R2, [R2]
  ADD	R2, R2, R1
  STR	R2, [R0, #+4]

  STR	SP, [R0, #+8]       /*сохранить указатель стека*/
  STR	LR, [R0, #+12]      /*сохранить регистр связи*/

  LDR   R2, [R0]            /*Размер структуры*/
  ADD	R0, R0, R2          /*Сдвинуть в конец структуры TFunction*/
  STMDB	R0, {R3-R12}       /*Сохранить содержимое регистров*/	

  LDR   LR, =TaskShedul     /*перейти к диспетчеру задач*/
  MOV   PC, LR
.endfunc


.global TaskResume
.func TaskResume, TaskResume
.thumb_func
TaskResume:
  LDR   R2, =SysTickCount
  LDR   R2, [R2]
  LDR   R3, [R0, #+4]       /*получить значение OnStartTick*/
  SUBS	R3, R2, R3          /*вычислить разницу*/
  BEQ TaskResume_ExTRUE     /*если наступило время, то запустить (if (StartTick == 0) res = TRUE;)*/            
  IT MI                     /*выйти если еще не наступил момент  (if ((StartTick > 0))*/
  BXMI LR                   /*выйти если еще не наступил момент  (if ((StartTick > 0))*/
  CMP   R3, #0x02000000	    /*33554432 ticks*/
  IT PL
  MOVPL PC, LR              /*выйти если разница больше чем макс. время задержки ((33554432 >= (StartTick - SysTickCount)))*/

TaskResume_ExTRUE:
  MOV   R1, R0
  ADD		R1, R1, #16         /*Сдвинуть в начала регистрового файла TFunction*/
  LDMFD	R1, {R2-R12}       /*восстановить содержимое регистров*/

  LDR   R1, [R0, #+8]         /*значение указ. стека*/
  CMP   R1, #0                /*если стек равен 0, то не восстанавливать*/
  IT NE
  MOVNE SP, R1
  LDR   LR, [R0, #+12]        /*значение регистр связи*/
  MOV   PC, LR
.endfunc


.end


/* [] END OF FILE */
