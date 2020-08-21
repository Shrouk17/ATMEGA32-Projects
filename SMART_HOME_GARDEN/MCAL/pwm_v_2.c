#include <avr/io.h>
#include <avr/interrupt.h>
#include "pwm_v_2.h"

void (*overflow_callback)(void); // call back pointer to overflow function 
void (*compare_callback)(void);  // call back pointer to compare match function


void pwm_init (void)
{
	/*
	in this function we will choose the prescaler and 
	we will choose the waveform 
	and enable the interrupt for compare match and overflow
	*/
	
	
	TCNT0 = 0 ; // to make sure timer0 will count from 0 ;
	OCR0 = 128 ;  // by that we set the initial duty cycle to 50% 
	
	TIMSK = (1<<TOIE0) |(1<<OCIE0); // ENABLE TIMER FOR OVERFLOW AND COMPARE MATCH
	
	TCCR0 = (1<<WGM00)|(1<<WGM01); // by setting these bits to one we enable 
	                               // the the timer in pwm mode 
								   // check page 80 in the data sheet
	TCCR0 |= (1<<CS00)|(1<<CS01); // by setting these bits to one we set the prescaler to                   
	                             // clk/64 and timer start counting
	/*
    as you can see the other bits of the control register is set to zero
    COM01 and COM00  and that includes the output compare match channels 
    because we are not using the pin(PB3) that is controlled by timer 0	
	*/
	
	sei();  // enable global interrupt 
}

void pwm_SetDutyCycle (unsigned char duty)
{
	
	OCR0 = duty ; // set duty cycle to the wanted value 
}

void Pwm_setcallback_comparematch (void(*ptr)(void))
{
	compare_callback = ptr ;  // make the call back pointer 
	                          // points to passed function 
	
}	

void Pwm_setcallback_overflow (void(*ptr)(void))
{
	overflow_callback = ptr ; // make the call back pointer 
	                          // points to passed function 
}


ISR(TIMER0_OVF_vect)
{
overflow_callback() ;   // overflow interrupt service routine will excute the funtion 
                         // that the callback pointer is pointing to 
}


ISR(TIMER0_COMP_vect)
{
compare_callback();
// compare interrupt service routine will excute the funtion 
                         // that the callback pointer is pointing to 
}

