

#ifndef UART_H_
#define UART_H_

#include <avr/io.h>

void Uart_init(long BaudRate);
void UART_send_byte( char byte);
void UART_send_string( char *ptr,int size);
char UART_recieve_byte(void);
void UART_recieve_string( char *ptr);
void uart_callback (void(*ptr)(void));
unsigned char uartread (void);

unsigned char uart_read (void);



#endif 
