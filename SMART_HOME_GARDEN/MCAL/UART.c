#include "UART.h"
#include <avr/interrupt.h>
#include <avr/io.h>

volatile unsigned char data;

void Uart_init(long BaudRate)
{
	UCSRB= (1<<TXEN)|(1<<RXCIE);
	UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	UBRRL=(unsigned char)(((F_CPU)/(16*BaudRate))-1);
}

void UART_send_byte( char byte)
{
	while(!(UCSRA &(1<<UDRE))); // while shift register flag != 1 (not empty))
	UDR=byte;
}


unsigned char uart_read (void)
{
	unsigned char return_data ;

	/* if new data came through uart
	     * it will be in the variable "data"
	     * then we put data to return data
	     * and then make data = 0
	     * to make sure that we get new data if it's not = 0
		*/
    return_data = data ;

	data = 0 ;

	return return_data ;
}

ISR(USART_RXC_vect)
{
	data = UDR ;
}
