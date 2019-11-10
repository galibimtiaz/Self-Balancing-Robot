/*
 * Driver.h
 *
 * Created: 11/8/2019 12:30:56 AM
 *  Author: Galib
 */ 


#ifndef DRIVER_H_
#define DRIVER_H_


#include <avr/io.h>
#include "MotorDriver.h"
#include "led.h"

class Driver
{
	unsigned char PORT;
	int pwmA;
	int pwmB;
	
	public:
	Driver(unsigned char,unsigned char);
	void moveA(int);
	void moveB(int);
	void stop_A();
	void stop_B();
};




#endif /* DRIVER_H_ */