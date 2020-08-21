#include"../01-LIB/types.h"
#include"regesters.h"
#include"../01-LIB/macros.h"
#include"ADC.h"

#define Null (void *) 0
void (*ptr)(void)=Null;

void ADC_Init(void){

	ADMUX=Channel0;
	//prescaler for ADC
	SetBit(ADCSRA,0);
	//ClearBit(ADCSRA,0);
	SetBit(ADCSRA,1);
	SetBit(ADCSRA,2);

	// ADC Enable
	SetBit(ADCSRA,7);
	// ADCIntterupt  Enable
	SetBit(ADCSRA,3);
	//Start conversion (Single conversion mode or free running)
	SetBit(ADCSRA,6);
}


u8 ADC_u8GetResult(u16 * result){

	u8 status=0;

	if(GetBit(ADCSRA,4)==1){
		*result=(ADCL & 0x3FF); // anding

		// Clear flag
		SetBit(ADCSRA,4);

		//Start conversion (Single conversion mode or free running)
		SetBit(ADCSRA,6);

		status=1;
	}
	return status;
}

void ADCIntrrupt_Init(void){

	// global interrupt
	SetBit(SREG,7);
	//Enable ADC Interrupt
	SetBit(ADCSRA,3);

}

#define _INTR_ATTRS used,externally_visible

void __vector_16(void)__attribute__((signal,_INTR_ATTRS));
void __vector_16(void){

	//Start conversion (Single conversion mode or free running)
	SetBit(ADCSRA,6);
	ptr();

}

void SetCallBackADCInterrupt(void (*fun)(void)){

	ptr=fun;

}










