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
#include "font_2.h"
// 
//  Font data for Arial 20pt
// 

// Character bitmaps for Arial 20pt
const uint_8 font_2Bitmaps[] = 
{
	// @0 ' ' (6 pixels wide)
	0b00000000, //       
	0b00000000, //       
	0b00000000, //       
	0b00000000, //       
	0b00000000, //       
	0b00000000, //       
	0b00000000, //       
	0b00000000, //       
	0b00000000, //       
	0b00000000, //       
	0b00000000, //       
	0b00000000, //       
	0b00000000, //       
	0b00000000, //       
	0b00000000, //       
	0b00000000, //       
	0b00000000, //       
	0b00000000, //       
	0b00000000, //       
	0b00000000, //       

	// @20 '#' (15 pixels wide)
	0b11111111, 0b11111110, //      ###   ### 
	0b11111111, 0b11111110, //      ###   ### 
	0b00000001, 0b00000000, //     ####  #### 
	0b00000011, 0b10000000, //     ###   ###  
	0b00000111, 0b11000000, //     ###   ###  
	0b00001111, 0b11100000, // ###############
	0b00011111, 0b11110000, // ###############
	0b00000001, 0b00000000, // ###############
	0b00000001, 0b00000000, //    ###   ###   
	0b00000001, 0b00000000, //    ###   ###   
	0b00000001, 0b00000000, //    ###   ###   
	0b00000001, 0b00000000, //    ###   ###   
	0b00000001, 0b00000000, // ###############
	0b00011111, 0b11110000, // ###############
	0b00001111, 0b11100000, // ###############
	0b00000111, 0b11000000, //   ###   ###    
	0b00000011, 0b10000000, //   ###   ###    
	0b00000001, 0b00000000, //  ####  ####    
	0b11111111, 0b11111110, //  ###   ###     
	0b11111111, 0b11111110, //  ###   ###     

	// @60 '.' (4 pixels wide)
	0b00000000, //     
	0b00000000, //     
	0b00000000, //     
	0b00000000, //     
	0b00000000, //     
	0b00000000, //     
	0b00000000, //     
	0b00000000, //     
	0b00000000, //     
	0b00000000, //     
	0b00000000, //     
	0b00000000, //     
	0b00000000, //     
	0b00000000, //     
	0b00000000, //     
	0b00000000, //     
	0b11110000, // ####
	0b11110000, // ####
	0b11110000, // ####
	0b11110000, // ####

	// @80 '0' (13 pixels wide)
	0b00001111, 0b10000000, //     #####    
	0b00111111, 0b11100000, //   #########  
	0b00111111, 0b11100000, //   #########  
	0b01111000, 0b11110000, //  ####   #### 
	0b01111000, 0b11110000, //  ####   #### 
	0b11110000, 0b01111000, // ####     ####
	0b11110000, 0b01111000, // ####     ####
	0b11110000, 0b01111000, // ####     ####
	0b11110000, 0b01111000, // ####     ####
	0b11110000, 0b01111000, // ####     ####
	0b11110000, 0b01111000, // ####     ####
	0b11110000, 0b01111000, // ####     ####
	0b11110000, 0b01111000, // ####     ####
	0b11110000, 0b01111000, // ####     ####
	0b11110000, 0b01111000, // ####     ####
	0b01111000, 0b11110000, //  ####   #### 
	0b01111000, 0b11110000, //  ####   #### 
	0b00111111, 0b11100000, //   #########  
	0b00111111, 0b11100000, //   #########  
	0b00001111, 0b10000000, //     #####    

	// @120 '1' (9 pixels wide)
	0b00000011, 0b10000000, //       ###
	0b00000111, 0b10000000, //      ####
	0b00001111, 0b10000000, //     #####
	0b00011111, 0b10000000, //    ######
	0b01111111, 0b10000000, //  ########
	0b11111111, 0b10000000, // #########
	0b11110111, 0b10000000, // #### ####
	0b11100111, 0b10000000, // ###  ####
	0b10000111, 0b10000000, // #    ####
	0b00000111, 0b10000000, //      ####
	0b00000111, 0b10000000, //      ####
	0b00000111, 0b10000000, //      ####
	0b00000111, 0b10000000, //      ####
	0b00000111, 0b10000000, //      ####
	0b00000111, 0b10000000, //      ####
	0b00000111, 0b10000000, //      ####
	0b00000111, 0b10000000, //      ####
	0b00000111, 0b10000000, //      ####
	0b00000111, 0b10000000, //      ####
	0b00000111, 0b10000000, //      ####

	// @160 '2' (13 pixels wide)
	0b00001111, 0b11000000, //     ######   
	0b00111111, 0b11100000, //   #########  
	0b01111111, 0b11110000, //  ########### 
	0b01111000, 0b11111000, //  ####   #####
	0b11110000, 0b01111000, // ####     ####
	0b11110000, 0b01111000, // ####     ####
	0b00000000, 0b01111000, //          ####
	0b00000000, 0b01111000, //          ####
	0b00000000, 0b11110000, //         #### 
	0b00000001, 0b11110000, //        ##### 
	0b00000011, 0b11100000, //       #####  
	0b00000111, 0b11000000, //      #####   
	0b00001111, 0b10000000, //     #####    
	0b00011111, 0b00000000, //    #####     
	0b00111110, 0b00000000, //   #####      
	0b00111100, 0b00000000, //   ####       
	0b01111000, 0b00000000, //  ####        
	0b01111111, 0b11111000, //  ############
	0b11111111, 0b11111000, // #############
	0b11111111, 0b11111000, // #############

	// @200 '3' (13 pixels wide)
	0b00011111, 0b10000000, //    ######    
	0b00111111, 0b11000000, //   ########   
	0b01111111, 0b11100000, //  ##########  
	0b11111001, 0b11110000, // #####  ##### 
	0b11110000, 0b11110000, // ####    #### 
	0b00000000, 0b11110000, //         #### 
	0b00000001, 0b11100000, //        ####  
	0b00000111, 0b11100000, //      ######  
	0b00000111, 0b10000000, //      ####    
	0b00000111, 0b11100000, //      ######  
	0b00000000, 0b11110000, //         #### 
	0b00000000, 0b01111000, //          ####
	0b00000000, 0b01111000, //          ####
	0b00000000, 0b01111000, //          ####
	0b11110000, 0b01111000, // ####     ####
	0b11110000, 0b01111000, // ####     ####
	0b01111000, 0b11110000, //  ####   #### 
	0b01111111, 0b11110000, //  ########### 
	0b00111111, 0b11100000, //   #########  
	0b00001111, 0b10000000, //     #####    

	// @240 '4' (14 pixels wide)
	0b00000000, 0b11110000, //         ####  
	0b00000000, 0b11110000, //         ####  
	0b00000001, 0b11110000, //        #####  
	0b00000011, 0b11110000, //       ######  
	0b00000011, 0b11110000, //       ######  
	0b00000111, 0b11110000, //      #######  
	0b00001110, 0b11110000, //     ### ####  
	0b00001110, 0b11110000, //     ### ####  
	0b00011100, 0b11110000, //    ###  ####  
	0b00111000, 0b11110000, //   ###   ####  
	0b00111000, 0b11110000, //   ###   ####  
	0b01110000, 0b11110000, //  ###    ####  
	0b11100000, 0b11110000, // ###     ####  
	0b11111111, 0b11111100, // ##############
	0b11111111, 0b11111100, // ##############
	0b11111111, 0b11111100, // ##############
	0b00000000, 0b11110000, //         ####  
	0b00000000, 0b11110000, //         ####  
	0b00000000, 0b11110000, //         ####  
	0b00000000, 0b11110000, //         ####  

	// @280 '5' (13 pixels wide)
	0b00111111, 0b11110000, //   ########## 
	0b00111111, 0b11110000, //   ########## 
	0b01111111, 0b11110000, //  ########### 
	0b01111000, 0b00000000, //  ####        
	0b01110000, 0b00000000, //  ###         
	0b01110000, 0b00000000, //  ###         
	0b01110111, 0b11000000, //  ### #####   
	0b11111111, 0b11100000, // ###########  
	0b11111111, 0b11110000, // ############ 
	0b11110000, 0b11110000, // ####    #### 
	0b00000000, 0b01111000, //          ####
	0b00000000, 0b01111000, //          ####
	0b00000000, 0b01111000, //          ####
	0b00000000, 0b01111000, //          ####
	0b00000000, 0b01111000, //          ####
	0b11110000, 0b01111000, // ####     ####
	0b11111000, 0b11110000, // #####   #### 
	0b01111111, 0b11100000, //  ##########  
	0b00111111, 0b11100000, //   #########  
	0b00011111, 0b10000000, //    ######    

	// @320 '6' (13 pixels wide)
	0b00000111, 0b11000000, //      #####   
	0b00011111, 0b11100000, //    ########  
	0b00111111, 0b11110000, //   ########## 
	0b01111000, 0b11111000, //  ####   #####
	0b01111000, 0b01111000, //  ####    ####
	0b01110000, 0b00000000, //  ###         
	0b11110000, 0b00000000, // ####         
	0b11110111, 0b11000000, // #### #####   
	0b11111111, 0b11100000, // ###########  
	0b11111111, 0b11110000, // ############ 
	0b11111000, 0b11110000, // #####   #### 
	0b11110000, 0b01111000, // ####     ####
	0b11110000, 0b01111000, // ####     ####
	0b11110000, 0b01111000, // ####     ####
	0b11110000, 0b01111000, // ####     ####
	0b01110000, 0b01111000, //  ###     ####
	0b01111000, 0b11110000, //  ####   #### 
	0b00111111, 0b11110000, //   ########## 
	0b00011111, 0b11100000, //    ########  
	0b00001111, 0b10000000, //     #####    

	// @360 '7' (13 pixels wide)
	0b11111111, 0b11111000, // #############
	0b11111111, 0b11111000, // #############
	0b11111111, 0b11111000, // #############
	0b00000000, 0b11111000, //         #####
	0b00000001, 0b11110000, //        ##### 
	0b00000001, 0b11100000, //        ####  
	0b00000011, 0b11000000, //       ####   
	0b00000111, 0b11000000, //      #####   
	0b00000111, 0b10000000, //      ####    
	0b00001111, 0b10000000, //     #####    
	0b00001111, 0b00000000, //     ####     
	0b00001111, 0b00000000, //     ####     
	0b00011110, 0b00000000, //    ####      
	0b00011110, 0b00000000, //    ####      
	0b00011110, 0b00000000, //    ####      
	0b00011110, 0b00000000, //    ####      
	0b00111100, 0b00000000, //   ####       
	0b00111100, 0b00000000, //   ####       
	0b00111100, 0b00000000, //   ####       
	0b00111100, 0b00000000, //   ####       

	// @400 '8' (13 pixels wide)
	0b00011111, 0b11000000, //    #######   
	0b00111111, 0b11100000, //   #########  
	0b01111111, 0b11110000, //  ########### 
	0b11111000, 0b11111000, // #####   #####
	0b11110000, 0b01111000, // ####     ####
	0b11110000, 0b01111000, // ####     ####
	0b11110000, 0b01111000, // ####     ####
	0b01111000, 0b11110000, //  ####   #### 
	0b00111111, 0b11100000, //   #########  
	0b00011111, 0b11000000, //    #######   
	0b00111111, 0b11100000, //   #########  
	0b01111000, 0b11110000, //  ####   #### 
	0b11110000, 0b01111000, // ####     ####
	0b11110000, 0b01111000, // ####     ####
	0b11110000, 0b01111000, // ####     ####
	0b11110000, 0b01111000, // ####     ####
	0b11111000, 0b11111000, // #####   #####
	0b01111111, 0b11110000, //  ########### 
	0b00111111, 0b11100000, //   #########  
	0b00001111, 0b10000000, //     #####    

	// @440 '9' (13 pixels wide)
	0b00001111, 0b10000000, //     #####    
	0b00111111, 0b11000000, //   ########   
	0b01111111, 0b11100000, //  ##########  
	0b01111000, 0b11110000, //  ####   #### 
	0b11110000, 0b01110000, // ####     ### 
	0b11110000, 0b01111000, // ####     ####
	0b11110000, 0b01111000, // ####     ####
	0b11110000, 0b01111000, // ####     ####
	0b11110000, 0b01111000, // ####     ####
	0b01111000, 0b11111000, //  ####   #####
	0b01111111, 0b11111000, //  ############
	0b00111111, 0b11111000, //   ###########
	0b00011111, 0b01111000, //    ##### ####
	0b00000000, 0b01111000, //          ####
	0b00000000, 0b01110000, //          ### 
	0b11110000, 0b11110000, // ####    #### 
	0b11111000, 0b11110000, // #####   #### 
	0b01111111, 0b11100000, //  ##########  
	0b01111111, 0b11000000, //  #########   
	0b00011111, 0b00000000, //    #####     

	// @480 'a' (13 pixels wide)
	0b00000000, 0b00000000, //              
	0b00000000, 0b00000000, //              
	0b00000000, 0b00000000, //              
	0b00000000, 0b00000000, //              
	0b00000000, 0b00000000, //              
	0b00011111, 0b11000000, //    #######   
	0b00111111, 0b11100000, //   #########  
	0b01111111, 0b11110000, //  ########### 
	0b11110001, 0b11110000, // ####   ##### 
	0b11100000, 0b11110000, // ###     #### 
	0b00000000, 0b11110000, //         #### 
	0b00000011, 0b11110000, //       ###### 
	0b00111111, 0b11110000, //   ########## 
	0b01111100, 0b11110000, //  #####  #### 
	0b11110000, 0b11110000, // ####    #### 
	0b11110000, 0b11110000, // ####    #### 
	0b11110001, 0b11110000, // ####   ##### 
	0b11111111, 0b11110000, // ############ 
	0b01111111, 0b01110000, //  ####### ### 
	0b00111110, 0b01111000, //   #####  ####

	// @520 'v' (13 pixels wide)
	0b00000000, 0b00000000, //              
	0b00000000, 0b00000000, //              
	0b00000000, 0b00000000, //              
	0b00000000, 0b00000000, //              
	0b00000000, 0b00000000, //              
	0b11110000, 0b01111000, // ####     ####
	0b11110000, 0b01111000, // ####     ####
	0b11110000, 0b01111000, // ####     ####
	0b01110000, 0b01110000, //  ###     ### 
	0b01111000, 0b11110000, //  ####   #### 
	0b01111000, 0b11110000, //  ####   #### 
	0b00111000, 0b11100000, //   ###   ###  
	0b00111000, 0b11100000, //   ###   ###  
	0b00111100, 0b11100000, //   ####  ###  
	0b00011101, 0b11000000, //    ### ###   
	0b00011101, 0b11000000, //    ### ###   
	0b00011111, 0b11000000, //    #######   
	0b00001111, 0b10000000, //     #####    
	0b00001111, 0b10000000, //     #####    
	0b00001111, 0b10000000, //     #####    
};

