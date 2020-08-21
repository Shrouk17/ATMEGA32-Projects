
#ifndef DIO_H_
#define DIO_H_

enum{
	PORT_A,
	PORT_B,
	PORT_C,
	port_D
};
enum stat{
	input,
	output
};

void DIO_vidSetPortDirection(u8 portNumber , u8 value);
void DIO_vidSetPortValue(u8 portNumber , u8 value);
u8 DIO_u8ReadPintValue(u8 portNumber);
void DIO_vidSetPinvalue(u8 portNumber ,u8 pin , u8 value);
void DIO_vidSetPinDirection(u8 portNumber ,u8 pin , u8 value);
u8 DIO_u8ReadPinValue(u8 portNumber,u8 pin);

#endif /* DIO_H_ */
