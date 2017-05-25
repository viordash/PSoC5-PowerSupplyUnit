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

#include <device.h>
#include <stdlib.h>
#include <string.h>
#include "Display\LCD_T6963.h"
#include "LCD_Display.h"

#define T6963_HOR_DOTS 240
#define T6963_VER_DOTS 128

#define T6963_TIME_ACCESS (150 - 100)  /*время ожидания при чтении данных, мкС*/
#define T6963_TIME_WRITE (80 - 50)   /*время ожидания при записи данных, мкС*/
#define T6963_TIMEOUT_MS 100  /*таймаут ожидания статуса*/

#define T6963_CMD__SET_CURSOR_POS 0x21
#define T6963_CMD__SET_ADRESS_PTR 0x24
#define T6963_CMD__SET_DATA_AUTO_WRITE 0xB0
#define T6963_CMD__SET_DATA_AUTO_RESET 0xB2
#define T6963_CMD__SET_MODE_OR 0x80
#define T6963_CMD__SET_MODE_XOR 0x81
#define T6963_CMD__SET_MODE_AND 0x83
#define T6963_CMD__SET_TEXT_HOME_ADR 0x40
#define T6963_CMD__SET_TEXT_AREA 0x41
#define T6963_CMD__SET_GRPH_HOME_ADR 0x42
#define T6963_CMD__SET_GRPH_AREA 0x43
#define T6963_CMD__CURSOR_1_LINE 0xA0
#define T6963_CMD__CURSOR_2_LINE 0xA1
#define T6963_CMD__CURSOR_3_LINE 0xA2
#define T6963_CMD__CURSOR_4_LINE 0xA3
#define T6963_CMD__CURSOR_5_LINE 0xA4
#define T6963_CMD__CURSOR_6_LINE 0xA5
#define T6963_CMD__CURSOR_7_LINE 0xA6
#define T6963_CMD__CURSOR_8_LINE 0xA7
#define T6963_CMD__DSPL_MODE_ALL 0x9F		 
#define T6963_CMD__DSPL_MODE_GRPH 0x98		
#define T6963_CMD__DSPL_OFF 0x90

#define T6963_FONT_WIDTH 8	/*ширина символа в битах у выбранного шрифта*/
#define T6963_GRPHIC_HOME 0x0000 /*((T6963_RAM_END / 2) + 1)	*/
#define T6963_GRPHIC_AREA ((T6963_HOR_DOTS / T6963_FONT_WIDTH) + 0)	/*(240 hor. dot / T6963_FONT_WIDTH) + 1 = 40 char per line*/

#define T6963_LCD_MAX_ROW (T6963_VER_DOTS / 8)	//максимум рядов по вертикали

#define T6963_DataPortToInput() LCD_DB_Write(0xFF)
#define T6963_DataPortToOutput() /*LCD_T6963_DB_PORT->MODER  |= (GPIO_MODER_MODER8_0 | GPIO_MODER_MODER9_0 | GPIO_MODER_MODER10_0 | GPIO_MODER_MODER11_0 | GPIO_MODER_MODER12_0 | \
	GPIO_MODER_MODER13_0 | GPIO_MODER_MODER14_0 | GPIO_MODER_MODER15_0);*/

#define T6963_RD  LCD_T6963_RD_GPIO_PIN
#define T6963_WR  LCD_T6963_WR_GPIO_PIN
#define T6963_CD  LCD_T6963_CD_GPIO_PIN

#define T6963_Write_DB(AValue) {LCD_T6963_DB_PORT->ODR = (LCD_T6963_DB_PORT->ODR & 0x00FF | ((BYTE)AValue << 8) & 0xFF00);}		

#define T6963_Write_WR_RD_CD(AValue) {LCD_T6963_WR_RD_CD_PORT->ODR = (LCD_T6963_WR_RD_CD_PORT->ODR & 0x1FFF) | (AValue & (T6963_WR|T6963_RD|T6963_CD));}	

#define T6963_DefaultPinState(AValue) {LCD_DB_Write(0xFF); O_LCD_RD_Write(TRUE); O_LCD_WR_Write(TRUE);}
#define COMMAND TRUE
#define DATA FALSE

typedef enum {
    dtData = FALSE,
	dtCommand = TRUE
} DataType;	 

TDisplay Display;
BOOL initialized = FALSE;

