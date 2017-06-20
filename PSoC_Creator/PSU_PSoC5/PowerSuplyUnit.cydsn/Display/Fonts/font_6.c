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
#include "font.h"
#include "font_5.h"
// 
//  Font data for Calibri 8pt
// 

// Character bitmaps for Calibri 8pt
const uint_8 font_6Bitmaps[] = 
{
	// @0 ' ' (6 pixels wide)
	0b00000000, //       
	0b00000000, //       
	0b00000000, //       
	0b00000000, //       
	0b00000000, //       
	0b00000000, //       
	0b00000000, //       

	// @7 '-' (6 pixels wide)
	0b00000000, //       
	0b00000000, //       
	0b00000000, //       
	0b00000000, //       
	0b01110000, //  ###  
	0b00000000, //       
	0b00000000, //       

	// @14 '0' (6 pixels wide)
	0b01110000, //  ###  
	0b10001000, // #   # 
	0b10001000, // #   # 
	0b10001000, // #   # 
	0b10001000, // #   # 
	0b10001000, // #   # 
	0b01110000, //  ###  

	// @21 '1' (6 pixels wide)
	0b01100000, //  ##   
	0b11100000, // ###   
	0b00100000, //   #   
	0b00100000, //   #   
	0b00100000, //   #   
	0b00100000, //   #   
	0b11110000, // ####  

	// @28 '2' (6 pixels wide)
	0b11110000, // ####  
	0b10001000, // #   # 
	0b00001000, //     # 
	0b00010000, //    #  
	0b00100000, //   #   
	0b01000000, //  #    
	0b11111000, // ##### 

	// @35 '3' (6 pixels wide)
	0b01110000, //  ###  
	0b10001000, // #   # 
	0b00001000, //     # 
	0b01110000, //  ###  
	0b00001000, //     # 
	0b00001000, //     # 
	0b11110000, // ####  

	// @42 '4' (6 pixels wide)
	0b00110000, //   ##  
	0b00110000, //   ##  
	0b01010000, //  # #  
	0b01010000, //  # #  
	0b10010000, // #  #  
	0b11111000, // ##### 
	0b00010000, //    #  

	// @49 '5' (6 pixels wide)
	0b01111100, //  #####
	0b01000000, //  #    
	0b01000000, //  #    
	0b01111000, //  #### 
	0b00000100, //      #
	0b00000100, //      #
	0b01111000, //  #### 

	// @56 '6' (6 pixels wide)
	0b01111000, //  #### 
	0b11000000, // ##    
	0b10000000, // #     
	0b11110000, // ####  
	0b10001000, // #   # 
	0b10001000, // #   # 
	0b01110000, //  ###  

	// @63 '7' (6 pixels wide)
	0b11111000, // ##### 
	0b00001000, //     # 
	0b00010000, //    #  
	0b00010000, //    #  
	0b00100000, //   #   
	0b00100000, //   #   
	0b01000000, //  #    

	// @70 '8' (6 pixels wide)
	0b01110000, //  ###  
	0b10001000, // #   # 
	0b11011000, // ## ## 
	0b01110000, //  ###  
	0b10001000, // #   # 
	0b10001000, // #   # 
	0b01110000, //  ###  

	// @77 '9' (6 pixels wide)
	0b01110000, //  ###  
	0b10001000, // #   # 
	0b10001000, // #   # 
	0b01111000, //  #### 
	0b00001000, //     # 
	0b00011000, //    ## 
	0b11110000, // ####  
};

// Character descriptors for Calibri 8pt
// { [Char width in bits], [Offset into calibri_8ptCharBitmaps in bytes] }
const FONT_CHAR_INFO font_6Descriptors[] = 
{
	{6, 0}, 		//   
	{0, 0}, 		// ! 
	{0, 0}, 		// " 
	{0, 0}, 		// # 
	{0, 0}, 		// $ 
	{0, 0}, 		// % 
	{0, 0}, 		// & 
	{0, 0}, 		// ' 
	{0, 0}, 		// ( 
	{0, 0}, 		// ) 
	{0, 0}, 		// * 
	{0, 0}, 		// + 
	{0, 0}, 		// , 
	{6, 7}, 		// - 
	{0, 0}, 		// . 
	{0, 0}, 		// / 
	{6, 14}, 		// 0 
	{6, 21}, 		// 1 
	{6, 28}, 		// 2 
	{6, 35}, 		// 3 
	{6, 42}, 		// 4 
	{6, 49}, 		// 5 
	{6, 56}, 		// 6 
	{6, 63}, 		// 7 
	{6, 70}, 		// 8 
	{6, 77}, 		// 9 
};

// Font information for Calibri 8pt
const FONT_INFO font_6FontInfo =
{
	7, //  Character height
	' ', //  Start character
	'9', //  End character
	6, //  Width, in pixels, of space character
	2, /*separatorWidth*/
	font_6Descriptors, //  Character descriptor array
	font_6Bitmaps, //  Character bitmap array
};

/* [] END OF FILE */
