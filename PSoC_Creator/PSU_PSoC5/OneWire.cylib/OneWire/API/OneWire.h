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

#if !defined(`$INSTANCE_NAME`_H) 
#define `$INSTANCE_NAME`_H


#include "cytypes.h"        //Обеспечивает macros и еще что-то
//#include "cylib.h"
//#include "cyfitter.h"     //Файл определяет адреса при компиляции.


#define Tinact  20          //in us. (Inactive before next signal)
#define TMtr0   50          //Data bit 0 read,write 15-60us
#define TMtr1   10          //Data bit 1 read,write 1-15us
#define RST_MAX 480         //in us.(минимум 480)

/***************************************
*        Function Prototypes 
***************************************/

uint8 `$INSTANCE_NAME`_R_Bit();                 //******   ReadBit ************

void `$INSTANCE_NAME`_W_Bit(uint8 payload);     //******   WriteBit ***********

uint8 `$INSTANCE_NAME`_BusReset();              //******** Bus Reset **********

void `$INSTANCE_NAME`_Write8(uint8 payload);    //******* Write a byte *********

uint8 `$INSTANCE_NAME`_Read8();              // чтение байта (не проверено!!!)



#endif












//[] END OF FILE
