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

/* [] END OF FILE */
#include "`$INSTANCE_NAME`.h"
#include <device.h>

/************************   ReadBit *******************************************/

uint8 `$INSTANCE_NAME`_R_Bit() //***  Read a single bit off the 1-WIRE bus. ***
    {
        CyDelayUs(Tinact);  // Inactive before next signal........#define Tinact 20   //in us. (Inactive before next signal)
        `$INSTANCE_NAME`_Pin_Write(0);       // Drive it low.                                             варианты: http://www.cypress.com/?rID=38854&cache=0
        CyDelayUs(TMtr1);   // If its a 1 to write. ....   #define TMtr1 10    //Data bit 1 read,write 1-15us
       `$INSTANCE_NAME`_Pin_Write(1);       // Back High.
	    CyDelayUs(5);       // проверяем через 5??? мкСек
	return(`$INSTANCE_NAME`_Pin_Read());     // читаем значение бита
    //return(1);
	}
    
/**************************   WriteBit   **************************************/

void `$INSTANCE_NAME`_W_Bit(uint8 payload) // Write a single bit to the 1-WIRE bus. 
    {
	    CyDelayUs(Tinact);  //Inactive before next signal.
	    `$INSTANCE_NAME`_Pin_Write(0);       //Drive it low.
	        if(payload==0)		CyDelayUs(TMtr0); //If its a 0 to write.
	        else     		    CyDelayUs(TMtr1); //If its a 1 to write.
	    `$INSTANCE_NAME`_Pin_Write(1);       //Back High.
    }

/*************************   Bus Reset   **************************************/
   
uint8 `$INSTANCE_NAME`_BusReset() //Pulldown the required "Bus Reset". *******
    {
uint8 BusPin=0 ;       //Состояние шины
        `$INSTANCE_NAME`_Pin_Write(0);       // Drive it low.
	    CyDelayUs(RST_MAX); // Передаем ипульс RESET минимум 480 мкСек
	    `$INSTANCE_NAME`_Pin_Write(1);       // Back High.
        CyDelayUs(5);       // проверяем отсутствие к.з. в линии
        if (`$INSTANCE_NAME`_Pin_Read()==0x00)  	return(0xFF);   //линия закорочена, выходим.
        CyDelayUs(55);      // через 15-60 мкСек проверяем наличие PRESENCE  (60-240 мкСек)
        BusPin = `$INSTANCE_NAME`_Pin_Read();   // Запомним Состояние шины
        CyDelayUs(200);     // Устройство все еще передает PRESENCE  (60-240) мкСек, ждем-с
return(BusPin);        //Возвращаем Состояние шины
    }
 
/**************************   Write a byte   **********************************/
void `$INSTANCE_NAME`_Write8(uint8 payload) //Write a byte to the slave.
    {
	    uint8 BitPayload,  shiftcount;
	    for (shiftcount=0; shiftcount<=7;shiftcount++) 
        {
            BitPayload = (payload >> shiftcount) & 0x01; //начнем с LSB
            `$INSTANCE_NAME`_W_Bit(BitPayload);
        }
    }  
    
/****************************   Read 8 bits  **********************************/

 uint8 `$INSTANCE_NAME`_Read8() //Read 8 bits "clocked" out by the slave. 
{
	uint8 IncomingByte=0, shiftcount=0 ;
	for (shiftcount=0; shiftcount<=7; shiftcount++) 
    {
       IncomingByte |= (`$INSTANCE_NAME`_R_Bit())<<shiftcount;//начинаем с  LSB
    }
    return(IncomingByte);
}
   
    