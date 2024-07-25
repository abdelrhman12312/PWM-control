/*
 * PWM.c
 *
 *  Created on: Feb 28, 2024
 *      Author: dell
 */

#include<avr/io.h>
#include"PWM.h"
#include"std_types.h"
#include"gpio.h"




void PWM_Timer0_Start(uint8 duty_cycle) {
	/* set a perscluer with CLK/8*/
	TCCR0 = (1<<WGM00) | (1<<WGM01) |(1<<COM01) |(1<<CS01);
	TCNT0=0; // iniate  with 0
	OCR0 = (float)((duty_cycle/100)*255);
	GPIO_setupPinDirection(PORTB_ID ,PIN3_ID , PIN_OUTPUT );
}
