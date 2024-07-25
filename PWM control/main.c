/*
 * main.c
 *
 *  Created on: Feb 28, 2024
 *      Author: Abdelrhman.H ahmed
 */

#include"lcd.h"
#include"motordriver.h"
#include"lm35_sensor.h"
#include"std_types.h"
#include"PWM.h"


#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "motordriver.h"
void main(void) {
	uint8 temperature;
	ADC_ConfigType ADC_Config = { Internal,
			F_CPU8 };
	ADC_init(&ADC_Config);
	LCD_init();
	DcMotor_Init();
	LCD_displayStringRowColumn(0, 3, "Fan is ");
	LCD_displayStringRowColumn(1, 2, "Temp = ");
	LCD_displayStringRowColumn(1, 13, "C");

	while (1) {
		temperature = LM35_getTemperature();
		LCD_moveCursor(1, 9);

		if (temperature < 30) {
			DcMotor_Rotate(stop, 0);
			LCD_intgerToString(temperature);
			LCD_displayCharacter(' ');
			LCD_displayStringRowColumn(0, 10, "OFF");
		} else if ((temperature >= 30) && (temperature < 60)) {
			DcMotor_Rotate(CW, 25);
			LCD_intgerToString(temperature);
			LCD_displayCharacter(' ');
			LCD_displayStringRowColumn(0, 10, "ON");
			LCD_displayCharacter(' ');
		} else if ((temperature >= 60) && (temperature < 90)) {
			DcMotor_Rotate(CW, 50);
			LCD_intgerToString(temperature);
			LCD_displayCharacter(' ');
			LCD_displayStringRowColumn(0, 10, "ON");
			LCD_displayCharacter(' ');
		} else if ((temperature >= 90) && (temperature < 120)) {
			DcMotor_Rotate(CW, 75);
			LCD_intgerToString(temperature);
			LCD_displayCharacter(' ');
			LCD_displayStringRowColumn(0, 10, "ON");
			LCD_displayCharacter(' ');
		}  else if (temperature >= 120) {
			DcMotor_Rotate(CW, 100);
			LCD_intgerToString(temperature);
			LCD_displayStringRowColumn(0, 10, "ON");
			LCD_displayCharacter(' ');
		}
	}

}
