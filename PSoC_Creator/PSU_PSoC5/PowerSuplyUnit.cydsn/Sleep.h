#ifndef __SLEEP_H
#define __SLEEP_H

#include <device.h>
    
extern void IdleTimer_Init();
extern void IdleTimer_Reset();
extern BOOL IdleTimer_Handle();

#endif /* end __SLEEP_H */