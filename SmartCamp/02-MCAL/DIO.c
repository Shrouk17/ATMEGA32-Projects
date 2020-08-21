#include"../01-LIB/macros.h"
#include"../01-LIB/types.h"
#include"regesters.h"
#include "DIO.h"



/* begin of DIO_vidSetPortDirection function*/
void DIO_vidSetPortDirection(u8 portNumber , u8 value){

	switch(portNumber){

		case PORT_A:
			DDRA=value;
			break;

		case PORT_B:
			DDRB=value;
			break;

		case PORT_C:
			DDRC=value;
			break;

		case port_D:
			DDRD=value;
			break;
	}
}/* end of DIO_vidSetPortDirection function*/


/* begin of DIO_vidSetPortValue function*/
void DIO_vidSetPortValue(u8 portNumber , u8 value){

	switch(portNumber){

		case PORT_A:
			PORTA=value;
			break;

		case PORT_B:
			PORTB=value;
			break;

		case PORT_C:
			PORTC=value;
			break;

		case port_D:
			PORTD=value;
			break;
	}
}/* end of DIO_vidSetPortValue function*/


/* begin of DIO_u8ReadPintValue function*/
u8 DIO_u8ReadPintValue(u8 portNumber){


	switch(portNumber){

		case PORT_A:
			return PINA;
			break;

		case PORT_B:
			return PINB;
			break;

		case PORT_C:
			return PINC;
			break;

		case port_D:
			return PIND;
			break;
	}
	return 0;
}/* end of DIO_u8ReadPintValue function*/


/* begin of DIO_vidSetPinDirection function*/
void DIO_vidSetPinDirection(u8 portNumber ,u8 pin , u8 value){

	switch(portNumber){

		case PORT_A:
			if(value==1){
				SetBit(DDRA,pin);
			}
			else if(value==0){
				ClearBit(DDRA,pin);
			}
			break;

		case PORT_B:
			if(value==1){
				SetBit(DDRB,pin);
			}
			else if(value==0){
				ClearBit(DDRB,pin);
			}
			break;

		case PORT_C:
			if(value==1){
				SetBit(DDRC,pin);
			}
			else if(value==0){
				ClearBit(DDRC,pin);
			}
			break;

		case port_D:
			if(value==1){
				SetBit(DDRD,pin);
			}
			else if(value==0){
				ClearBit(DDRD,pin);
			}
			break;
	}
}/* end of DIO_vidSetPinDirection function*/


/* begin of DIO_vidSetPinvalue function*/
void DIO_vidSetPinvalue(u8 portNumber ,u8 pin , u8 value){

	switch(portNumber){

		case PORT_A:
			if(value==1){
				SetBit(PORTA,pin);
			}
			else if(value==0){
				ClearBit(PORTA,pin);
			}
			break;

		case PORT_B:
			if(value==1){
				SetBit(PORTB,pin);
			}
			else if(value==0){
				ClearBit(PORTB,pin);
			}
			break;

		case PORT_C:
			if(value==1){
				SetBit(PORTC,pin);
			}
			else if(value==0){
				ClearBit(PORTC,pin);
			}
			break;

		case port_D:
			if(value==1){
				SetBit(PORTD,pin);
			}
			else if(value==0){
				ClearBit(PORTD,pin);
			}
			break;
	}
}/* end of DIO_vidSetPinvalue function*/


/* begin of DIO_u8ReadPinValue function*/
u8 DIO_u8ReadPinValue(u8 portNumber,u8 pin){

	switch(portNumber){

		case PORT_A:
			return GetBit(PINA,pin);
			break;

		case PORT_B:
			return GetBit(PINB,pin);
			break;

		case PORT_C:
			return GetBit(PINC,pin);
			break;

		case port_D:
			return GetBit(PIND,pin);
			break;
	}
	return 0;
}/* end of DIO_u8ReadPinValue function*/


