
#ifndef MACROS_H_
#define MACROS_H_

#define SetBit(reg,bit) reg|=(1<<bit)
#define ClearBit(reg,bit) reg&=(~(1<<bit))
#define TogleBit(reg,bit) reg^=(1<<bit)
#define GetBit(reg,bit) ((reg>>bit)&1)

#endif /* MACROS_H_ */
