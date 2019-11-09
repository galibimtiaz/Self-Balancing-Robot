/*
 * Driver.h
 *
 * Created: 11/8/2019 12:30:56 AM
 *  Author: Galib
 */ 


#ifndef DRIVER_H_
#define DRIVER_H_

#include "MotorDriver.h"
#include <avr/io.h>


class Driver
{
	MotorDriver motor1(0x05,0,1);
	MotorDriver motor2(0x05,2,3);
	unsigned char PORT;
	int pwmA;
	int pwmB;
	
	public:
	Driver(unsigned char motorPort,unsigned char pwmPort);
	void moveA(int pwm);
	void moveB(int pwm);
	void stop_A();
	void stop_B();
};




#endif /* DRIVER_H_ */