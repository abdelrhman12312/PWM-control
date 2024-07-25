/*
 * ADC.c
 *
 *  Created on: Feb 19, 2024
 *      Author: dell
 */

#include<avr/io.h>
#include"ADC.h"
#include "common_macros.h"
#include"std_types.h"




void ADC_init(const ADC_ConfigType * Config_Ptr) {
	//ADMUX = 0 ;
	ADMUX = (Config_Ptr->ref_volt)<<6;
	SET_BIT(ADCSRA,ADEN);
	ADCSRA = (ADCSRA & 0xf8 ) | Config_Ptr->prescaler;
}

uint16 ADC_ReadChannel( uint8 channel ) {

	channel &= 0x07;
	ADMUX &=0xE0;
	ADMUX = ADMUX | channel;

	SET_BIT(ADCSRA,ADSC);
   while( BIT_IS_CLEAR(ADCSRA,ADIF));
    SET_BIT(ADCSRA,ADIF);

    return ADC;
}
