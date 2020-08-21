################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/ADC.c \
../MCAL/I2C.c \
../MCAL/TIMER2.c \
../MCAL/UART.c \
../MCAL/dio.c \
../MCAL/pwm_v_2.c 

OBJS += \
./MCAL/ADC.o \
./MCAL/I2C.o \
./MCAL/TIMER2.o \
./MCAL/UART.o \
./MCAL/dio.o \
./MCAL/pwm_v_2.o 

C_DEPS += \
./MCAL/ADC.d \
./MCAL/I2C.d \
./MCAL/TIMER2.d \
./MCAL/UART.d \
./MCAL/dio.d \
./MCAL/pwm_v_2.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o: ../MCAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


