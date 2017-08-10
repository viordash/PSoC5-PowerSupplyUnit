/* ========================================
*
* Copyright VIOR, 2014
* All Rights Reserved
* UNPUBLISHED, LICENSED SOFTWARE.
*
* CONFIDENTIAL AND PROPRIETARY INFORMATION
* WHICH IS THE PROPERTY OF VIOR.
*
* ========================================
*/


#include "DS1821.h"
#include "TemperControl.h"
#include "MainWork.h"

BOOL TemperInit = TRUE;

WORD wrrr= 0;
TTemperatureDeviceStatus BusReset(void) {
	switch (DS1821_BusReset()) {
		case 1: return tdsNoDevice;
		case 255: return tdsBusShort;
		default: return tdsPresent;
	}
}

INT ReadTemper(void) {
	INT bt;
    TTemperatureDeviceStatus status = BusReset();
	if (status == tdsNoDevice) {
        return TEMPER_NO_DEVICE;
    } else if (status == tdsBusShort) {
        return TEMPER_BUS_SHORT;
    } else if (status != tdsPresent) {
        return TEMPER_ERR;
    } 

	DS1821_Write8(0xAC);  //READ STATUS
	bt = DS1821_Read8();

	if ((bt & (/*0x10 | 0x08 |*/ 0x04 | 0x01)) /*|| !(bt & 0x01)*/ || TemperInit) {			//Check bits 1SHOT & T\R in config register of DS1821
		TemperInit = FALSE;
		if (!BusReset()) return TEMPER_ERR;
		DS1821_Write8(0x0C);  //WRITE STATUS
		DS1821_Write8(0x00);
		if (!BusReset()) return TEMPER_ERR;
		DS1821_Write8(0xAC);  //READ STATUS
		bt = DS1821_Read8();
		if ((bt & (0x04 | 0x01)) /*|| !(bt & 0x01)*/) {			//Check bits 1SHOT & T\R in config register of DS1821
			return TEMPER_ERR;
		}
		if (!BusReset()) return TEMPER_ERR;
		DS1821_Write8(0xEE);   //START CONVERT T
	}

	if (!BusReset()) return(FALSE);
	DS1821_Write8(0xAA);
	return DS1821_Read8();
}

TTemperature CheckTemper(void) {
    TTemperature res = {TEMPER_INIT, TEMPER_INIT, FALSE};
	res.Radiator = ReadTemper();
    
	static SHORT CPUTemperature = TEMPER_ERR;
	DieTemp_Query(&CPUTemperature);
    res.Cpu = (INT)CPUTemperature;
	DieTemp_Start();
	if (res.Radiator >= 80) {
		FanCtrl_WriteCompare(255);
        res.FanIsOn = TRUE;
	} else if (res.Radiator >= 70) {
		FanCtrl_WriteCompare(220);
        res.FanIsOn = TRUE;
	} else if (res.Radiator >= 60) {
		FanCtrl_WriteCompare(180);
        res.FanIsOn = TRUE;
	} else if (res.Radiator >= 50) {
		FanCtrl_WriteCompare(128);
        res.FanIsOn = TRUE;
	} else if (res.Radiator >= 40) {
		FanCtrl_WriteCompare(80);
        res.FanIsOn = TRUE;
	} else if (MainWorkObj.State == mwsWork && res.Radiator >= 35) {
		FanCtrl_WriteCompare(32);
	} else if (res.Cpu >= 45) {
		FanCtrl_WriteCompare(90);
        res.FanIsOn = TRUE;
	} else if (res.Cpu >= 40) {
		FanCtrl_WriteCompare(40);
	} else if (res.Cpu >= 37) {
		FanCtrl_WriteCompare(10);
	} else {
		FanCtrl_WriteCompare(0);
        res.FanIsOn = FALSE;
	}
	return res;
}

/* [] END OF FILE */