// Character descriptors for Arial 20pt
// { [Char width in bits], [Offset into arial_20ptCharBitmaps in bytes] }
const FONT_CHAR_INFO font_2Descriptors[] = 
{
	{6, 0}, 		//   
	{0, 0}, 		// ! 
	{0, 0}, 		// " 
	{15, 20}, 		// # 
	{0, 0}, 		// $ 
	{0, 0}, 		// % 
	{0, 0}, 		// & 
	{0, 0}, 		// ' 
	{0, 0}, 		// ( 
	{0, 0}, 		// ) 
	{0, 0}, 		// * 
	{0, 0}, 		// + 
	{0, 0}, 		// , 
	{0, 0}, 		// - 
	{4, 60}, 		// . 
	{0, 0}, 		// / 
	{13, 80}, 		// 0 
	{9, 120}, 		// 1 
	{13, 160}, 		// 2 
	{13, 200}, 		// 3 
	{14, 240}, 		// 4 
	{13, 280}, 		// 5 
	{13, 320}, 		// 6 
	{13, 360}, 		// 7 
	{13, 400}, 		// 8 
	{13, 440}, 		// 9 
	{0, 0}, 		// : 
	{0, 0}, 		// ; 
	{0, 0}, 		// < 
	{0, 0}, 		// = 
	{0, 0}, 		// > 
	{0, 0}, 		// ? 
	{0, 0}, 		// @ 
	{0, 0}, 		// A 
	{0, 0}, 		// B 
	{0, 0}, 		// C 
	{0, 0}, 		// D 
	{0, 0}, 		// E 
	{0, 0}, 		// F 
	{0, 0}, 		// G 
	{0, 0}, 		// H 
	{0, 0}, 		// I 
	{0, 0}, 		// J 
	{0, 0}, 		// K 
	{0, 0}, 		// L 
	{0, 0}, 		// M 
	{0, 0}, 		// N 
	{0, 0}, 		// O 
	{0, 0}, 		// P 
	{0, 0}, 		// Q 
	{0, 0}, 		// R 
	{0, 0}, 		// S 
	{0, 0}, 		// T 
	{0, 0}, 		// U 
	{0, 0}, 		// V 
	{0, 0}, 		// W 
	{0, 0}, 		// X 
	{0, 0}, 		// Y 
	{0, 0}, 		// Z 
	{0, 0}, 		// [ 
	{0, 0}, 		// "\" 
	{0, 0}, 		// ] 
	{0, 0}, 		// ^ 
	{0, 0}, 		// _ 
	{0, 0}, 		// ` 
	{13, 480}, 		// a 
	{0, 0}, 		// b 
	{0, 0}, 		// c 
	{0, 0}, 		// d 
	{0, 0}, 		// e 
	{0, 0}, 		// f 
	{0, 0}, 		// g 
	{0, 0}, 		// h 
	{0, 0}, 		// i 
	{0, 0}, 		// j 
	{0, 0}, 		// k 
	{0, 0}, 		// l 
	{0, 0}, 		// m 
	{0, 0}, 		// n 
	{0, 0}, 		// o 
	{0, 0}, 		// p 
	{0, 0}, 		// q 
	{0, 0}, 		// r 
	{0, 0}, 		// s 
	{0, 0}, 		// t 
	{0, 0}, 		// u 
	{13, 520}, 		// v 
};

// Font information for Arial Narrow 14pt
const FONT_INFO font_2FontInfo =
{
	20, //  Character height
	' ', //  Start character
	'v', //  End character
	6,	/*spaceWidth*/
	2, /*separatorWidth*/
	font_2Descriptors, //  Character descriptor array
	font_2Bitmaps, //  Character bitmap array
};


/* [] END OF FILE */
