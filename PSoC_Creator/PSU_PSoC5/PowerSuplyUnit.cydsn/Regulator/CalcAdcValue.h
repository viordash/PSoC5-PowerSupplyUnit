/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#ifndef __CalcAdcValue_H__
#define __CalcAdcValue_H__
	
#include <device.h>
#include "Utils\MedianFilters.h"


extern INT CalcDisplayValueVoltageA (TElectrValue value);
extern TElectrValue CalcSetPointValueVoltageA (TElectrValue value);
extern INT CalcDisplayValueAmperageA (TElectrValue value);
extern INT CalcDisplayValueVoltageB (TElectrValue value);
extern TElectrValue CalcSetPointValueVoltageB (TElectrValue value);
extern INT CalcDisplayValueAmperageB (TElectrValue value);
	
#endif  /* __CalcAdcValue_H__ */
/* [] END OF FILE */
