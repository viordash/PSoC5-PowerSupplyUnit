/*******************************************************************************
* Copyright 2009, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/
/* ========================================
 *
 * This file is automatically generated by PSoC Creator
 * and should not be edited by hand.
 *
 * This file is necessary for your project to build.
 * Please do not delete it.
 *
 * ========================================
*/

#ifndef __DEVICE_H__
#define __DEVICE_H__
    
#include <project.h>
#include "type.h"
#include "OS\SystemOS.h"    
#include "Utils\GeneralUtils.h"

#define PROGRAM_VERSION_MAJOR 1
#define PROGRAM_VERSION_MINOR 0
    
#define TEMPER_ERR (127)
#define TEMPER_NO_DEVICE (TEMPER_ERR - 1)
#define TEMPER_BUS_SHORT (TEMPER_NO_DEVICE - 1)
#define TEMPER_INIT (TEMPER_BUS_SHORT - 1)
#define TemperatureSensorIsNorm(value) (value != TEMPER_ERR && value != TEMPER_NO_DEVICE && value != TEMPER_BUS_SHORT && value != TEMPER_INIT)
    
#define Voltage_MAX 15 * 100
#define Voltage_MIN 0
#define Voltage_Default 1260
#define Amperage_MAX 8 * 1000
#define Amperage_MIN 5
#define Amperage_Default 1000
    
    
#define ERROR_OVER_NONE 0x00
#define ERROR_OVER_HW_VOLTAGE_A 0x01
#define ERROR_OVER_HW_AMPERAGE_A 0x02
#define ERROR_OVER_HW_VOLTAGE_B 0x04
#define ERROR_OVER_HW_AMPERAGE_B 0x08
#define ERROR_OVER_SW_VOLTAGE_A 0x10
#define ERROR_OVER_SW_AMPERAGE_A 0x20
#define ERROR_OVER_SW_VOLTAGE_B 0x40
#define ERROR_OVER_SW_AMPERAGE_B 0x80
    
typedef BYTE TErrorOver, * PTErrorOver;     
    
typedef enum {
	smVoltageStab = 0,
	smAmperageStab,
} TStabilizeMode;

typedef enum {
	rrpuSlow = 0,
	rrpuFast
} TRiseRatePowerUp;

typedef enum {
	svNone = 0,
	svMeasuredVoltageA,
	svMeasuredAmperageA,
	svMeasuredVoltageB,
	svMeasuredAmperageB,
	svSetPointVoltageA,
	svSetPointAmperageA,
	svSetPointVoltageB,
	svSetPointAmperageB,
	svTemperature,
	svTemperatureCpu,
} TSelectValue;

typedef enum {
	cvVoltageA,
	cvAmperageA,
	cvVoltageB,
	cvAmperageB
} TChangedValue;

typedef enum {
	ssmNone = 0,
	ssmVoltageA,
	ssmAmperageA,
	ssmVoltageB,
	ssmAmperageB,
} TSelectStabilizeMode;

typedef enum {
	tcNorm = 0,
	tcInvisible,
	tcInvert
} TTextColor;

typedef enum {
	ltSolid = 0,
	ltDashed,
	ltDoted,
	ltInvisible
} TLineType;

typedef SHORT TElectrValue, * PTElectrValue;     
//typedef TElectrValue TVoltage;      /*voltage * 100*/
//typedef TElectrValue TAmperage;     /*amperage * 1000*/


typedef struct {
	INT Radiator;
    INT Cpu;
    BOOL FanIsOn;
} TTemperature, *PTTemperature;

#define VOLTAGE_CALIBRATE_POINT_COUNT 16
#define AMPERAGE_CALIBRATE_POINT_COUNT 16

typedef struct {
	TElectrValue Adc;
	TElectrValue Pwm;
    BYTE Crc;
} TCalibrateItem, *PTCalibrateItem;

typedef struct {
    TElectrValue VoltageA;
    TElectrValue AmperageA;
    TElectrValue VoltageB;
    TElectrValue AmperageB;
    TStabilizeMode StabilizeModeA;
    TStabilizeMode StabilizeModeB;
} TSettings, *PTSettings;

#define STORAGE_OK_MAGIC 123
#define EEPROM_ROW_SIZE_BYTES 16

typedef struct {	
	TCalibrateItem CalibratedVoltage[VOLTAGE_CALIBRATE_POINT_COUNT];
	TCalibrateItem CalibratedAmperage[VOLTAGE_CALIBRATE_POINT_COUNT];
    TSettings Settings;
    DWORD Crc;
    BYTE Ok;
    BYTE Dummy[((sizeof(TCalibrateItem) * VOLTAGE_CALIBRATE_POINT_COUNT) + (sizeof(TCalibrateItem) * VOLTAGE_CALIBRATE_POINT_COUNT) 
                + sizeof(TSettings)/*Settings*/ + sizeof(DWORD)/*Crc*/ + sizeof(BYTE)/*Ok*/) % EEPROM_ROW_SIZE_BYTES];
    
} TEepromStrorage, *PTEepromStrorage;

typedef enum {
	mwsInit = 0,
	mwsStart,
	mwsStandBy,
	mwsWork,
	mwsErrGlb
} TMainWorkState;
#endif  /* __DEVICE_H__ */
/*[]*/
