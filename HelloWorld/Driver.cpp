/*
* Driver.cpp
*
* Created: 11/8/2019 1:10:53 AM
*  Author: Galib
*/

#include "Driver.h"
#include <avr/io.h>


 Driver::Driver(unsigned char motorPort,unsigned char pwmPort)
 {
	 set_bits(DDR(pwmPort),PIND4,PIND5);
	 set_bits(TCCR1A,WGM10,COM1A1,COM1B1);
	 set_bits(TCCR1B,WGM12,CS12,CS10);

 }

void Driver::moveA(int pwm)
{
	
	// Make saturation
	if (pwm > 255)
	{
		pwmA = 255;
	}
	else if (pwm < -255)
	{
		pwmA = -255;
	}
	else
	{
		pwmA = pwm;
	}

	// Checks direction and make the motor A moving
	if (pwmA > 0)
	{
		motor1.forward(pwm);
	}
	else if (pwmA < 0)
	{
		motor1.reverse(pwm);
	}
	else
	{
		this->stop_A();
	}
	
	OCR1A = pwm;

}

void Driver::moveB(int pwm)
{
	// Make saturation
	if (pwm > 255)
	{
		pwmB = 255;
	}
	else if (pwm < -255)
	{
		pwmB = -255;
	}
	else
	{
		pwmB = pwm;
	}

	// Checks direction and make the motor B moving
	if (pwmA > 0)
	{
		motor2.forward(pwm);
	}
	else if (pwmA < 0)
	{
		motor2.reverse(pwm);
	}
	else
	{
		this->stop_B();
	}
	
	OCR1B = pwm;

}

void Driver::stop_A()
{

	motor1.stop();
}

void Driver::stop_B()
{
	motor2.stop();
}