void Delay_nS(x) {
    DWORD i = ((1000 / BCLK__BUS_CLK__MHZ ) * (x / 10));  
    CyDelayCycles(i);
} //задержка в nS

BYTE T6963_Read(DataType dataType) { 
	T6963_DataPortToInput(); 
    O_LCD_CD_Write(dataType); 
    O_LCD_RD_Write(FALSE); 
	Delay_nS(T6963_TIME_ACCESS); 
    O_LCD_RD_Write(TRUE); 
	return((BYTE)LCD_DB_Read()); 
}

void T6963_Write(BYTE value, DataType dataType) { 
	T6963_DataPortToOutput(); 
    LCD_DB_Write(value);
    O_LCD_CD_Write(dataType); 
    O_LCD_WR_Write(FALSE); 
	Delay_nS(T6963_TIME_WRITE); 
    O_LCD_WR_Write(TRUE); 
}


BOOL T6963_Busy(void) {
	BYTE bt;
	DWORD T6963_Timeout = GetTickCount() + T6963_TIMEOUT_MS;
	while (TRUE) {
		bt = T6963_Read(dtCommand);
		if ((bt & 0x03) == 0x03) return (TRUE);  //STA0 и STA1
		if (GetTickCount() > T6963_Timeout) return (FALSE);
	}
}

BOOL T6963_StatusAutoWrite(void) {
	BYTE bt;
	DWORD T6963_Timeout = GetTickCount() + T6963_TIMEOUT_MS;
	while (TRUE) {
		bt = T6963_Read(dtCommand);
		if ((bt & 0x08) == 0x08) return (TRUE);  //STA3
		if (GetTickCount() > T6963_Timeout) return (FALSE);
		//	Delay_uS(10);
			Display_TaskSleepZero();
	}
}

void _LCD_Init() {
    O_LCD_BKL_Write(FALSE);

	T6963_DefaultPinState(0xFF);
	_LCD_Reset();
	Display_TaskSleep(100);        //задержка в 100mS

	if (!T6963_Busy()) return;
	T6963_Write(T6963_CMD__SET_MODE_XOR, dtCommand);	// "OR" mode			

	if (!T6963_Busy()) return;
	T6963_Write((BYTE)T6963_GRPHIC_HOME, dtData); 	//graphic home low adres
	if (!T6963_Busy()) return;
	T6963_Write((T6963_GRPHIC_HOME >> 8), dtData);	//graphic home high adres
	if (!T6963_Busy()) return;
	T6963_Write(T6963_CMD__SET_GRPH_HOME_ADR, dtCommand);	//graphic home command

	if (!T6963_Busy()) return;
	T6963_Write(T6963_GRPHIC_AREA, dtData); 	//graphic area
	if (!T6963_Busy()) return;
	T6963_Write(0, dtData);
	if (!T6963_Busy()) return;
	T6963_Write(T6963_CMD__SET_GRPH_AREA, dtCommand);	//graphic area command  

	_LCD_SetFont(1);
	_LCD_SetCursorPos(0, 0);
	_LCD_Clear();
	_LCD_Enable();
    
	initialized = TRUE; 
}	

void _LCD_WaitReady() {
	while (!initialized)Display_TaskSleep(1);
}

void _LCD_Reset(void) {
    O_LCD_RES_Write(FALSE);
	Display_TaskSleep(5);
    O_LCD_RES_Write(TRUE);
}

void _LCD_Clear(void) {
	INT i;
	//Set adress pointer     
	if (!T6963_Busy()) return;
	T6963_Write((BYTE)T6963_GRPHIC_HOME, dtData);       //Low adress
	if (!T6963_Busy()) return;
	T6963_Write((T6963_GRPHIC_HOME >> 8), dtData);       //High adress
	if (!T6963_Busy()) return;
	T6963_Write(T6963_CMD__SET_ADRESS_PTR, dtCommand);   //Поместить в указатель адреса значение 0
	if (!T6963_Busy()) return;

	T6963_Write(T6963_CMD__SET_DATA_AUTO_WRITE, dtCommand);   //Включение режима автозаписи

	for (i = 0; i < (T6963_GRPHIC_AREA * T6963_VER_DOTS); i++) {
		if (!T6963_StatusAutoWrite()) return;
		T6963_Write(0x00, dtData);
	}
	if (!T6963_StatusAutoWrite()) return;
	T6963_Write(T6963_CMD__SET_DATA_AUTO_RESET, dtCommand);   //Выключение режима автозаписи
}

