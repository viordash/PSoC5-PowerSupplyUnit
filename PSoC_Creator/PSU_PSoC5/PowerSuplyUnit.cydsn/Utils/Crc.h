#ifndef __CRC_H
#define __CRC_H

#include <device.h>
extern DWORD CalcCrc32(PBYTE buffer, INT size);
extern BYTE CalcCalibrateItemCrc8(PTCalibrateItem pCalibrateItem);

#endif /* end __CRC_H */