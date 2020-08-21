/*
 * LCD.h
 *
 *  Created on: Aug 8, 2019
 *      Author: Ahmed M Salah
 */

#ifndef LCD_H_
#define LCD_H_

#include "LCD_conf.h"

void systick_lcd_Init(void);
void systick_lcd_Send_Command(unsigned char command);
void systick_lcd_print_data(unsigned char data);
void systick_lcd_goto(unsigned char roe , unsigned char column);
void systick_lcd_print_string( char *string);
void systick_lcd_clear_screen(void);
void systick_lcd_print_number(unsigned char integer ,  char* string);

#endif /* LCD_H_ */
