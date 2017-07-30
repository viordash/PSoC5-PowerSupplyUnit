#ifndef __FILTERS_H
#define __FILTERS_H

#include <device.h>
    
#define MedianFilter3BufferSize 3    
typedef struct {
    TElectrValue Buffer[MedianFilter3BufferSize];
    BYTE Index;
} TMedianFilter3, *PTMedianFilter3;
    
extern void MedianFilter3_Push(PTMedianFilter3 pMedianFilter3, TElectrValue value);
extern TElectrValue MedianFilter3_Calc(PTMedianFilter3 pMedianFilter3);

#endif /* end __FILTERS_H */