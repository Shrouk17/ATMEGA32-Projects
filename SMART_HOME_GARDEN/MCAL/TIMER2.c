
#include "TIMER2.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void timer_start (void)
{
	TCCR1A = 0 ;
	TCCR1B = (1<<CS10)|(1<<CS12);
}
void timer_stop (void)
{
	TCCR1B = 0 ;
}
unsigned long timer_get_count (void)
{
	return TCNT1 ;
}
void timer_reset(void)
{
	TCNT1 = 0 ;
}
