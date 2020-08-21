/*
 * dio.h
 *
 *  Created on: Aug 10, 2019
 *      Author: Ahmed M Salah
 */

#ifndef DIO_H_
#define DIO_H_

#define SYSTICK_DIO_SET_PIN_DIRECTION(DDR , BIT)        (DDR |= (1 << BIT))
#define SYSTICK_DIO_CLEAR_PIN_DIRECTION(DDR , BIT)      (DDR &=~ (1 << BIT))

#define SYSTICK_DIO_SET_DIRECTION(DDR , DIRECTION_VALUE)     (DDR = (1 << DIRECTION_VALUE))
#define SYSTICK_DIO_CLEAR_DIRECTION(DDR , DIRECTION_VALUE)   (DDR &=~ (1 << DIRECTION_VALUE))

#define SYSTICK_DIO_SET_PIN_PORT(PORT , BIT)        (PORT |= (1 << BIT))
#define SYSTICK_DIO_CLEAR_PIN_PORT(PORT , BIT)      (PORT &=~ (1 << BIT))
#define SYSTICK_DIO_TOGGLE_PIN_PORT(PORT , BIT)      (PORT ^= (1 << BIT))

#define SYSTICK_DIO_SET_PORT(PORT , PORT_VALUE)     (PORT = (1 << PORT_VALUE))
#define SYSTICK_DIO_CLEAR_PORT(PORT , PORT_VALUE)   (PORT &=~ (1 << PORT_VALUE))

#define SYSTICK_DIO_IS_BIT_SET(REGISTER , BIT)   (REGISTER & (1 << BIT))
#define SYSTICK_DIO_IS_BIT_CLEAR(REGISTER , BIT) (!(REGISTER & (1 << BIT)))

#define SYSTICK_DIO_SET_PIN_REGISTER(REGISTER , BIT)        (REGISTER |= (1 << BIT))
#define SYSTICK_DIO_CLEAR_PIN_REGISTER(REGISTER , BIT)      (REGISTER &=~ (1 << BIT))

void systick_dio_set_pin_direction(unsigned char direction_name , unsigned char pin_number);
void systick_dio_clear_pin_direction(unsigned char direction_name , unsigned char pin_number);

void systick_dio_set_direction(unsigned char direction_name , unsigned char direction_value);
void systick_dio_clear_direction(unsigned char direction_name , unsigned char direction_value);

unsigned char systick_dio_is_bit_set(unsigned char pin_name , unsigned char pin_number);
unsigned char systick_dio_is_bit_clear(unsigned char pin_name , unsigned char pin_number);

void systick_dio_set_pin_port(unsigned char port_name , unsigned char pin_number);
void systick_dio_clear_pin_port(unsigned char port_name , unsigned char pin_number);
void systick_dio_toggle_pin_port(unsigned char port_name , unsigned char pin_number);

void systick_dio_set_port(unsigned char port_name , unsigned char port_value);
void systick_dio_clear_port(unsigned char port_name , unsigned char port_value);

#endif /* DIO_H_ */
