#ifndef SYSTEM_H
#define	SYSTEM_H

#include <xc.h>
#define _XTAL_FREQ  64000000

void initPins(void);
void initOscillator(void);
void initInterrupts(void);

#endif