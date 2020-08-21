#include<util/delay.h>
#include "01-LIB/macros.h"
#include "01-LIB/types.h"
#include "02-MCAL/regesters.h"
#include "03-HAL/LCD.h"
#include "02-MCAL/DIO.h"
#include "02-MCAL/ADC.h"
#include "02-MCAL/UART.h"

enum{
	off,
	on
};
enum{
	FirstLED,
	SecoundLED,
	ThirdLEDPIRLDR,
	FirstIRGarage,
	SecoundIRGarage,
	Fan,
};

#define _INTR_ATTRS used,externally_visible

volatile u32 count=0,value,LDR,temp,pir;

/* Timer0 CTC Mode :
 *
 * in this interrupt the switching occurs between
 * Three ADC channels because it read from 1 channel at a time
 * First channel to read analog volt from LDR
 * Second channel to read analog volt from PIR motion sensor
 * based on first and second channels we turn on or of street lights if some thing is moving at night (save power)
 * Third  channel to read analog volt from LM35temperature sensor based on it we turn on Fan
 *
 * */
void __vector_10(void)__attribute__((signal,_INTR_ATTRS));
void __vector_10(void){

	++count;
	if(count==30){

		switch(ADMUX){
			case Channel0:

				ADMUX=Channel1;

				break;

			case Channel1:

				ADMUX=Channel2;

				break;
			case Channel2:

				ADMUX=Channel0;

				break;

			default:
				break;
		}
		count=0;
	}
}

/*	CallBack Function Called in ADC Interrupt
 *
 * We pass this function to ISR in ADC interrupt in MCAL layer
 * To read value when convergence occurs
 * Reading from 3 channels based in values we tack some actions
 */
void CallBack_ADCInterrupt(void){

	value=(ADCL & 0x3FF);

	switch(ADMUX){
		case Channel0:
			LDR = (u32)((u32)value*5000)/1023;
			LCD_vidSetPosition(0,0);
			LCD_vidWriteString((u8*)"LDR=");
			LCD_vidWriteNumber((u32)LDR);

	    	break;
		case Channel1:

			pir = (u32)((u32)value*5000)/1023;
			/*LCD_vidSetPosition(1,0);
			LCD_vidWriteString((u8*)"pir=");
			LCD_vidWriteNumber((u32)pir);*/

			if(LDR>4800 && pir> 3000){
				DIO_vidSetPinvalue(PORT_B,ThirdLEDPIRLDR,on);
			}
			else {
				DIO_vidSetPinvalue(PORT_B,ThirdLEDPIRLDR,off);
			}

			break;

		case Channel2:

			// tempreture  (digital * 5 / 1023 *1000) / 10  because 10 mv/1 c (degree) begine is zero

			temp = (u32)(value*500)/1023+ 0;

			LCD_vidSetPosition(1,0);
			LCD_vidWriteString((u8*)"tmp=");
			LCD_vidWriteNumber((u32)temp);

			if(temp>20){
				DIO_vidSetPinvalue(PORT_B,Fan,on);
			}
			else{
				DIO_vidSetPinvalue(PORT_B,Fan,off);
			}
			break;

		default:
			break;
	}

}


/*	Reading From bluetooth with baud rate 9600
 * Interrupt occurs when mobile device send to control LEDS with high voltage through Relays
 */
void __vector_13(void)__attribute__((signal,_INTR_ATTRS));
void __vector_13(void){

	u8 data =UDR;

	switch(data){
		case '1':
			DIO_vidSetPinvalue(PORT_B,FirstLED,on);
			break;
		case '2':
			DIO_vidSetPinvalue(PORT_B,SecoundLED,on);
			break;
		case '3':
			DIO_vidSetPinvalue(PORT_B,FirstLED,off);
			break;
		case '4':
			DIO_vidSetPinvalue(PORT_B,SecoundLED,off);
			break;
		default:
			break;
	}
	ClearBit(UCSRA,7);

}

void EnableCTCModeInTimer0(){

	//CTC Mode
	/*for Waveform Generation Mode (CTC mode)
	*set bit 3 (WGM01) and clear bit 6 (WGM00) in TCCR0 register*/
	SetBit(TCCR0,3);
	ClearBit(TCCR0,6);

	/*clock select prescaler with division factor 1024
	 *by assigning 100 to first 3 bits in TCCR0 register*/
	SetBit(TCCR0,0);
	ClearBit(TCCR0,1);
	SetBit(TCCR0,2);

	/*for Compare Output Mode (CTC) bits 4&5 for toggling OC0 on Compare Match*/
	SetBit(TCCR0,4);
	ClearBit(TCCR0,5);

	/*for Output Compare Match Interrupt Enable bit 1 (OCIE0) in TIMSK register*/
	SetBit(TIMSK,1);

	OCR0=255;

	//Time =(8000000/(255(OCR0)*1024(prescaler)))=125
	//enable global interrupt
	SetBit(SREG,7);

}

int main(void){

	LCD_vidInit();

	ADC_Init();

	ADCIntrrupt_Init();

	EnableCTCModeInTimer0();
	UART_Init();

	DIO_vidSetPortDirection(PORT_B,255);

	DIO_vidSetPinDirection(PORT_A,7,0);
		//DIO_vidSetPinDirection(PORT_A,6,0);
	DIO_vidSetPinvalue(PORT_A,7,1);
		//DIO_vidSetPinvalue(PORT_A,6,1);

	while(1){

		/*Sending My CallBackFunction to call it when ADC Interrupt come*/

		SetCallBackADCInterrupt(CallBack_ADCInterrupt);


		/* This section for garage to detect cars  */
		if(DIO_u8ReadPinValue(PORT_A,7)){

			DIO_vidSetPinvalue(PORT_B,FirstIRGarage,0);
		}
		else{
			DIO_vidSetPinvalue(PORT_B,FirstIRGarage,1);
		}
		/*if(DIO_u8ReadPinValue(PORT_A,6)){
			DIO_vidSetPinvalue(PORT_B,SecoundIRGarage,0);
		}
		else{
			DIO_vidSetPinvalue(PORT_B,SecoundIRGarage,1);

		}*/
	}

}
