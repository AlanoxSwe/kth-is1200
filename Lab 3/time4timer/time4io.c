#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

//type name(void) == no parameters
int getsw(void){
                                    //Bits 8-11 needed
    return (PORTD >> 8) & 0x000F;   //Shift 8 bits to right, mask all other bits

}

int getbtns(void){
                                    //Bits 7, 6, 5 needed
    return (PORTD >> 5) & 0x0007;   //Shift 5 bits to right, mask all other bits
                                    // 7 = 0111

}