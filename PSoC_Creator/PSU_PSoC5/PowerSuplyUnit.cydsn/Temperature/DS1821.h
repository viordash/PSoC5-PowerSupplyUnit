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

#ifndef __DS1821_H_
#define __DS1821_H_

#include <device.h>

#define Tinact  20          //in us. (Inactive before next signal)
#define TMtr0   50          //Data bit 0 read,write 15-60us
#define TMtr1   10          //Data bit 1 read,write 1-15us
#define RST_MAX 480         //in us.(минимум 480)

/***************************************
*        Function Prototypes 
***************************************/

uint8 DS1821_R_Bit();                 //******   ReadBit ************

void DS1821_W_Bit(uint8 payload);     //******   WriteBit ***********

uint8 DS1821_BusReset();              //******** Bus Reset **********

void DS1821_Write8(uint8 payload);    //******* Write a byte *********

uint8 DS1821_Read8();              // чтение байта (не проверено!!!)


#endif  /* __DS1821_H_ */

//[] END OF FILE
