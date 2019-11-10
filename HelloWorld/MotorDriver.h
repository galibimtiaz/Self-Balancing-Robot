/*
* MotorDriver.h
*
* Created: 11/3/2019 8:24:19 AM
*  Author: Galib
*/


#ifndef MOTORDRIVER_H_
#define MOTORDRIVER_H_

#include "macros.h"

class MotorDriver
{
	int pin1;
	int pin2;
	unsigned char PORT;
	int pwm;
	public:
	MotorDriver(unsigned char port,int pin1, int pin2);
	void forward(int pwm);
	void reverse(int pwm);
	void stop(void);
};



#endif /* MOTORDRIVER_H_ */