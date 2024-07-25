/*
 * motordriver.h
 *
 *  Created on: Feb 25, 2024
 *      Author: Abdelrhman.H ahmed
 */


#ifndef MOTOR_DRIVER
#define MOTOR_DRIVER


#include"PWM.h"
#include"gpio.h"
#include"std_types.h"

#define MOTOR_DRIVER_PORT  PORTB_ID
#define MOTOR_DRIVER_PIN1 PIN0_ID
#define MOTOR_DRIVER_PIN2 PIN1_ID


typedef enum {
	CW , A_CW , stop
}DcMotor_State;


void DcMotor_Init(void);

void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif
