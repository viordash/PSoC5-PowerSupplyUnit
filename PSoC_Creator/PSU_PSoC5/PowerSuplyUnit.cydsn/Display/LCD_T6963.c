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


#define T6963_TIME_ACCESS (150 - 50)  /*время ожидания при чтении данных, мкС*/
#define T6963_TIME_WRITE (80 - 0)   /*время ожидания при записи данных, мкС*/
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


#define T6963_DataPortToInput() {LCD_DB_OutEnable_Write(FALSE);}/*T6963_Write_DB(0xFF)*/
#define T6963_DataPortToOutput() {LCD_DB_OutEnable_Write(TRUE);}/**/

#define T6963_Write_DB(x) {LCD_DB_DR = x;}	
#define T6963_Read_DB() ((BYTE)LCD_DB_PS)	

#define T6963_Write_WR(x) {if (x) {O_LCD_WR_DR |= O_LCD_WR_MASK;} else {O_LCD_WR_DR &= ~O_LCD_WR_MASK;}}	
#define T6963_Write_RD(x) {if (x) {O_LCD_RD_DR |= O_LCD_RD_MASK;} else {O_LCD_RD_DR &= ~O_LCD_RD_MASK;}}	
#define T6963_Write_CD(x) {if (x) {O_LCD_CD_DR |= O_LCD_CD_MASK;} else {O_LCD_CD_DR &= ~O_LCD_CD_MASK;}}	

#define T6963_DefaultPinState(AValue) {T6963_DataPortToInput(); T6963_Write_WR(TRUE); T6963_Write_RD(TRUE);}
#define COMMAND TRUE
#define DATA FALSE
#define STATUS_BUSY 0x03
#define STATUS_AUTO_WRITE 0x08

typedef enum {
    dtData = FALSE,
	dtCommand = TRUE
} DataType;	 

TDisplay Display;
BOOL initialized = FALSE;

BYTE T6963_Read(DataType dataType) { 
	T6963_DataPortToInput(); 
    T6963_Write_CD(dataType); 
    T6963_Write_RD(FALSE); 
	Display_TaskSleepZero(); 
    T6963_Write_RD(TRUE); 
	return(T6963_Read_DB()); 
}

void T6963_Write(BYTE value, DataType dataType, BYTE statusMask) { 
	DWORD T6963_Timeout = GetTickCount() + T6963_TIMEOUT_MS;
  	while ((T6963_Read(dtCommand) & statusMask) != statusMask) {
  		if (GetTickCount() > T6963_Timeout) return;
        Display_TaskSleepZero();
  	}
    T6963_DataPortToOutput();
    T6963_Write_DB(value);
    T6963_Write_CD(dataType); 
    T6963_Write_WR(FALSE); 
	Display_TaskSleepZero(); 
    T6963_Write_WR(TRUE); 
}

