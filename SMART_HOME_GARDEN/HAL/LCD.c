/*
 * LCD.c
 *
 *  Created on: Aug 8, 2019
 *      Author: Ahmed M Salah
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "LCD_conf.h"
#include "LCD.h"
#include "../MCAL/dio.h"

void systick_lcd_Init()
{
	systick_dio_set_pin_direction(LCD_CONTROL_DIR,ENABLE);
	systick_dio_set_pin_direction(LCD_CONTROL_DIR,RESET);

	systick_dio_set_pin_direction(LCD_DATA_DIR,PB0);
	systick_dio_set_pin_direction(LCD_DATA_DIR,PB1);
	systick_dio_set_pin_direction(LCD_DATA_DIR,PB2);
	systick_dio_set_pin_direction(LCD_DATA_DIR,PB3);

	_delay_ms(2);

	systick_lcd_Send_Command(RETURN_HOME);
	_delay_ms(2);
	systick_lcd_Send_Command(_4_BIT_2_LINE);
	_delay_ms(2);
	systick_lcd_Send_Command(CLEAR_DISPLAY);
	_delay_ms(2);
	systick_lcd_Send_Command(DISPLAY_ON_CURSOR_OFF);

	_delay_ms(50);
}
void systick_lcd_Send_Command(unsigned char command)
{
	command = ((command & 1) << 7) | ((command & 2) << 5) | ((command & 4) << 3) | ((command & 8) << 1) | ((command & 16) >> 1) | ((command & 32) >> 3) | ((command & 64) >> 5) | ((command & 128) >> 7);
	_delay_ms(50);
	systick_dio_clear_pin_port(LCD_CONTROL_PORT,RESET);
	_delay_ms(2);
	systick_dio_set_pin_port(LCD_CONTROL_PORT,ENABLE);
	_delay_ms(2);
	systick_dio_set_port(LCD_DATA_PORT,((command & 0x0F) | (1 << ENABLE)));
	_delay_ms(2);
	systick_dio_clear_pin_port(LCD_CONTROL_PORT,ENABLE);
	_delay_ms(2);
	systick_dio_clear_pin_port(LCD_CONTROL_PORT,RESET);
	_delay_ms(2);
	systick_dio_set_pin_port(LCD_CONTROL_PORT,ENABLE);
	_delay_ms(2);
	systick_dio_set_port(LCD_DATA_PORT,(((command >> 4) & 0x0F) | (1 << ENABLE)));
	_delay_ms(2);
	systick_dio_clear_pin_port(LCD_CONTROL_PORT,ENABLE);
	_delay_ms(2);
}
void systick_lcd_print_data(unsigned char data)
{
	data = ((data & 1) << 7) | ((data & 2) << 5) | ((data & 4) << 3) | ((data & 8) << 1) | ((data & 16) >> 1) | ((data & 32) >> 3) | ((data & 64) >> 5) | ((data & 128) >> 7);
	_delay_ms(2);
	systick_dio_set_pin_port(LCD_CONTROL_PORT,RESET);
	_delay_ms(2);
	systick_dio_set_pin_port(LCD_CONTROL_PORT,ENABLE);
	_delay_ms(2);
	systick_dio_set_port(LCD_DATA_PORT,((data & 0x0F) | (1 << RESET) | (1 << ENABLE)));
	_delay_ms(2);
	systick_dio_clear_pin_port(LCD_CONTROL_PORT,ENABLE);
	_delay_ms(2);
	systick_dio_set_pin_port(LCD_CONTROL_PORT,RESET);
	_delay_ms(2);
	systick_dio_set_pin_port(LCD_CONTROL_PORT,ENABLE);
	_delay_ms(2);
	systick_dio_set_port(LCD_DATA_PORT,(((data >> 4) & 0x0F) | (1 << RESET) | (1 << ENABLE)));
	_delay_ms(2);
	systick_dio_clear_pin_port(LCD_CONTROL_PORT,ENABLE);
}
void systick_lcd_goto(unsigned char row , unsigned char column)
{
	unsigned char address = 0;
	switch(row)
	{
	case 1 :address = (0x00 + column); break;
	case 2 :address = (0x40 + column); break;
	default : break;
	}
	systick_lcd_Send_Command(address | SET_CURSOR_LOCATION);
}
void systick_lcd_print_string(char *string)
{
	unsigned char string_counter = 0;
	while(string[string_counter] != '\0')
	{
		systick_lcd_print_data(string[string_counter]);
		string_counter++;
	}
}
void systick_lcd_clear_screen()
{
	systick_lcd_Send_Command(CLEAR_DISPLAY);
}
void systick_lcd_print_number(unsigned char integer ,  char* string)
{
	itoa(integer,string,10);
}
