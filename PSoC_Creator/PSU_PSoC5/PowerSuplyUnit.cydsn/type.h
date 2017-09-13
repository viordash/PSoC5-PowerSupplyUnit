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

#ifndef __TYPE_H__
#define __TYPE_H__

#ifndef NULL
#define NULL    ((void *)0)
#endif

#ifndef FALSE
#define FALSE   (0)
#endif

#ifndef TRUE
#define TRUE    (1)
#endif

typedef unsigned char BYTE, * PBYTE;
typedef unsigned short WORD, * PWORD;
typedef signed short SHORT, * PSHORT;
typedef unsigned long DWORD, * PDWORD;
typedef unsigned long long LONG64;
#ifndef BOOL
typedef unsigned int BOOL, * PBOOL;
#endif
typedef signed int INT, * PINT;
typedef unsigned int	UINT;
typedef char CHAR, * PCHAR;
typedef void *  POINTER;
typedef float   FLOAT;

typedef void * PWaitFunction;

typedef struct _TDriveExt { 
  BYTE num;
	PWaitFunction waitFunction;
} TDriveExt;

//union uLONG64 {
//  LONG64 asLONG64;
//  DWORD asDWORD[2];
//  WORD asWORD[4];
//  BYTE asBYTE[8];
//};

union uDWORD {
  DWORD asDWORD;
  WORD asWORD[2];
  BYTE asBYTE[4];
};

union uWORD {
  WORD asWORD;
  BYTE asBYTE[2];
};

#define HI_WORD  USHRT_MAX
#define HI_DWORD  ULONG_MAX
#define HI_INT  LONG_MAX
#define HI_BYTE  0xFF
#define SWAP16(x) ((WORD)((x >> 8) | (x << 8)))



#endif  /* __TYPE_H__ */

/* [] END OF FILE */
