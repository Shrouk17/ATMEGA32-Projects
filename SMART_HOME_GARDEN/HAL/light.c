#include "../MCAL/adc.h"

void light_init(void)
{

ADC_Init();
}


int light_read(void)
{

	return ADC_Read(1);
}