BOOL _LCD_DrawPixel(BYTE ACoordX, BYTE ACoordY, BOOL APixelVal) {
	INT i;
	BYTE ch;
	ch = ACoordX / T6963_FONT_WIDTH;
	i = T6963_GRPHIC_HOME + (T6963_GRPHIC_AREA * ACoordY) + ch;
	ch = ACoordX - (ch * T6963_FONT_WIDTH);  //остаток от деления ACoordX / T6963_FONT_WIDTH. Номер бита
	ch = (T6963_FONT_WIDTH - 1) - ch;//номер бита перевернуть с начала на конец. И ch привести к виду комманды BOOL SET/RESET
	ch |= 0xF8;
	if (!APixelVal) ch &= 0xF7;	//установить или сбросить бит

	if (!T6963_Busy()) return(FALSE);
	T6963_Write(i, dtData);
	if (!T6963_Busy()) return(FALSE);
	T6963_Write((i >> 8), dtData);
	if (!T6963_Busy()) return(FALSE);
	T6963_Write(T6963_CMD__SET_ADRESS_PTR, dtCommand);	//Поместить в указатель адреса значение

	if (!T6963_Busy()) return(FALSE);
	T6963_Write(ch, dtCommand);	//Изменить бит
	return (TRUE);
}

void T6963_DrawVertPixels(WORD ACoordX, WORD ACoordY, BYTE APixelVal) {
	if (ACoordX >= T6963_HOR_DOTS) {
		return;
	}
	_LCD_DrawPixel(ACoordX, ACoordY + 0, APixelVal & 0x01);
	_LCD_DrawPixel(ACoordX, ACoordY + 1, APixelVal & 0x02);
	_LCD_DrawPixel(ACoordX, ACoordY + 2, APixelVal & 0x04);
	_LCD_DrawPixel(ACoordX, ACoordY + 3, APixelVal & 0x08);
	_LCD_DrawPixel(ACoordX, ACoordY + 4, APixelVal & 0x10);
	_LCD_DrawPixel(ACoordX, ACoordY + 5, APixelVal & 0x20);
	_LCD_DrawPixel(ACoordX, ACoordY + 6, APixelVal & 0x40);
	_LCD_DrawPixel(ACoordX, ACoordY + 7, APixelVal & 0x80);
}

BOOL T6963_DrawLine(BYTE ACoordX1, BYTE ACoordY1, BYTE ACoordX2, BYTE ACoordY2, BOOL APixelVal) {
	WORD ishf;
	BYTE i;
	BYTE shf;
	SHORT delX = ACoordX2 - ACoordX1;
	SHORT delY = ACoordY2 - ACoordY1;
	SHORT dirX = 0;
	SHORT dirY = 0;

	if (delX < 0) { dirX = -1; delX = delX * dirX; } else if ((BYTE)delX != 0) dirX = 1;
	if (delY < 0) { dirY = -1; delY = delY * dirY; } else if ((BYTE)delY != 0) dirY = 1;

	if (delY > delX) {
		i = delY + 1;
		do {
			ishf = (BYTE)delX * (BYTE)(i - 1);
			shf = (ishf + (delY / 2)) / delY;
			_LCD_DrawPixel((char)ACoordX1 + (shf * dirX), (char)ACoordY1 + ((i - 1) * dirY), APixelVal);
		} while (--i != 0);
	} else {
		i = delX + 1;
		do {
			ishf = (BYTE)delY * (BYTE)(i - 1);
			shf = (ishf + (delX / 2)) / delX;
			_LCD_DrawPixel((char)ACoordX1 + ((i - 1) * dirX), (char)ACoordY1 + (shf * dirY), APixelVal);
		} while (--i != 0);
	}
	return (TRUE);
}

BOOL T6963_DrawRectangle(BYTE ACoordX1, BYTE ACoordY1, BYTE ACoordX2, BYTE ACoordY2, BOOL APixelVal) {
	if (!T6963_DrawLine(ACoordX1, ACoordY1, ACoordX2, ACoordY1, APixelVal)) return(FALSE);
	if (!T6963_DrawLine(ACoordX2, ACoordY1, ACoordX2, ACoordY2, APixelVal)) return(FALSE);
	if (!T6963_DrawLine(ACoordX2, ACoordY2, ACoordX1, ACoordY2, APixelVal)) return(FALSE);
	if (!T6963_DrawLine(ACoordX1, ACoordY2, ACoordX1, ACoordY1, APixelVal)) return(FALSE);
	return (TRUE);
}

