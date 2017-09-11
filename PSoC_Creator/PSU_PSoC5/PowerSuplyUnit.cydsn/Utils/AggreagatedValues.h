#ifndef __AggreagatedValues_H
#define __AggreagatedValues_H

#include <device.h>
    
#define AGG_CHART_BUFFER_SIZE 2048 /*(VoltageChartWidth > AmperageChartWidth ? VoltageChartWidth : AmperageChartWidth)*/
#define AGG_IND_BUFFER_SIZE 32 
 
typedef struct {
  INT Index;
  INT Size;
  PTElectrValue Buffer;     
} TAggreagatedValues, *PTAggreagatedValues;
    
extern void AggreagatedValues_Init(PTAggreagatedValues pAggreagatedValues, PTElectrValue Buffer, INT size);
extern void AggreagatedValues_Push(PTAggreagatedValues pAggreagatedValues, TElectrValue value);
extern TElectrValue AggreagatedValues_Pop(PTAggreagatedValues pAggreagatedValues, TProcessTasks pProcessTasks);

#endif /* end __AggreagatedValues_H */