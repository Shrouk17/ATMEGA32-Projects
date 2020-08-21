/*
 * _ADC.c
 *
 *  Created on: Oct 10, 2019
 *      Author: amd
 */


#include <avr/io.h>

#include "adc.h"

void ADC_Init(void)
{

/*
first we make the internal voltag the adc refernce voltag from the bits " REFS 1:0 "
in ADMUX REGISTER

SO  REFS1 = 0
    REFS0 = 1

and set the rest to zero

*/

	ADMUX = 0b01000000;

	/* Bits Description:
	 * ADEN=1 enable ADC
	 * ADPS2:0=011 to choose ADC_Clock=F_CPU/8=      16Mhz/ 128  =  125Khz --> ADC must operate in range 50-200Khz
         *from ADCSRA register
	 */



	ADCSRA = (1<<ADEN) | (1<<ADPS1) | (1<<ADPS0) |(1<<ADPS2);
}

unsigned short ADC_Read(unsigned char channel_num)
{
	channel_num &=0x07; //must be from 0 --> 7

	ADMUX &= 0xE0; //clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel

	ADMUX = ADMUX | channel_num; //choose the correct channel by setting the channel number in MUX4:0 bits

	ADCSRA |= (1<<ADSC); //start conversion write '1' to ADSC

	while(!(ADCSRA & (1<<ADIF))); // wait for conversion to complete ADIF becomes '1'

	ADCSRA |=(1<<ADIF); //clear ADIF by write'1' to it :)

	return ADC; //return the data register
}
