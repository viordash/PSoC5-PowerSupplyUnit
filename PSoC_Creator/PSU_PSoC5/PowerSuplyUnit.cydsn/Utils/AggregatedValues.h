#ifndef __AggregatedValues_H
#define __AggregatedValues_H

#include <device.h>
    
#define AGG_CHART_BUFFER_SIZE 2048 /*(VoltageChartWidth > AmperageChartWidth ? VoltageChartWidth : AmperageChartWidth)*/
#define AGG_IND_BUFFER_SIZE 32 
 
typedef struct {
  INT Index;
  INT Size;
  PTElectrValue Buffer;     
} TAggregatedValues, *PTAggregatedValues;
    
extern void AggregatedValues_Init(PTAggregatedValues pAggregatedValues, PTElectrValue Buffer, INT size);
extern void AggregatedValues_Push(PTAggregatedValues pAggregatedValues, TElectrValue value);
extern TElectrValue AggregatedValues_Pop(PTAggregatedValues pAggregatedValues, TProcessTasks pProcessTasks);

#endif /* end __AggregatedValues_H */