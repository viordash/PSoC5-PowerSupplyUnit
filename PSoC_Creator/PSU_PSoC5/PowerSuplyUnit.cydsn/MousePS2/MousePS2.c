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

/* [] END OF FILE */

#include <device.h>
#include "MousePS2.h"
#include "MainWork.h"

#define MSMode_Init 0 
#define MSMode_RXTXMask 0x80
#define MSMode_RX 0x00 
#define MSMode_TX 0x80 

#define MSMode_StateMask 0x3F
#define MSMode_StateReset 0x00
#define MSMode_StateSetSampleRate0Cmd 0x01
#define MSMode_StateSetSampleRate0Val 0x02
#define MSMode_StateSetSampleRate1Cmd 0x03
#define MSMode_StateSetSampleRate1Val 0x04
#define MSMode_StateSetSampleRate2Cmd 0x05
#define MSMode_StateSetSampleRate2Val 0x06
#define MSMode_StateGetdeviceID 			0x07
#define MSMode_SetRemoteMode          0x08
#define MSMode_ReadData            		0x09
#define MSMode_StateSetSampleRate3Cmd 0x0A
#define MSMode_StateSetSampleRate3Val 0x0B


#define MSFrame_DelayMs 20 

BYTE MouseMode = MSMode_Init;
BYTE MouseDataReg = 0;
BYTE MouseBitNum = 0;
BYTE MouseData[8];
BYTE MouseByteNum = 0;
DWORD MouseLastActTick = 0;
BYTE MouseMidBtn = 0;


void MouseData_WriteRee(BYTE value) {
	BYTE staticBits = (MouseData_DR & (BYTE)(~MouseData_MASK));
	MouseData_DR = staticBits | ((BYTE)(value << MouseData_SHIFT) & MouseData_MASK);
}

BYTE MouseData_ReadRee(void) {
	return (MouseData_PS & MouseData_MASK);
}

BYTE MouseClk_ReadRee(void) {
	return (MouseClk_PS & MouseClk_MASK);
}

BOOL ParityCheckOdd(BOOL AParityBit) {
	BYTE Data = MouseDataReg;
	BYTE BitCnt;
	if (AParityBit) BitCnt = 1;
	else BitCnt = 0;
	while (Data != 0) {
		Data &= (Data - 1);
		BitCnt++;
	}
	return (BitCnt % 2);
}

void MSCommReset(void) {
	MouseBitNum = 0;
	MouseByteNum = 0;
}

CY_ISR(MouseIrqHandler) {
	if (MouseClk_ReadRee() == 0) {
        BOOL dataLine = MouseData_ReadRee();        
        
		if (((MouseMode & MSMode_RXTXMask) == MSMode_RX) /*&& (MouseClk_Read() == 0)*/) {//from the device to the host is read on the falling edge           
			if (MouseBitNum != 0) {  //если не старт бит, то проверить последнюю активность сигнала на CLK, и если дольше MSFrame_DelayMs, то сбросить					
				if (GetElapsedPeriod(MouseLastActTick) > SYSTICK_mS(MSFrame_DelayMs)) {
					MSCommReset();
				}
			}
			if (MouseBitNum == 0) {  //1 start bit.  This is always 0.
				if (dataLine == FALSE) {
					MouseBitNum++;
					MouseDataReg = 0;
				}
			} else if ((MouseBitNum >= 1) && (MouseBitNum <= 8)) { //8 data bits, least significant bit first.
				MouseBitNum++;
				MouseDataReg >>= 1;
				if (dataLine) MouseDataReg |= 0x80;
			} else if (MouseBitNum == 9) { //1 parity bit (odd parity).
				MouseBitNum++;
				if (!ParityCheckOdd(dataLine)) {
					MSCommReset();
				}
			} else if (MouseBitNum == 10) { //1 stop bit.  This is always 1.
				if (dataLine) { //данные получены
					if (MouseByteNum < sizeof(MouseData)) {
						MouseData[MouseByteNum] = MouseDataReg;
						MouseByteNum++;
					}
				}
				MouseBitNum = 0;
			}
		} else {
			if (MouseBitNum < 9) {  				//8 data bits, least significant bit first.
				MouseData_WriteRee(MouseDataReg & 0x01);
				MouseDataReg >>= 1;
			} else if (MouseBitNum == 9) {  //1 parity bit (odd parity).
				MouseDataReg = MouseData[0];
				if (ParityCheckOdd(TRUE)) MouseData_WriteRee(0x01);
				else MouseData_WriteRee(0x00);
			} else  if (MouseBitNum == 10) {  //1 stop bit.  This is always 1.			
				MouseData_WriteRee(0x01);
			} else {			//check ACK
				if (dataLine) { //нет ACK от устройства
                    MouseState(FALSE);
				}
				MouseBitNum = 0xFF;
				MouseMode &= ~MSMode_RXTXMask;
			}
			MouseBitNum++;
		}
		MouseLastActTick = GetTickCount();        
	}
	MouseClk_ClearInterrupt();
}


