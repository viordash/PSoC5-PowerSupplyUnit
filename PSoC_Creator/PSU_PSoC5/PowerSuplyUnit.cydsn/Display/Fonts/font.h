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
#ifndef __FONT_H__
#define __FONT_H__
 
 
typedef unsigned char uint_8;
 
 
typedef struct {
  int width; // Character width in bytes.
//  int height; // Character height in bits.
  int offset; // Offset in bytes into font bitmap.
} FONT_CHAR_INFO, *PFONT_CHAR_INFO;
 
 
typedef struct {
  int height; // Character height in bytes.
  char start_char; // Start character.
  char end_char; // End character.
  int spaceWidth;  
	int separatorWidth;
  const FONT_CHAR_INFO * p_character_descriptor; // Character decriptor array.
  const uint_8 *p_character_bitmaps; // Character bitmap array.
} FONT_INFO, *PFONT_INFO;
 
 
#endif // __FONT_H__

/* [] END OF FILE */
