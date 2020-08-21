################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/DS1307.c \
../HAL/LCD.c \
../HAL/light.c \
../HAL/rf.c \
../HAL/ultra2.c 

OBJS += \
./HAL/DS1307.o \
./HAL/LCD.o \
./HAL/light.o \
./HAL/rf.o \
./HAL/ultra2.o 

C_DEPS += \
./HAL/DS1307.d \
./HAL/LCD.d \
./HAL/light.d \
./HAL/rf.d \
./HAL/ultra2.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o: ../HAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


