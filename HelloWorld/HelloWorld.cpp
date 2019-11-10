/*
 * Hello_World.cpp
 *
 * Created: 12/12/2011 17:22:59
 *  Author: Loïc KAEMMERLEN
 */ 

# define F_CPU 16000000L
#include <avr/io.h>
#include <math.h>
#include <util/delay.h>    // including the avr delay lib
#include <util/delay.h>		// Including the avr delay lib
#include "Driver.h"
#include "usart.h"			// Header for Serial communication



// OBJECT CREATION
LED led1(PORTB,5);			// Creates an object called led1 connected to PortB.5 (0x05 is the Special function register for PORTB)
Driver driver(PORTC,PORTB);


int main(void)
{
	// INITIALIZATIONS
	DDRB |= (1 << DDB5);	//B5 output: board LED
	USART_Init(MYUBRR); // Initializes the serial communication
	// Go to USART.H AND CHANGE YOUR FOSC AND BAUD

	
	
    while(1)
    {
		led1.on();
        USART_Send_string("HELLO WORLD\n");
		_delay_ms(1000);	
		led1.off();
		_delay_ms(1000);

    }
}