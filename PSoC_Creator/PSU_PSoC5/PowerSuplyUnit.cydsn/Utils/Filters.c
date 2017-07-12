

#include "Utils\Filters.h"

TElectrValue GetMedianOf3Value(PTElectrValue pThreeValues) {
    TElectrValue a, b, c;
    a = pThreeValues[0];
    b = pThreeValues[1];
    c = pThreeValues[2];
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