
#include <xc.h>
#include "system.h"

void main(void) {
    initOscillator();
    initPins();   
    initInterrupts();
    
    INTCON0bits.GIEH = 1;
    INTCON0bits.GIEL = 1;
    
    while (1) {
        
    }
}


//Example CANRX ISR
void __interrupt(irq(CANRX), high_priority, base(8)) CANRX_ISR()
{
    
    
}