BOOL T6963_FillRectangle(BYTE ACoordX1, BYTE ACoordY1, BYTE ACoordX2, BYTE ACoordY2, BOOL APixelVal) {
	BYTE i;
	SHORT delX = (CHAR)ACoordX2 - (CHAR)ACoordX1;
	CHAR dirX;
	if (delX < 0) dirX = -1; else dirX = 1;
	delX = delX * dirX;
	i = delX + 1;
	do {
		T6963_DrawLine(ACoordX1, ACoordY1, ACoordX1, ACoordY2, APixelVal);
		ACoordX1 += dirX;
	} while (--i != 0);
	return (TRUE);
}

void _LCD_Enable(void) {
    O_LCD_BKL_Write(TRUE);
	if (!T6963_Busy()) return;
	T6963_Write(T6963_CMD__DSPL_MODE_GRPH, dtCommand);	//Text off, graphic on
}

void _LCD_Sleep(void) {
    O_LCD_BKL_Write(FALSE);
	if (!T6963_Busy()) return;
	T6963_Write(T6963_CMD__DSPL_OFF, dtCommand);	//Text off, graphic off
}

void _LCD_ClearLine(BYTE Line) {
	PCHAR data;
	_LCD_SetCursorPos(Line * (8 * Display.font->height), 0);
	PFONT_CHAR_INFO p_character_descriptor = (PFONT_CHAR_INFO)&(Display.font->p_character_descriptor[' ' - Display.font->start_char]);
	INT width = (T6963_HOR_DOTS / (p_character_descriptor->width + Display.font->separatorWidth));
	data = malloc(width + 1);
	if (data == NULL) {
		return;
	}
	memset(data, ' ', width);
	_LCD_Print(data, width);
	free(data);
}

void _LCD_SetCursorPos(WORD ACoordX, WORD ACoordY) {
	Display.coordY = ACoordY;
	Display.coordX = ACoordX;
}

void _LCD_PrintChar(CHAR ch) {
	CHAR data[] = {ch, 0};
	_LCD_Print(data, 1);
}

void _LCD_Print(PCHAR buffer, INT size) {
	INT height;
	WORD coordY = Display.coordY;
	if (size == 0) {
		return;
	}
	if (size < 0) {
		size = strlen(buffer);
	}
	PCHAR pStringEnd = buffer + size;
	for (height = 0; height < Display.font->height; height++) {
		PCHAR pString = buffer;
		CHAR ch;
		WORD coordX = Display.coordX;
		while (pString < pStringEnd) {
			ch = *pString++;
			if (ch == 0x0D || ch == 0x0A) {
				pStringEnd = pString;
				ch = *pString;
				if (ch == 0x0D || ch == 0x0A) {
					pString++;
				}
				if (height == 0) {
					Display.coordY += (8 * Display.font->height);
					_LCD_Print(pString, size - (pString - buffer));
				}
				break;
			}
			if ((ch < Display.font->start_char) || (ch > Display.font->end_char)) {
				return;
			}
			PFONT_CHAR_INFO p_character_descriptor = (PFONT_CHAR_INFO)&(Display.font->p_character_descriptor[ch - Display.font->start_char]);
			INT width = p_character_descriptor->width; // Character width in bits.
			PBYTE pBuffer = (PBYTE)(Display.font->p_character_bitmaps + p_character_descriptor->offset + (height * width));

			while (width-- > 0) {
				T6963_DrawVertPixels(coordX++, coordY, *(pBuffer++));
			}

			if (ch > ' ') {
				width = Display.font->separatorWidth; //space between chars		  
				while (width-- > 0) {
					T6963_DrawVertPixels(coordX++, coordY, 0x00);
				}
			}
		}
		coordY += 8;
	};
}

void _LCD_SetFont(INT size) {
	if (size == 1) {
		Display.font = (PFONT_INFO)&font_1FontInfo;
	} else if (size == 2) {
		Display.font = (PFONT_INFO)&font_2FontInfo;
	} else if (size == 3) {
		Display.font = (PFONT_INFO)&font_3FontInfo;
	} else {
		Display.font = (PFONT_INFO)&font_0FontInfo;
	}
}

/* [] END OF FILE */
