/*
 * dio.c
 *
 *  Created on: Aug 10, 2019
 *      Author: Ahmed M Salah
 */

#include <avr/io.h>
//#include "dio_conf.h"
#include "dio.h"

void systick_dio_set_pin_direction(unsigned char direction_name , unsigned char pin_number)
{
	switch(direction_name)
	{
	case 'A':
		DDRA |= (1 << pin_number);break;
	case 'B':
		DDRB |= (1 << pin_number);break;
	case 'C':
		DDRC |= (1 << pin_number);break;
	case 'D':
		DDRD |= (1 << pin_number);break;
	default :break;
	}
}
void systick_dio_clear_pin_direction(unsigned char direction_name , unsigned char pin_number)
{
	switch(direction_name)
	{
	case 'A':
		DDRA &=~ (1 << pin_number);break;
	case 'B':
		DDRB &=~ (1 << pin_number);break;
	case 'C':
		DDRC &=~ (1 << pin_number);break;
	case 'D':
		DDRD &=~ (1 << pin_number);break;
	default :break;
	}
}

void systick_dio_set_direction(unsigned char direction_name , unsigned char direction_value)
{
	switch(direction_name)
	{
	case 'A':
		DDRA = direction_value;break;
	case 'B':
		DDRB = direction_value;break;
	case 'C':
		DDRC = direction_value;break;
	case 'D':
		DDRD = direction_value;break;
	default :break;
	}
}
void systick_dio_clear_direction(unsigned char direction_name , unsigned char direction_value)
{
	switch(direction_name)
	{
	case 'A':
		DDRA &=~ direction_value;break;
	case 'B':
		DDRB &=~ direction_value;break;
	case 'C':
		DDRC &=~ direction_value;break;
	case 'D':
		DDRD &=~ direction_value;break;
	default :break;
	}
}
unsigned char systick_dio_is_bit_set(unsigned char pin_name , unsigned char pin_number)
{
	unsigned char check_value = 0;
	switch(pin_name)
	{
	case 'A' : check_value = (PINA & (1 << pin_number));break;
	case 'B' : check_value = (PINB & (1 << pin_number));break;
	case 'C' : check_value = (PINC & (1 << pin_number));break;
	case 'D' : check_value = (PIND & (1 << pin_number));break;
	}
	return check_value;
}
unsigned char systick_dio_is_bit_clear(unsigned char pin_name , unsigned char pin_number)
{
	unsigned char check_value = 0;
	switch(pin_name)
	{
	case 'A' : check_value = (!(PINA & (1 << pin_number)));break;
	case 'B' : check_value = (!(PINB & (1 << pin_number)));break;
	case 'C' : check_value = (!(PINC & (1 << pin_number)));break;
	case 'D' : check_value = (!(PIND & (1 << pin_number)));break;
	}
	return check_value;
}
void systick_dio_set_pin_port(unsigned char port_name , unsigned char pin_number)
{
	switch(port_name)
	{
	case 'A':
		PORTA |= (1 << pin_number);break;
	case 'B':
		PORTB |= (1 << pin_number);break;
	case 'C':
		PORTC |= (1 << pin_number);break;
	case 'D':
		PORTD |= (1 << pin_number);break;
	default :break;
	}
}
void systick_dio_clear_pin_port(unsigned char port_name , unsigned char pin_number)
{
	switch(port_name)
	{
	case 'A':
		PORTA &=~ (1 << pin_number);break;
	case 'B':
		PORTB &=~ (1 << pin_number);break;
	case 'C':
		PORTC &=~ (1 << pin_number);break;
	case 'D':
		PORTD &=~ (1 << pin_number);break;
	default :break;
	}
}
void systick_dio_toggle_pin_port(unsigned char port_name , unsigned char pin_number)
{
	switch(port_name)
	{
	case 'A':
		PORTA ^= (1 << pin_number);break;
	case 'B':
		PORTB ^= (1 << pin_number);break;
	case 'C':
		PORTC ^= (1 << pin_number);break;
	case 'D':
		PORTD ^= (1 << pin_number);break;
	default :break;
	}
}

void systick_dio_set_port(unsigned char port_name , unsigned char port_value)
{
	switch(port_name)
	{
	case 'A':
		PORTA = port_value;break;
	case 'B':
		PORTB = port_value;break;
	case 'C':
		PORTC = port_value;break;
	case 'D':
		PORTD = port_value;break;
	default :break;
	}
}
void systick_dio_clear_port(unsigned char port_name , unsigned char port_value)
{
	switch(port_name)
	{
	case 'A':
		PORTA &=~ port_value;break;
	case 'B':
		PORTB &=~ port_value;break;
	case 'C':
		PORTC &=~ port_value;break;
	case 'D':
		PORTD &=~ port_value;break;
	default :break;
	}
}
