#ifndef __AggreagatedValues_H
#define __AggreagatedValues_H

#include <device.h>
    
#define AGG_BUFFER_SIZE 512 /*(VoltageChartWidth > AmperageChartWidth ? VoltageChartWidth : AmperageChartWidth)*/
#define AGG_BUFFER_SIZE_MASK (AGG_BUFFER_SIZE - 1)
    
typedef struct {       
  DWORD Push;               //указывает на последний принятый байт + 1
  DWORD Pop;                //указывает на считанный байт + 1
  TElectrValue Buffer[AGG_BUFFER_SIZE];         //указывает на начало буфера приема
} TRingBuffer, * PTRingBuffer;
 
typedef struct {
    TRingBuffer RingBuffer;
} TAggreagatedValues, *PTAggreagatedValues;
    
extern void AggreagatedValues_Init(PTAggreagatedValues pAggreagatedValues);
extern void AggreagatedValues_Push(PTAggreagatedValues pAggreagatedValues, TElectrValue value);
extern TElectrValue AggreagatedValues_Pop(PTAggreagatedValues pAggreagatedValues);

#endif /* end __AggreagatedValues_H */