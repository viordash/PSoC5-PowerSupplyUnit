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

#ifndef __TemperControl_H_
#define __TemperControl_H_
    
#include <device.h>
    
    
typedef enum {
    tdsInit = 0,
	tdsNoDevice,
	tdsBusShort,
	tdsPresent
} TTemperatureDeviceStatus;


extern TTemperature CheckTemper(void);
#endif  /* __TemperControl_H_ */












//[] END OF FILE
