
#ifndef ADC_H_
#define ADC_H_

void ADC_Init(void);
u8 ADC_u8GetResult(u16 * result);
void SetCallBackADCInterrupt(void (*fun)(void));
void ADCIntrrupt_Init(void);

enum{
	Channel0,
	Channel1,
	Channel2,
	Channel3,
	Channel4,
	Channel5,
	Channel6,
	Channel7
};

#endif /* ADC_H_ */
