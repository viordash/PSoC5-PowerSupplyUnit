#ifndef __GENERAL_UTILS_H
#define __GENERAL_UTILS_H

#include <device.h>
extern void ProgramVersion(PCHAR ABuffer);
extern PCHAR _strncpy(PCHAR dest, PCHAR src, DWORD len);
extern void ClipStringAlignRight(PCHAR AString, CHAR AExtChar, DWORD ALimitLen);
extern void ClipStringAlignLeft(PCHAR AString, CHAR AExtChar, DWORD ALimitLen);
extern void ClipStringAlignMid(PCHAR AString, CHAR AExtChar, DWORD ALimitLen);
#endif /* end __GENERAL_UTILS_H */