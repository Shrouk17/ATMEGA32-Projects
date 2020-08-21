################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../02-MCAL/ADC.c \
../02-MCAL/DIO.c \
../02-MCAL/UART.c 

OBJS += \
./02-MCAL/ADC.o \
./02-MCAL/DIO.o \
./02-MCAL/UART.o 

C_DEPS += \
./02-MCAL/ADC.d \
./02-MCAL/DIO.d \
./02-MCAL/UART.d 


# Each subdirectory must supply rules for building sources it contributes
02-MCAL/%.o: ../02-MCAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


