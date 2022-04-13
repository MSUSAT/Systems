
#include <xc.h>
#include "system.h"

void initPins(void) {
    ANSELA = 0; //All digital
    ANSELB = 0;
    ANSELC = 0;
    LATA = 0;
    LATB = 0;
    LATC = 0;
    TRISA = 0;
    TRISB = 0;
    TRISC = 0;
    //PPS
    //First unlock PPS - should already be unlocked but doesn't hurt
    PPSLOCK = 0x55;
    PPSLOCK = 0xaa;
    PPSLOCKbits.PPSLOCKED = 0;
    
    //Input mapping
    CANRXPPS = 0b010011;  //RC3 as an example - upper 3 bits are port 010 = C, lower 3 bits are pin
    //Output mapping
    RC4PPS = 0x46;        //RC4 is CANTX
    
    //Now lock PPS
    PPSLOCK = 0x55;
    PPSLOCK = 0xaa;
    PPSLOCKbits.PPSLOCKED = 1;
}

void initOscillator(void) {
    //adjust HFINTOSC if needed
    while (OSCSTATbits.HFOR != 1);  //Wait for HFINTOSC ready
}

void initInterrupts(void) {
    INTCON0bits.IPEN = 1;
    GIE = 0;
    IVTLOCK = 0x55;
    IVTLOCK = 0xAA;
    IVTLOCKbits.IVTLOCKED = 0; // unlock IVT
    //Set IVT base to 0x000008
    IVTBASEU = 0;
    IVTBASEH = 0;
    IVTBASEL = 8;
    IVTLOCK = 0x55;
    IVTLOCK = 0xAA;
    IVTLOCKbits.IVTLOCKED = 1; // lock IVT

}

void __interrupt(irq(default),base(8)) Default_ISR()
{
}
