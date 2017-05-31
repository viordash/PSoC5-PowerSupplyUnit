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
#include "font_3.h"
// 
//  Font data for Arial Narrow 26pt
// 

// Character bitmaps for Arial Narrow 26pt
const uint_8 font_3Bitmaps[] = 
{
	// @0 ' ' (8 pixels wide)
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
	0b00000000, //         
	0b00000000, //         
	0b00000000, //         
	0b00000000, //         
	0b00000000, //         

	// @25 '.' (4 pixels wide)
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
	0b00000000, //     
	0b11110000, // ####
	0b11110000, // ####
	0b11110000, // ####
	0b11110000, // ####

	// @50 '0' (13 pixels wide)
	0b00001111, 0b10000000, //     #####    
	0b00011111, 0b11000000, //    #######   
	0b00111111, 0b11100000, //   #########  
	0b01111111, 0b11110000, //  ########### 
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
	0b11110000, 0b01111000, // ####     ####
	0b11110000, 0b01111000, // ####     ####
	0b11110000, 0b01111000, // ####     ####
	0b01111000, 0b11110000, //  ####   #### 
	0b01111000, 0b11110000, //  ####   #### 
	0b01111111, 0b11110000, //  ########### 
	0b00111111, 0b11100000, //   #########  
	0b00011111, 0b11000000, //    #######   
	0b00001111, 0b10000000, //     #####    

	// @100 '1' (9 pixels wide)
	0b00000011, 0b10000000, //       ###
	0b00000111, 0b10000000, //      ####
	0b00000111, 0b10000000, //      ####
	0b00001111, 0b10000000, //     #####
	0b00011111, 0b10000000, //    ######
	0b00111111, 0b10000000, //   #######
	0b01111111, 0b10000000, //  ########
	0b11111111, 0b10000000, // #########
	0b11110111, 0b10000000, // #### ####
	0b11000111, 0b10000000, // ##   ####
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
	0b00000111, 0b10000000, //      ####
	0b00000111, 0b10000000, //      ####
	0b00000111, 0b10000000, //      ####

	// @150 '2' (14 pixels wide)
	0b00001111, 0b11000000, //     ######    
	0b00111111, 0b11110000, //   ##########  
	0b00111111, 0b11111000, //   ########### 
	0b01111111, 0b11111000, //  ############ 
	0b01111000, 0b01111100, //  ####    #####
	0b11111000, 0b00111100, // #####     ####
	0b11110000, 0b00111100, // ####      ####
	0b00110000, 0b00111100, //   ##      ####
	0b00000000, 0b00111100, //           ####
	0b00000000, 0b00111100, //           ####
	0b00000000, 0b01111000, //          #### 
	0b00000000, 0b11111000, //         ##### 
	0b00000001, 0b11111000, //        ###### 
	0b00000001, 0b11110000, //        #####  
	0b00000011, 0b11100000, //       #####   
	0b00000111, 0b11000000, //      #####    
	0b00001111, 0b11000000, //     ######    
	0b00011111, 0b10000000, //    ######     
	0b00111111, 0b00000000, //   ######      
	0b00111110, 0b00000000, //   #####       
	0b01111100, 0b00000000, //  #####        
	0b01111111, 0b11111100, //  #############
	0b11111111, 0b11111100, // ##############
	0b11111111, 0b11111100, // ##############
	0b11111111, 0b11111100, // ##############

	// @200 '3' (14 pixels wide)
	0b00001111, 0b10000000, //     #####     
	0b00111111, 0b11100000, //   #########   
	0b01111111, 0b11110000, //  ###########  
	0b01111111, 0b11110000, //  ###########  
	0b11111000, 0b11111000, // #####   ##### 
	0b11110000, 0b01111000, // ####     #### 
	0b00110000, 0b01111000, //   ##     #### 
	0b00000000, 0b01111000, //          #### 
	0b00000000, 0b11110000, //         ####  
	0b00000111, 0b11110000, //      #######  
	0b00000111, 0b11100000, //      ######   
	0b00000111, 0b11100000, //      ######   
	0b00000111, 0b11110000, //      #######  
	0b00000000, 0b01111000, //          #### 
	0b00000000, 0b01111100, //          #####
	0b00000000, 0b00111100, //           ####
	0b00000000, 0b00111100, //           ####
	0b00110000, 0b00111100, //   ##      ####
	0b11110000, 0b00111100, // ####      ####
	0b11111000, 0b01111100, // #####    #####
	0b01111100, 0b01111000, //  #####   #### 
	0b01111111, 0b11111000, //  ############ 
	0b00111111, 0b11110000, //   ##########  
	0b00011111, 0b11100000, //    ########   
	0b00001111, 0b10000000, //     #####     

	// @250 '4' (15 pixels wide)
	0b00000000, 0b11110000, //         ####   
	0b00000000, 0b11110000, //         ####   
	0b00000001, 0b11110000, //        #####   
	0b00000001, 0b11110000, //        #####   
	0b00000011, 0b11110000, //       ######   
	0b00000011, 0b11110000, //       ######   
	0b00000111, 0b11110000, //      #######   
	0b00000111, 0b11110000, //      #######   
	0b00001110, 0b11110000, //     ### ####   
	0b00011110, 0b11110000, //    #### ####   
	0b00011100, 0b11110000, //    ###  ####   
	0b00111100, 0b11110000, //   ####  ####   
	0b00111000, 0b11110000, //   ###   ####   
	0b01111000, 0b11110000, //  ####   ####   
	0b01110000, 0b11110000, //  ###    ####   
	0b11110000, 0b11110000, // ####    ####   
	0b11111111, 0b11111110, // ###############
	0b11111111, 0b11111110, // ###############
	0b11111111, 0b11111110, // ###############
	0b11111111, 0b11111110, // ###############
	0b00000000, 0b11110000, //         ####   
	0b00000000, 0b11110000, //         ####   
	0b00000000, 0b11110000, //         ####   
	0b00000000, 0b11110000, //         ####   
	0b00000000, 0b11110000, //         ####   

	// @300 '5' (14 pixels wide)
	0b00111111, 0b11111000, //   ########### 
	0b00111111, 0b11111000, //   ########### 
	0b00111111, 0b11111000, //   ########### 
	0b01111111, 0b11111000, //  ############ 
	0b01111000, 0b00000000, //  ####         
	0b01111000, 0b00000000, //  ####         
	0b01111000, 0b00000000, //  ####         
	0b01111011, 0b11000000, //  #### ####    
	0b01111111, 0b11100000, //  ##########   
	0b11111111, 0b11110000, // ############  
	0b11111111, 0b11111000, // ############# 
	0b11111000, 0b11111000, // #####   ##### 
	0b00110000, 0b01111100, //   ##     #####
	0b00000000, 0b00111100, //           ####
	0b00000000, 0b00111100, //           ####
	0b00000000, 0b00111100, //           ####
	0b00000000, 0b00111100, //           ####
	0b00110000, 0b00111100, //   ##      ####
	0b11110000, 0b00111100, // ####      ####
	0b11111000, 0b01111000, // #####    #### 
	0b01111100, 0b11111000, //  #####  ##### 
	0b01111111, 0b11111000, //  ############ 
	0b00111111, 0b11110000, //   ##########  
	0b00011111, 0b11100000, //    ########   
	0b00001111, 0b10000000, //     #####     

	// @350 '6' (14 pixels wide)
	0b00000111, 0b11000000, //      #####    
	0b00001111, 0b11110000, //     ########  
	0b00011111, 0b11111000, //    ########## 
	0b00111111, 0b11111000, //   ########### 
	0b01111100, 0b01111100, //  #####   #####
	0b01111000, 0b00111100, //  ####     ####
	0b01110000, 0b00110000, //  ###      ##  
	0b11110000, 0b00000000, // ####          
	0b11110000, 0b00000000, // ####          
	0b11110111, 0b11000000, // #### #####    
	0b11111111, 0b11100000, // ###########   
	0b11111111, 0b11110000, // ############  
	0b11111111, 0b11111000, // ############# 
	0b11111000, 0b01111000, // #####    #### 
	0b11110000, 0b01111100, // ####     #####
	0b11110000, 0b00111100, // ####      ####
	0b11110000, 0b00111100, // ####      ####
	0b11110000, 0b00111100, // ####      ####
	0b01110000, 0b00111100, //  ###      ####
	0b01111000, 0b00111100, //  ####     ####
	0b01111100, 0b01111000, //  #####   #### 
	0b00111111, 0b11111000, //   ########### 
	0b00111111, 0b11110000, //   ##########  
	0b00011111, 0b11100000, //    ########   
	0b00000111, 0b11000000, //      #####    

	// @400 '7' (14 pixels wide)
	0b11111111, 0b11111100, // ##############
	0b11111111, 0b11111100, // ##############
	0b11111111, 0b11111100, // ##############
	0b11111111, 0b11111100, // ##############
	0b00000000, 0b01111000, //          #### 
	0b00000000, 0b11111000, //         ##### 
	0b00000000, 0b11110000, //         ####  
	0b00000001, 0b11100000, //        ####   
	0b00000001, 0b11100000, //        ####   
	0b00000011, 0b11100000, //       #####   
	0b00000011, 0b11000000, //       ####    
	0b00000011, 0b11000000, //       ####    
	0b00000111, 0b10000000, //      ####     
	0b00000111, 0b10000000, //      ####     
	0b00000111, 0b10000000, //      ####     
	0b00001111, 0b00000000, //     ####      
	0b00001111, 0b00000000, //     ####      
	0b00001111, 0b00000000, //     ####      
	0b00001111, 0b00000000, //     ####      
	0b00001111, 0b00000000, //     ####      
	0b00011110, 0b00000000, //    ####       
	0b00011110, 0b00000000, //    ####       
	0b00011110, 0b00000000, //    ####       
	0b00011110, 0b00000000, //    ####       
	0b00011110, 0b00000000, //    ####       

	// @450 '8' (14 pixels wide)
	0b00001111, 0b11000000, //     ######    
	0b00111111, 0b11110000, //   ##########  
	0b01111111, 0b11111000, //  ############ 
	0b01111111, 0b11111000, //  ############ 
	0b11111000, 0b01111100, // #####    #####
	0b11110000, 0b00111100, // ####      ####
	0b11110000, 0b00111100, // ####      ####
	0b11110000, 0b00111100, // ####      ####
	0b11110000, 0b00111100, // ####      ####
	0b01111000, 0b01111000, //  ####    #### 
	0b01111111, 0b11110000, //  ###########  
	0b00011111, 0b11100000, //    ########   
	0b00111111, 0b11110000, //   ##########  
	0b01111111, 0b11111000, //  ############ 
	0b01111000, 0b01111000, //  ####    #### 
	0b11110000, 0b00111100, // ####      ####
	0b11110000, 0b00111100, // ####      ####
	0b11110000, 0b00111100, // ####      ####
	0b11110000, 0b00111100, // ####      ####
	0b11110000, 0b00111100, // ####      ####
	0b11111000, 0b01111100, // #####    #####
	0b01111111, 0b11111000, //  ############ 
	0b01111111, 0b11111000, //  ############ 
	0b00011111, 0b11110000, //    #########  
	0b00001111, 0b11000000, //     ######    

	// @500 '9' (14 pixels wide)
	0b00001111, 0b10000000, //     #####     
	0b00011111, 0b11100000, //    ########   
	0b00111111, 0b11110000, //   ##########  
	0b01111111, 0b11110000, //  ###########  
	0b01111000, 0b11111000, //  ####   ##### 
	0b11110000, 0b01111000, // ####     #### 
	0b11110000, 0b00111000, // ####      ### 
	0b11110000, 0b00111100, // ####      ####
	0b11110000, 0b00111100, // ####      ####
	0b11110000, 0b00111100, // ####      ####
	0b11111000, 0b00111100, // #####     ####
	0b01111000, 0b01111100, //  ####    #####
	0b01111111, 0b11111100, //  #############
	0b00111111, 0b11111100, //   ############
	0b00011111, 0b11111100, //    ###########
	0b00001111, 0b00111100, //     ####  ####
	0b00000000, 0b00111100, //           ####
	0b00000000, 0b00111100, //           ####
	0b00110000, 0b00111000, //   ##      ### 
	0b11110000, 0b01111000, // ####     #### 
	0b11111000, 0b11111000, // #####   ##### 
	0b01111111, 0b11110000, //  ###########  
	0b01111111, 0b11100000, //  ##########   
	0b00111111, 0b11000000, //   ########    
	0b00001111, 0b10000000, //     #####     

	// @550 ':' (4 pixels wide)
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

	// @575 'a' (14 pixels wide)
	0b00000000, 0b00000000, //               
	0b00000000, 0b00000000, //               
	0b00000000, 0b00000000, //               
	0b00000000, 0b00000000, //               
	0b00000000, 0b00000000, //               
	0b00000000, 0b00000000, //               
	0b00000000, 0b00000000, //               
	0b00011111, 0b11000000, //    #######    
	0b00111111, 0b11110000, //   ##########  
	0b01111111, 0b11110000, //  ###########  
	0b11111111, 0b11111000, // ############# 
	0b11111000, 0b01111000, // #####    #### 
	0b00110000, 0b01111000, //   ##     #### 
	0b00000000, 0b11111000, //         ##### 
	0b00001111, 0b11111000, //     ######### 
	0b00111111, 0b11111000, //   ########### 
	0b01111111, 0b11111000, //  ############ 
	0b11111110, 0b01111000, // #######  #### 
	0b11110000, 0b01111000, // ####     #### 
	0b11110000, 0b01111000, // ####     #### 
	0b11111000, 0b11111000, // #####   ##### 
	0b11111111, 0b11111000, // ############# 
	0b01111111, 0b11111000, //  ############ 
	0b01111111, 0b10111000, //  ######## ### 
	0b00011111, 0b00111100, //    #####  ####

	// @625 'v' (15 pixels wide)
	0b00000000, 0b00000000, //                
	0b00000000, 0b00000000, //                
	0b00000000, 0b00000000, //                
	0b00000000, 0b00000000, //                
	0b00000000, 0b00000000, //                
	0b00000000, 0b00000000, //                
	0b00000000, 0b00000000, //                
	0b11110000, 0b00011110, // ####       ####
	0b11111000, 0b00111110, // #####     #####
	0b01111000, 0b00111100, //  ####     #### 
	0b01111000, 0b00111100, //  ####     #### 
	0b01111000, 0b00111100, //  ####     #### 
	0b00111100, 0b01111000, //   ####   ####  
	0b00111100, 0b01111000, //   ####   ####  
	0b00111100, 0b01111000, //   ####   ####  
	0b00111100, 0b01111000, //   ####   ####  
	0b00011110, 0b11110000, //    #### ####   
	0b00011110, 0b11110000, //    #### ####   
	0b00011110, 0b11110000, //    #### ####   
	0b00001111, 0b11100000, //     #######    
	0b00001111, 0b11100000, //     #######    
	0b00001111, 0b11100000, //     #######    
	0b00000111, 0b11000000, //      #####     
	0b00000111, 0b11000000, //      #####     
	0b00000111, 0b11000000, //      #####     
};

// Character descriptors for Arial Narrow 26pt
// { [Char width in bits], [Offset into arialNarrow_26ptCharBitmaps in bytes] }
const FONT_CHAR_INFO font_3Descriptors[] = 
{
	{8, 0}, 		//   
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
	{0, 0}, 		// - 
	{4, 25}, 		// . 
	{0, 0}, 		// / 
	{13, 50}, 		// 0 
	{9, 100}, 		// 1 
	{14, 150}, 		// 2 
	{14, 200}, 		// 3 
	{15, 250}, 		// 4 
	{14, 300}, 		// 5 
	{14, 350}, 		// 6 
	{14, 400}, 		// 7 
	{14, 450}, 		// 8 
	{14, 500}, 		// 9 
	{4, 550}, 		// : 
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
	{14, 575}, 		// a 
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
	{15, 625}, 		// v 
};



// Font information for Bernard MT Condensed 72pt
const FONT_INFO font_3FontInfo =
{
	25, //  Character height
	' ', //  Start character
	'v', //  End character

	8,	/*spaceWidth*/
	2, /*separatorWidth*/
	font_3Descriptors, //  Character descriptor array
	font_3Bitmaps, //  Character bitmap array
};


/* [] END OF FILE */