void MouseModeToRecieve(void) {
	MouseMode &= ~MSMode_RXTXMask;
}

void MouseTransmit(BYTE Data) {
	MouseISR_Disable();
	MouseData[0] = Data;
	MouseDataReg = Data;
	MouseByteNum = 0x00;
	MouseBitNum = 0x01;
	MouseMode |= MSMode_TX;
	MouseClk_Write(0);  //1)   Bring the Clock line low for at least 100 microseconds.
	CyDelayUs(100);
	MouseData_WriteRee(0); //2)   Bring the Data line low.
	MouseClk_Write(1);  //3)   Release the Clock line.		
	MouseISR_Enable();  //4)   Wait for the device to bring the Clock line low.
						//	MouseClk_ClearInterrupt();
}

#define MSMode_StateSET(STATE) {MouseMode = (MouseMode & ~MSMode_StateMask) | STATE;}
#define MSMode_StateGET (MouseMode & MSMode_StateMask)
#define MSMode_RXByteReady(MinCount) ((MouseByteNum >= MinCount) && (SysClk_GetPeriod(MouseLastAct) > MSFrame_DelayMs))

void InitMouse() {
    MouseState(FALSE);
	MSMode_StateSET(MSMode_StateReset);
	MouseMode |= MSMode_TX;
	MouseBitNum = 0x00;
	MouseISR_StartEx(MouseIrqHandler);
}

BOOL MouseStateMachine(BYTE TXData, BYTE ExpectRXAnswer_0, BYTE ExpectRXMinCount, BYTE NextState, DWORD ATimeOut) {
	DWORD ActPeriod = GetElapsedPeriod(MouseLastActTick);
	if ((MouseMode & MSMode_RXTXMask) == MSMode_TX) {
		if (MouseBitNum == 0) {
			MouseTransmit(TXData);
		} else if (ActPeriod > SYSTICK_mS(1000)) {
			MSMode_StateSET(MSMode_StateReset);
			MouseMode |= MSMode_TX;
			MouseBitNum = 0x00;
			MouseLastActTick = GetTickCount();
		}
	} else {
		if ((MouseByteNum >= ExpectRXMinCount) /*&& (ActPeriod >= SYSTICK_mS(MSFrame_DelayMs))*/) {
			if (MouseData[0] == ExpectRXAnswer_0) {
				MSMode_StateSET(NextState);
				MouseMode |= MSMode_TX;
				return (TRUE);
			} else {
				MSMode_StateSET(MSMode_StateReset);
				MouseMode |= MSMode_TX;
				MouseBitNum = 0x00;
			}
		} else if (ActPeriod > SYSTICK_mS(ATimeOut)) {
			MSMode_StateSET(MSMode_StateReset);
			MouseMode |= MSMode_TX;
			MouseBitNum = 0x00;
		}
	}
	return (FALSE);
}

