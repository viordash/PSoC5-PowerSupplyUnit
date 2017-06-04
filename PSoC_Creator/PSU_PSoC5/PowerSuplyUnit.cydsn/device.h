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
    
typedef enum {
	smVoltageStab = 0,
	smAmperageStab,
} TStabilizeMode;


typedef enum {
	tcNorm = 0,
	tcInvisible,
	tcInvert
} TTextColor;

typedef enum {
	ltSolid = 0,
	ltDashed,
	ltDoted
} TLineType;

#endif  /* __DEVICE_H__ */
/*[]*/
