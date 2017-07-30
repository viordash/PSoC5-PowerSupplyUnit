
#include "Utils\MedianFilters.h"

void MedianFilter3_Push(PTMedianFilter3 pMedianFilter3, TElectrValue value) {
    if (pMedianFilter3->Index >= MedianFilter3BufferSize) {
        pMedianFilter3->Index = 0;    
    }        
    pMedianFilter3->Buffer[pMedianFilter3->Index++] = value;
}

TElectrValue MedianFilter3_Calc(PTMedianFilter3 pMedianFilter3) {
    TElectrValue a, b, c;
    a = pMedianFilter3->Buffer[0];
    b = pMedianFilter3->Buffer[1];
    c = pMedianFilter3->Buffer[2];
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