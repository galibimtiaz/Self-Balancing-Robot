/*
* MotorDriver.cpp
*
* Created: 11/6/2019 8:56:07 AM
*  Author: Galib
*/

#include "MotorDriver.h"
#include <avr/io.h>

MotorDriver::MotorDriver(unsigned char port,int pin1,int pin2)
{
	PORT = port;
	pin1 = pin1;
	pin2 = pin2;
	
	pwm = 0;
	
	set_bits(DDR(PORT),PIN1,PIN2);
	clear_bits(PORT,PIN1,PIN2);
}

void MotorDriver::forward(int pwm)
{
	
	OCR1A = pwm;
	set_bit(PORT,pin2);
	clear_bit(PORT,pin1);
}

void MotorDriver::reverse(int pwm)
{
	OCR1A = pwm;
	set_bit(PORT,pin1);
	clear_bit(PORT,pin2);
}

void MotorDriver::stop()
{
	clear_bits(PORT,pin1,pin2);
}
