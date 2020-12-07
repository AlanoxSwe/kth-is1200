/* mipslabwork.c

	 This file written 2015 by F Lundevall

	 This file should be changed by YOU! So add something here:

	 This file modified 2015-12-24 by Ture Teknolog 

	 Latest update 2015-08-28 by F Lundevall

	 For copyright and licensing, see file COPYING */

#include <stdint.h>	 /* Declarations of uint_32 and the like */
#include <pic32mx.h>	/* Declarations of system-specific addresses etc */
#include "mipslab.h"	/* Declatations for these labs */

#define TMR2PERIOD ((80000000 / 256) / 10) /* 100ms */

int mytime = 0x0000;
int timeoutcount = 0;

char textstring[] = "text, more text, and even more text!";

/* Interrupt Service Routine */
void user_isr( void )
{
	return;
}

/* Lab-specific initialization goes here */
void labinit( void ) {

	// Set *E to address of TRISE.
	volatile int *E = (volatile int *) 0xbf886100;
	
	// Set last 8 bits to zero, i.e. sets them as output pins.
	*E = *E & 0xff00;

	// Initialize port D, set bits 11-5 as inputs.
	TRISD = TRISD & 0x0fe0;

 
    T2CONSET = 0x70; // 0111 0000 (bit 6-4 for prescaling, Section 14 Timers, P.9)
    PR2 = TMR2PERIOD; //Set the time period
    TMR2 = 0; //Resets the timer
    T2CONSET = 0x8000; //Sets the bit 15 "ON" to 1 in T2CON, bit #15

	return;
}

/* This function is called repetitively from the main program */
void labwork( void ) {

	int sw = getsw();
	int btn = getbtns();
	/* 
	Checks if bit 1(001) is pressed and 2(010) and so on ..	
	sw is a number 0-f, shift it into the right position and OR it with the correct zeroed byte of mytime.
	*/	

	if (btn & 1) {
		mytime = (sw << 4) | (mytime & 0xff0f);
	}
	if (btn & 2) {
		mytime = (sw << 8) | (mytime & 0xf0ff);
	}
	if (btn & 4) {
		mytime = (sw << 12) | (mytime & 0x0fff);
	}

	//delay( 1000 );
	
	// Check time-out event flag.
	if (IFS(0) & 0x100) {

		// Reset all event flags. (Not so elegant)
		IFS(0) = 0;		
		timeoutcount++;

		if (timeoutcount == 10) {

			time2string( textstring, mytime );
			display_string( 3, textstring );
			display_update();
			tick( &mytime );
			display_image(96, icon);
					
			timeoutcount = 0;		
		}
	}		
}