void _LCD_Init() {
    O_LCD_BKL_Write(FALSE);

	T6963_DefaultPinState(0xFF);
	_LCD_Reset();
	Display_TaskSleep(100);        //задержка в 100mS
    Display.GraphicHome = 0x0000;
	T6963_Write(T6963_CMD__SET_MODE_XOR, dtCommand, STATUS_BUSY);	// "OR" mode			
    
	T6963_Write((BYTE)T6963_GRPHIC_HOME, dtData, STATUS_BUSY); 	//graphic home low adres
	T6963_Write((T6963_GRPHIC_HOME >> 8), dtData, STATUS_BUSY);	//graphic home high adres
	T6963_Write(T6963_CMD__SET_GRPH_HOME_ADR, dtCommand, STATUS_BUSY);	//graphic home command

	T6963_Write(T6963_GRPHIC_AREA, dtData, STATUS_BUSY); 	//graphic area
	T6963_Write(0, dtData, STATUS_BUSY);
	T6963_Write(T6963_CMD__SET_GRPH_AREA, dtCommand, STATUS_BUSY);	//graphic area command  

    Display.GraphicBuffer = malloc(T6963_GRPHIC_AREA * T6963_VER_DOTS);    
	_LCD_SetFont(1);
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

void _LCD_Flush(void) { 
    Display.GraphicHome++;
    if (Display.GraphicHome > (19200 / (T6963_GRPHIC_AREA * T6963_VER_DOTS))) {
        Display.GraphicHome = 0;
    }
    WORD graphicHome = Display.GraphicHome * (T6963_GRPHIC_AREA * T6963_VER_DOTS);
	 
	T6963_Write((BYTE)graphicHome, dtData, STATUS_BUSY);       //Low adress
	T6963_Write((graphicHome >> 8), dtData, STATUS_BUSY);       //High adress
	T6963_Write(T6963_CMD__SET_ADRESS_PTR, dtCommand, STATUS_BUSY);   //Set adress pointer

	T6963_Write(T6963_CMD__SET_DATA_AUTO_WRITE, dtCommand, STATUS_BUSY);   //Включение режима автозаписи
    DWORD i;
	for (i = 0; i < (T6963_GRPHIC_AREA * T6963_VER_DOTS); i++) {
		T6963_Write(Display.GraphicBuffer[i], dtData, STATUS_AUTO_WRITE);
	}
	T6963_Write(T6963_CMD__SET_DATA_AUTO_RESET, dtCommand, STATUS_AUTO_WRITE);   //Выключение режима автозаписи    
    
	T6963_Write((BYTE)graphicHome, dtData, STATUS_BUSY); 	//graphic home low adres
	T6963_Write((graphicHome >> 8), dtData, STATUS_BUSY);	//graphic home high adres
	T6963_Write(T6963_CMD__SET_GRPH_HOME_ADR, dtCommand, STATUS_BUSY);	//graphic home command
}

void _LCD_Clear(void) {
    memset(Display.GraphicBuffer, 0x00, T6963_GRPHIC_AREA * T6963_VER_DOTS);
    _LCD_Flush();
}

void _LCD_DrawPixel(BYTE coordX, BYTE coordY, BOOL value) {
    INT posX = coordX / 8;
    INT posY = coordY * (T6963_HOR_DOTS / T6963_FONT_WIDTH);
    PBYTE pGraphicBuffer = &(Display.GraphicBuffer[posY + posX]);
	BYTE bt = 0x80 >> (coordX % 8);
    if (value) {
        *pGraphicBuffer |= bt;
    } else {
        *pGraphicBuffer &= ~bt;
    }
}

void _LCD_DrawLine(BYTE coordX1, BYTE coordY1, BYTE coordX2, BYTE coordY2, TLineType lineType, BOOL flush) {
    WORD ishf;
	BYTE i;
	BYTE shf;
	SHORT delX = coordX2 - coordX1;
	SHORT delY = coordY2 - coordY1;
	SHORT dirX = 0;
	SHORT dirY = 0;
    BYTE lineValue;
    if (lineType == ltDoted) {
        lineValue = 1;
    } else if (lineType == ltDashed) {
        lineValue = 8;
    } else {
        lineValue = 0xFF;
    }

	if (delX < 0) { dirX = -1; delX = delX * dirX; } else if ((BYTE)delX != 0) dirX = 1;
	if (delY < 0) { dirY = -1; delY = delY * dirY; } else if ((BYTE)delY != 0) dirY = 1;

	if (delY > delX) {
		i = delY + 1;
		do {
			ishf = (BYTE)delX * (BYTE)(i - 1);
			shf = (ishf + (delY / 2)) / delY;
			_LCD_DrawPixel((char)coordX1 + (shf * dirX), (char)coordY1 + ((i - 1) * dirY), i & lineValue);
		} while (--i != 0);
	} else {
		i = delX + 1;
		do {
			ishf = (BYTE)delY * (BYTE)(i - 1);
			shf = (ishf + (delX / 2)) / delX;
			_LCD_DrawPixel((char)coordX1 + ((i - 1) * dirX), (char)coordY1 + (shf * dirY), i & lineValue);
		} while (--i != 0);
	}
    if (flush) {
        _LCD_Flush();
    }
}

void _LCD_DrawRectangle(BYTE coordX1, BYTE coordY1, BYTE coordX2, BYTE coordY2, TLineType lineType, BOOL flush) {
	_LCD_DrawLine(coordX1, coordY1, coordX2, coordY1, lineType, FALSE);
	_LCD_DrawLine(coordX2, coordY1, coordX2, coordY2, lineType, FALSE);
	_LCD_DrawLine(coordX2, coordY2, coordX1, coordY2, lineType, FALSE);
	_LCD_DrawLine(coordX1, coordY2, coordX1, coordY1, lineType, FALSE);    
    if (flush) {
        _LCD_Flush();
    }
}

void _LCD_FillRectangle(BYTE coordX1, BYTE coordY1, BYTE coordX2, BYTE coordY2, TLineType lineType, BOOL flush) {
	BYTE i;
	SHORT delX = (CHAR)coordX2 - (CHAR)coordX1;
	CHAR dirX;
	if (delX < 0) dirX = -1; else dirX = 1;
	delX = delX * dirX;
	i = delX + 1;
	do {
		_LCD_DrawLine(coordX1, coordY1, coordX1, coordY2, lineType, FALSE);
		coordX1 += dirX;
	} while (--i != 0);    
    if (flush) {
        _LCD_Flush();
    }
}

void _LCD_Enable(void) {
    O_LCD_BKL_Write(TRUE);
	T6963_Write(T6963_CMD__DSPL_MODE_GRPH, dtCommand, STATUS_BUSY);	//Text off, graphic on
}

void _LCD_Sleep(void) {
    O_LCD_BKL_Write(FALSE);
	T6963_Write(T6963_CMD__DSPL_OFF, dtCommand, STATUS_BUSY);	//Text off, graphic off
}

void PutDataInGraphicBuffer(PBYTE pCharBitmap, INT width, INT posY, INT shiftX, TTextColor color) {
    BYTE posX = shiftX / 8;
    BYTE posShift = shiftX % 8;
    BYTE posShiftBack = 8 - posShift;
    BYTE headerMask = 0xFF << posShiftBack;
    BYTE bt = width + shiftX;
    BYTE taleMask = 0xFF >> (bt % 8);
    if (taleMask == 0xFF) {
        taleMask = 0;
    }
    BOOL addByteInGraphicBuffer =  ((posShift + width - 1) / 8) > ((width - 1) / 8);
    BYTE remain = 0;
    BYTE charPosX = 0;
    PBYTE pGraphicBuffer = NULL;
	while (width > 0) {
        bt = *pCharBitmap;
        if (color == tcInvert) {
            bt = ~bt;
            if (width < 8) {
                BYTE mask = 0xFF >> width;
                bt &= ~mask;
            }
        } else if (color == tcInvisible) {
            bt = 0;
        }
        DWORD data = bt << 8;  
        data |= (remain << 16);
        data = data >> posShift;        
        remain = (data & 0x000000FF) >> posShiftBack;
        pGraphicBuffer = &(Display.GraphicBuffer[posY + posX + charPosX]);
		bt = headerMask;
        headerMask = 0;    
        charPosX++;    
        if (width <= 8) {
            if (!addByteInGraphicBuffer) {
                bt |= taleMask;
            }
            width = 0;
        } else {
           width -= 8;  
        }
        bt = *pGraphicBuffer & bt;
        *pGraphicBuffer = bt | ((data >> 8) & 0x000000FF);
        pCharBitmap++;
	}
    if (addByteInGraphicBuffer) {
        pGraphicBuffer = &(Display.GraphicBuffer[posY + posX + charPosX]);
        bt = *pGraphicBuffer & taleMask;
        *pGraphicBuffer = bt | (remain << posShiftBack);
    }
}

BYTE _LCD_Print(PCHAR buffer, TTextColor color, BYTE coordX, BYTE coordY, BOOL flush) { //return shift X coord
	INT height;
    INT size = strlen(buffer);
	INT posY = coordY * (T6963_HOR_DOTS / T6963_FONT_WIDTH);
	PCHAR pStringEnd = buffer + size; 
    INT shiftX = 0;
    for (height = 0; height < Display.font->height; height++) {
        shiftX = coordX;
        PCHAR pString = buffer;
        CHAR ch;
        while (pString < pStringEnd) {
            ch = *pString++;
			if ((ch < Display.font->start_char) || (ch > Display.font->end_char)) {
				return 0;
			}    
            
            PFONT_CHAR_INFO p_character_descriptor = (PFONT_CHAR_INFO)&(Display.font->p_character_descriptor[ch - Display.font->start_char]);
			INT width = p_character_descriptor->width; // Character width in bits.
            PBYTE pBuffer = (PBYTE)(Display.font->p_character_bitmaps + p_character_descriptor->offset + (height * (((width - 1) / 8) + 1)));
            PutDataInGraphicBuffer(pBuffer, width, posY, shiftX, color);
            shiftX += width;
			if ((ch > ' ') && (pString < pStringEnd)) {
                width = Display.font->separatorWidth; //space between chars	
                BYTE spaceChars[8] = {0};
                PutDataInGraphicBuffer(spaceChars, width, posY, shiftX, color);
                shiftX += width;
			}         
        }
        posY += (T6963_HOR_DOTS / T6963_FONT_WIDTH);
    }  
    if (flush) {
        _LCD_Flush();
    }
    return shiftX;
}

void _LCD_SetFont(INT size) {
	if (size == 1) {
		Display.font = (PFONT_INFO)&font_1FontInfo;
	} else if (size == 2) {
		Display.font = (PFONT_INFO)&font_2FontInfo;
	} else if (size == 3) {
		Display.font = (PFONT_INFO)&font_3FontInfo;
	} else if (size == 4) {
		Display.font = (PFONT_INFO)&font_4FontInfo;
	}  else {
		Display.font = (PFONT_INFO)&font_0FontInfo;
	}
}

/* [] END OF FILE */
