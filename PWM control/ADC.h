/*
 * ADC.h
 *
 *  Created on: Feb 19, 2024
 *      Author: Abdelrhman.H ahmed
 */
#ifndef ADC_H
#define ADC_H

#include"common_macros.h"
#include"std_types.h"


#define ADC_MAX_VAL 1023
#define ADC_VOLT_REF 2.56


typedef enum {
	  AREF , AVCC , Reserved , Internal
}ADC_ReferenceVolatge;



typedef enum {
	F_CPU2 = 1  , F_CPU3 , F_CPU4 , F_CPU8 , F_CPU16 ,
	F_CPU32 , F_CPU64 , F_CPU128
}ADC_Prescaler;



typedef struct {
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

void ADC_init(const ADC_ConfigType * Config_Ptr);


uint16 ADC_ReadChannel( uint8 channel );


#endif
