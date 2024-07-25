/*
 * motordriver.c
 *
 *  Created on: Feb 25, 2024
 *      Author: Abdelrhman.H ahmed
 */
#include<avr/io.h>
#include "PWM.h"
#include"motordriver.h"
#include"gpio.h"
#include"std_types.h"

void DcMotor_Init(void) {
		TCNT0=0;
		OCR0=0;
		GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);
		TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01)| (1<<CS01);
	GPIO_setupPinDirection(MOTOR_DRIVER_PORT , MOTOR_DRIVER_PIN1 , PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_DRIVER_PORT , MOTOR_DRIVER_PIN2 , PIN_OUTPUT);
	GPIO_writePin(MOTOR_DRIVER_PORT , MOTOR_DRIVER_PIN1 , LOGIC_LOW);
	GPIO_writePin(MOTOR_DRIVER_PORT , MOTOR_DRIVER_PIN2 , LOGIC_LOW);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed) {
		switch(state)
		{
		case CW:
				GPIO_writePin(MOTOR_DRIVER_PORT , MOTOR_DRIVER_PIN1 , LOGIC_LOW);
				GPIO_writePin(MOTOR_DRIVER_PORT , MOTOR_DRIVER_PIN2 , LOGIC_HIGH);
		break;
		case A_CW:
				GPIO_writePin(MOTOR_DRIVER_PORT , MOTOR_DRIVER_PIN1 , LOGIC_HIGH);
				GPIO_writePin(MOTOR_DRIVER_PORT , MOTOR_DRIVER_PIN2 , LOGIC_LOW);
		break;
		case stop:
				GPIO_writePin(MOTOR_DRIVER_PORT , MOTOR_DRIVER_PIN1 , LOGIC_LOW);
				GPIO_writePin(MOTOR_DRIVER_PORT , MOTOR_DRIVER_PIN2 , LOGIC_LOW);
				break;
			default:
				break ;
		}
			uint8 duty_cycle = ((uint8) (((uint16) (speed * 255)) / 100));
			PWM_Timer0_Start(duty_cycle);
}
