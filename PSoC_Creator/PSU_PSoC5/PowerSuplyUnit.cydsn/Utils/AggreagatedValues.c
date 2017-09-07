#include "Utils\AggreagatedValues.h"

TElectrValue MedianFilter3(TElectrValue a, TElectrValue b, TElectrValue c);

void AggreagatedValues_Init(PTAggreagatedValues pAggreagatedValues) {      
    pAggreagatedValues->Index = 0; 
}

void AggreagatedValues_Push(PTAggreagatedValues pAggreagatedValues, TElectrValue value) {
    DWORD pos = pAggreagatedValues->Index++; 
    pAggreagatedValues->Buffer[pos] = value;
}

TElectrValue AggreagatedValues_Pop(PTAggreagatedValues pAggreagatedValues) {
    INT size = pAggreagatedValues->Index + 1;  
    TSumElectrValue res = 0;
    INT medianRest = size % 3;
    PTElectrValue pBuffer;
    if (size <= medianRest) {
        INT size_t = size;
        pBuffer = pAggreagatedValues->Buffer;
        while (size--) {
            res += *(pBuffer++);            
        }
        res = res / (TSumElectrValue)size_t;
        pAggreagatedValues->Index = 0; 
        return (TElectrValue)res;
    }    
    pBuffer = &(pAggreagatedValues->Buffer[medianRest]);
    size -= medianRest;
    DWORD size_t = size / 3;
    while (size) {
        TElectrValue value0 = *(pBuffer++);
        TElectrValue value1 = *(pBuffer++);
        TElectrValue value2 = *(pBuffer++);
        res += MedianFilter3(value0, value1, value2);
        size -= 3;
    }
    res = res / (TSumElectrValue)size_t;
    pAggreagatedValues->Index = 0; 
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