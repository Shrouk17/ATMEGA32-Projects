#ifndef LCD_CFG_H_
#define LCD_CFG_H_

/*
 * we use this part because we can use MCAL "Micro Controller Abstraction layer" in all types and for any
 * kind of "tosyla hardwire" just write the port number that you connected it with LCD in LCD_DataPort
 * and just write the port number that you connected it with LCD to control in LCD_ControlPort
 *
 * */
#define LCD_8bit 1

#define LCD_DataPort 2

#define LCD_ControlPort 3

#define RS 7

#define RW 6

#define E 5

#endif /* LCD_CFG_H_ */
