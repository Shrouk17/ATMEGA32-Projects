
#ifndef REGESTERS_H_
#define REGESTERS_H_

#define PINA *((volatile u8 *)0x39)
#define DDRA (*((u8 *)0x3A))
#define PORTA *((u8 *)0x3B)

#define PINB *((volatile u8 *)0x36)
#define DDRB *((u8 *)0x37)
#define PORTB *((u8 *)0x38)

#define PINC *((volatile u8 *)0x33)
#define DDRC *((u8 *)0x34)
#define PORTC *((u8 *)0x35)

#define PIND *((volatile u8 *)0x30)
#define DDRD *((u8 *)0x31)
#define PORTD *((u8 *)0x32)

#define SREG *((volatile u8 *)0x5F)
#define MCUCR *((volatile u8 *)0x55)
#define GICR *((volatile u8 *)0x5B)

#define TIFR *((volatile u8 *)0x58)

#define TCCR0 *((volatile u8 *)0x53)
#define TIMSK *((volatile u8 *)0x59)
#define OCR0 *((volatile u8 *)0x5C)

#define TCCR1A *((volatile u8 *)0x4F)
#define TCCR1B *((volatile u8 *)0x4E)
#define ICR1 *((volatile u16 *)0x46)
#define OCR1 *((volatile u16 *)0x4A)

#define ADCSRA *((volatile u8 *)0x26)
#define ADMUX  *((volatile u8 *)0x27)
#define ADCL  *((volatile u16 *)0x24)

#define UDR *((volatile u8 *)0x2C)
#define UCSRC *((volatile u8 *)0x40) // nfs 3nwan UBRRH
#define UBRRH *((volatile u8 *)0x40)
#define UBRRL *((volatile u8 *)0x29)

#define UCSRA *((volatile u8 *)0x2B)
#define UCSRB *((volatile u8 *)0x2A)

//SPI
#define SPCR *((volatile u8 *)0x2D)
#define SPSR *((volatile u8 *)0x2E)
#define SPDR *((volatile u8 *)0x2F)

#endif /* REGESTERS_H_ */
