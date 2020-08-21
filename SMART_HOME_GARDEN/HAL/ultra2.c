#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include "../MCAL/TIMER2.h"


int get_ultra_distance (void)
{
	unsigned  long pulse ;


	DDRD |= (1<<7);
	PORTD |= (1<<7);
	_delay_us(15);
	PORTD &= ~(1<<7);


	while((PIND & (1<<6))==0);
	timer_start();
	while((PIND & (1<<6)));

	timer_stop();
	pulse = timer_get_count();
	pulse = pulse * 0.000064 * 34500 ;
	timer_reset();

	return pulse/2 ;
}


