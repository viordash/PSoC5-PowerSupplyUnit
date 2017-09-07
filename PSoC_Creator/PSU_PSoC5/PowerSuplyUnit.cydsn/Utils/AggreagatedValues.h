#ifndef __AggreagatedValues_H
#define __AggreagatedValues_H

#include <device.h>
    
#define AGG_BUFFER_SIZE 1024 /*(VoltageChartWidth > AmperageChartWidth ? VoltageChartWidth : AmperageChartWidth)*/
 
typedef struct {
  INT Index;
  TElectrValue Buffer[AGG_BUFFER_SIZE];      
} TAggreagatedValues, *PTAggreagatedValues;
    
extern void AggreagatedValues_Init(PTAggreagatedValues pAggreagatedValues);
extern void AggreagatedValues_Push(PTAggreagatedValues pAggreagatedValues, TElectrValue value);
extern TElectrValue AggreagatedValues_Pop(PTAggreagatedValues pAggreagatedValues);

#endif /* end __AggreagatedValues_H */