/*
 * board.h
 *
 * Created: 11/12/2019 1:11:15 AM
 *  Author: Galib
 */ 


#ifndef BOARD_H_
#define BOARD_H_

#include <avr/io.h>


//
//	Motor Control Pin
//
#define MOTOR1_PIN1	5
#define MOTOR1_PIN2	4
#define MOTOR2_PIN1	6
#define MOTOR2_PIN2	7
//
//	IMU Pin
//

#define MOTOR_PORT	PORTB


#define DMP_IRQ		2
#define IRQ_PORT	0
//
//	Sign of Life Pin
//
#define SOL_LED		13


#define BAUDRATE	115200U




#endif /* BOARD_H_ */