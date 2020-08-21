#include "../MCAL/UART.h"


void rf_init(void)
{
	Uart_init(9600);
}

void rf_send(char data)
{
	UART_send_byte(data);
}

unsigned char rf_read (void)
{
	return uart_read();
}
