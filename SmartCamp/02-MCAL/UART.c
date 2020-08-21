#include "../01-LIB/macros.h"
#include "../01-LIB/types.h"
#include "regesters.h"

void UART_Init(void){

	UCSRC =0b10000110;
	/*
	 * bit 7 = 1 to write UCSRC
	 * Select UART bit 6 =0
	 * bit 5 =0 & bit 4= 0 for no parity
	 * bit 3 =0 one stop bit
	 * bit 1 = 1 bit 2 = 1 for 8 bit mode
	 */
	/*
	 * in UCSRB
	 * bit 2 =0 relative to 8 bit mode
	 *bit 4 =0  resave enable & bit 3 =1 transmit enable
	 *set bit 6 & 7 to enable Inttrupt
	 */
	ClearBit(UCSRB,2);
	SetBit(UCSRB,3);
	SetBit(UCSRB,4);
	SetBit(UCSRB,6);
	SetBit(UCSRB,7);
	/*
	 * U2X bit 1 in UCSRA = 1 to controal BudRate 8
	 */
	SetBit(UCSRA,1);
	UBRRL=0x67;
	UBRRH=0x00;

}

void UART_vidSend(u8 data){

	/*
	 * awl ma y5alsb3t bykon el flag =1
	 *
	 */
	UDR=data;
	while(GetBit(UCSRA,5)==0);

}

u8 UART_u8Resive(void){

	/*
	 * awl ma yst2bl bykon el flag =1
	 *
	 */
	while(GetBit(UCSRA,7)==0);

	return UDR;
}
