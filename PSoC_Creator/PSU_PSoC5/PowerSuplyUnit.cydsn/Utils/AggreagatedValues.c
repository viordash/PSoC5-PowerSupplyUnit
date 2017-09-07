#include "Utils\AggreagatedValues.h"

TElectrValue MedianFilter3(TElectrValue a, TElectrValue b, TElectrValue c);

void AggreagatedValues_Init(PTAggreagatedValues pAggreagatedValues) {      
    pAggreagatedValues->RingBuffer.Pop = 0; 
    pAggreagatedValues->RingBuffer.Push = 0;
}

void AggreagatedValues_Push(PTAggreagatedValues pAggreagatedValues, TElectrValue value) {
    DWORD pos = pAggreagatedValues->RingBuffer.Push++ & AGG_BUFFER_SIZE_MASK; 
    pAggreagatedValues->RingBuffer.Buffer[pos] = value;
}

TElectrValue AggreagatedValues_Pop(PTAggreagatedValues pAggreagatedValues) {
    DWORD size = (pAggreagatedValues->RingBuffer.Push - pAggreagatedValues->RingBuffer.Pop) & AGG_BUFFER_SIZE_MASK;  
    TSumElectrValue res = 0;
    DWORD medianRest = size % 3;
    PTElectrValue pBuffer;
    if (size <= medianRest) {
        DWORD size_t = size;
        DWORD pos = pAggreagatedValues->RingBuffer.Pop & AGG_BUFFER_SIZE_MASK;
        pBuffer = &(pAggreagatedValues->RingBuffer.Buffer[pos]);
        while (size--) {
            res += *(pBuffer++);            
        }
        pAggreagatedValues->RingBuffer.Pop += size_t;
        res = res / (TSumElectrValue)size_t;
        return (TElectrValue)res;
    }
    pAggreagatedValues->RingBuffer.Pop += medianRest;
    size -= medianRest;
    DWORD size_t = size / 3;
    while (size) {
        TElectrValue value0 = pAggreagatedValues->RingBuffer.Buffer[pAggreagatedValues->RingBuffer.Pop++ & AGG_BUFFER_SIZE_MASK];
        TElectrValue value1 = pAggreagatedValues->RingBuffer.Buffer[pAggreagatedValues->RingBuffer.Pop++ & AGG_BUFFER_SIZE_MASK];
        TElectrValue value2 = pAggreagatedValues->RingBuffer.Buffer[pAggreagatedValues->RingBuffer.Pop++ & AGG_BUFFER_SIZE_MASK];
        res += MedianFilter3(value0, value1, value2);
        size -= 3;
    }
    res = res / (TSumElectrValue)size_t;
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