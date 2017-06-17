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
//  Font data for Calibri 10pt
// 

// Character bitmaps for Calibri 10pt
const uint_8 font_5Bitmaps[] = 
{
	// @0 '0' (5 pixels wide)
	0b01110000, //  ### 
	0b10001000, // #   #
	0b10001000, // #   #
	0b10001000, // #   #
	0b10001000, // #   #
	0b10001000, // #   #
	0b10001000, // #   #
	0b01110000, //  ### 

	// @8 '1' (5 pixels wide)
	0b01100000, //  ##  
	0b10100000, // # #  
	0b00100000, //   #  
	0b00100000, //   #  
	0b00100000, //   #  
	0b00100000, //   #  
	0b00100000, //   #  
	0b11111000, // #####

	// @16 '2' (5 pixels wide)
	0b01110000, //  ### 
	0b10001000, // #   #
	0b00001000, //     #
	0b00001000, //     #
	0b00010000, //    # 
	0b00100000, //   #  
	0b01000000, //  #   
	0b11111000, // #####

	// @24 '3' (5 pixels wide)
	0b01110000, //  ### 
	0b10001000, // #   #
	0b00001000, //     #
	0b01110000, //  ### 
	0b00001000, //     #
	0b00001000, //     #
	0b10001000, // #   #
	0b01110000, //  ### 

	// @32 '4' (5 pixels wide)
	0b00110000, //   ## 
	0b00110000, //   ## 
	0b01010000, //  # # 
	0b01010000, //  # # 
	0b10010000, // #  # 
	0b11111000, // #####
	0b00010000, //    # 
	0b00010000, //    # 

	// @40 '5' (5 pixels wide)
	0b11111000, // #####
	0b10000000, // #    
	0b10000000, // #    
	0b11110000, // #### 
	0b00001000, //     #
	0b00001000, //     #
	0b10001000, // #   #
	0b01110000, //  ### 

	// @48 '6' (5 pixels wide)
	0b00111000, //   ###
	0b01000000, //  #   
	0b10000000, // #    
	0b11110000, // #### 
	0b10001000, // #   #
	0b10001000, // #   #
	0b10001000, // #   #
	0b01110000, //  ### 

	// @56 '7' (5 pixels wide)
	0b11111000, // #####
	0b00001000, //     #
	0b00010000, //    # 
	0b00010000, //    # 
	0b00100000, //   #  
	0b00100000, //   #  
	0b01000000, //  #   
	0b01000000, //  #   

	// @64 '8' (5 pixels wide)
	0b01110000, //  ### 
	0b10001000, // #   #
	0b10001000, // #   #
	0b01110000, //  ### 
	0b10001000, // #   #
	0b10001000, // #   #
	0b10001000, // #   #
	0b01110000, //  ### 

	// @72 '9' (5 pixels wide)
	0b01110000, //  ### 
	0b10001000, // #   #
	0b10001000, // #   #
	0b10001000, // #   #
	0b01111000, //  ####
	0b00001000, //     #
	0b00010000, //    # 
	0b11100000, // ###  
};

// Character descriptors for Calibri 10pt
// { [Char width in bits], [Offset into calibri_10ptCharBitmaps in bytes] }
const FONT_CHAR_INFO font_5Descriptors[] = 
{
	{5, 0}, 		// 0 
	{5, 8}, 		// 1 
	{5, 16}, 		// 2 
	{5, 24}, 		// 3 
	{5, 32}, 		// 4 
	{5, 40}, 		// 5 
	{5, 48}, 		// 6 
	{5, 56}, 		// 7 
	{5, 64}, 		// 8 
	{5, 72}, 		// 9 
};

// Font information for Calibri 10pt

const FONT_INFO font_5FontInfo =
{
	8, //  Character height
	'0', //  Start character
	'9', //  End character
	3, //  Width, in pixels, of space character
	2, /*separatorWidth*/
	font_5Descriptors, //  Character descriptor array
	font_5Bitmaps, //  Character bitmap array
};

/* [] END OF FILE */