BOOL MouseHandler(PINT pX, PINT pY) {
	static DWORD mouseTick = 0;
    if (MainWorkObj.MousePresent) {
    	if (GetElapsedPeriod(mouseTick) < SYSTICK_mS(50)){  //период опроса мыши 50мс
            return FALSE; 
        }
    } else {
    	if (GetElapsedPeriod(mouseTick) < SYSTICK_mS(500)){ 
            return FALSE; 
        }  
    }
    mouseTick = GetTickCount();
BOOL res = FALSE;        
	if (MSMode_StateGET == MSMode_StateReset) {
		if (MouseStateMachine(0xFF, 0xFA, 1, MSMode_StateSetSampleRate0Cmd, 1000)) {
            MouseState(TRUE);
		} else {
            MouseState(FALSE);
        }
	} else if (MSMode_StateGET == MSMode_StateSetSampleRate0Cmd) {  //Intellimouse Установить частоту дискретизации =200
		MouseStateMachine(0xF3, 0xFA, 1, MSMode_StateSetSampleRate0Val, 100);
	} else if (MSMode_StateGET == MSMode_StateSetSampleRate0Val) {
		MouseStateMachine(200, 0xFA, 1, MSMode_StateSetSampleRate1Cmd, 100);
	} else if (MSMode_StateGET == MSMode_StateSetSampleRate1Cmd) {  //Установить частоту дискретизации =100
		MouseStateMachine(0xF3, 0xFA, 1, MSMode_StateSetSampleRate1Val, 100);
	} else if (MSMode_StateGET == MSMode_StateSetSampleRate1Val) {
		MouseStateMachine(100, 0xFA, 1, MSMode_StateSetSampleRate2Cmd, 100);
	} else if (MSMode_StateGET == MSMode_StateSetSampleRate2Cmd) {  //Установить частоту дискретизации =80
		MouseStateMachine(0xF3, 0xFA, 1, MSMode_StateSetSampleRate2Val, 100);
	} else if (MSMode_StateGET == MSMode_StateSetSampleRate2Val) {
		MouseStateMachine(80, 0xFA, 1, MSMode_StateGetdeviceID, 100);
	} else if (MSMode_StateGET == MSMode_StateGetdeviceID) {
		if (MouseStateMachine(0xF2, 0xFA, 2, MSMode_SetRemoteMode, 100)) {
			if (MouseData[1] != 0x03) {  //если будет подключена Microsoft Intellimouse, то она ответит ID =0×03.
				MSMode_StateSET(MSMode_StateReset);
				MouseMode |= MSMode_TX;
				MouseBitNum = 0x00;
				MouseState(FALSE);
			} else {
				MouseState(TRUE);
			}
		} else {
            MouseState(FALSE);    
        }
	} else if (MSMode_StateGET == MSMode_SetRemoteMode) {
		MouseStateMachine(0xF0, 0xFA, 1, MSMode_StateSetSampleRate3Cmd, 100);
	} else if (MSMode_StateGET == MSMode_StateSetSampleRate3Cmd) {  //Установить частоту дискретизации =100
		MouseStateMachine(0xF3, 0xFA, 1, MSMode_StateSetSampleRate3Val, 100);
	} else if (MSMode_StateGET == MSMode_StateSetSampleRate3Val) {
		MouseStateMachine(100, 0xFA, 1, MSMode_ReadData, 100);
	} else if (MSMode_StateGET == MSMode_ReadData) {
		if (MouseStateMachine(0xEB, 0xFA, 5, MSMode_ReadData, 200)) {
			BYTE msDt = MouseData[1];
			INT i8 = (int8)MouseData[4];
			if (MainWorkObj.State != mwsStart && MainWorkObj.State != mwsInit) {
                if (i8 != 0) {
                    if (msDt & 0x01) i8 =  i8 * 100; //BtnLeft;
    				else if (msDt & 0x02) i8 =  i8 * 10; //MSS_MSBtnRight;
                    else i8 =  i8 * 5;
                    MouseChangingValue(i8);
                    res = TRUE;
                }
                
				if ((msDt & 0x04) != MouseMidBtn) {
					MouseMidBtn = (msDt & 0x04);
					if (MouseMidBtn) {
						if (MainWorkObj.State == mwsErrGlb) {
							ResetErrorState();
						} else {
							if ((O_OUT_ON_Read() == 0) && (msDt & 0x02)) { //MSS_MSBtnRight; при включении выхода, правой кнопкой блокировать защиту	
								SuppressProtection(TRUE);
							} else {
								SuppressProtection(FALSE);
							}
							ChangeOutputState();
						}
                        res = TRUE;
					}
				}
				if (MainWorkObj.HwPrSupressed && ((msDt & 0x02) == 0) /*&& (OUT_ON_R_Read() != 0)*/) { //MSS_MSBtnRight; 
					SuppressProtection(FALSE);
				}
                if (pX != NULL && pY != NULL) {
                    INT x, y;
                    x = MouseData[2];           
                    y = MouseData[3];                   
                    if (msDt & 0x10) {
                        x = x * -1;
                    }  
                    if (msDt & 0x20) {
                        y = y * -1;
                    }   
                    *pX = x;
                    *pY = y;
                }
			}
		}
	}
    return res;
}