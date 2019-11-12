/*
* Driver.cpp
*
* Created: 11/8/2019 1:10:53 AM
*  Author: Galib
*/

#include "Driver.h"
#include "board.h"
#include "board.h"

MotorDriver motorA(MOTOR_PORT,MOTOR1_PIN1,MOTOR1_PIN2);
MotorDriver motorB(MOTOR_PORT,MOTOR2_PIN1,MOTOR2_PIN1);

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
		motorA.forward(pwm);
	}
	else if (pwmA < 0)
	{
		motorA.reverse(pwm);
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
		motorB.forward(pwm);
	}
	else if (pwmA < 0)
	{
		motorB.reverse(pwm);
	}
	else
	{
		stop_B();
	}
	
	OCR1B = pwm;

}

void Driver::stop_A()
{

	motorA.stop();
}

void Driver::stop_B()
{
	motorB.stop();
}
