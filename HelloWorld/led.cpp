
#include "led.h"
#include <avr/io.h>


LED::LED (unsigned char  p,int x)
{	
	PORT = p;
	PIN = x;
}

void LED::on(void)
{
	set_bit(PORT,PIN);
}

void LED::off(void)
{
	clear_bit(PORT,PIN);
}

