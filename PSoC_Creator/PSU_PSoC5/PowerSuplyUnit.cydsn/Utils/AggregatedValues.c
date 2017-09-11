#include "Utils\AggregatedValues.h"

TElectrValue MedianFilter3(TElectrValue a, TElectrValue b, TElectrValue c);

void AggregatedValues_Init(PTAggregatedValues pAggregatedValues, PTElectrValue buffer, INT size) {      
    pAggregatedValues->Index = 0;      
    pAggregatedValues->Buffer = buffer;      
    pAggregatedValues->Size = size;   
}

void AggregatedValues_Push(PTAggregatedValues pAggregatedValues, TElectrValue value) {
    pAggregatedValues->Buffer[pAggregatedValues->Index] = value;
    if (++pAggregatedValues->Index >= pAggregatedValues->Size) {
        pAggregatedValues->Index = 0;
    }
}

TElectrValue AggregatedValues_Pop(PTAggregatedValues pAggregatedValues, TProcessTasks pProcessTasks) {
    INT size = pAggregatedValues->Index + 1;  
    TSumElectrValue res = 0;
    INT medianRest = size % 3;
    PTElectrValue pBuffer;
    if (size <= medianRest) {
        INT size_t = size;
        pBuffer = pAggregatedValues->Buffer;
        while (size--) {
            res += *(pBuffer++);            
        }
        res = res / (TSumElectrValue)size_t;
        pAggregatedValues->Index = 0; 
        return (TElectrValue)res;
    }    
    pBuffer = &(pAggregatedValues->Buffer[medianRest]);
    size -= medianRest;
    INT processTasks = 0;
    DWORD size_t = size / 3;
    while (size) {
        TElectrValue value0 = *(pBuffer++);
        TElectrValue value1 = *(pBuffer++);
        TElectrValue value2 = *(pBuffer++);
        res += MedianFilter3(value0, value1, value2);
        size -= 3;
        if (pProcessTasks != NULL && processTasks++ & 0x10) {
            pProcessTasks();
            processTasks = 0;
        }
    }
    res = res / (TSumElectrValue)size_t;
    pAggregatedValues->Index = 0; 
    return (TElectrValue)res;
}

TElectrValue MedianFilter3(TElectrValue a, TElectrValue b, TElectrValue c) {
    BOOL a_LessOrEqual_b = a <= b;
    BOOL a_LessOrEqual_c = a <= c;
    BOOL b_LessOrEqual_c = b <= c;
    
    if (a_LessOrEqual_b && a_LessOrEqual_c) {
        return b_LessOrEqual_c ? b : c;
    } 
    if (b_LessOrEqual_c && (b <= a)) {
        return a_LessOrEqual_c ? a : c;
    }
    return a_LessOrEqual_b ? a : b;    
}