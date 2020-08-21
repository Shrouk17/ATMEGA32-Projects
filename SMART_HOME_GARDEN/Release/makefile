################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/subdir.mk
-include HAL/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
SMART_HOME_GARDEN.lss \

FLASH_IMAGE += \
SMART_HOME_GARDEN.hex \

EEPROM_IMAGE += \
SMART_HOME_GARDEN.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: SMART_HOME_GARDEN.elf secondary-outputs

# Tool invocations
SMART_HOME_GARDEN.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SMART_HOME_GARDEN.map -mmcu=atmega32 -o "SMART_HOME_GARDEN.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SMART_HOME_GARDEN.lss: SMART_HOME_GARDEN.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SMART_HOME_GARDEN.elf  >"SMART_HOME_GARDEN.lss"
	@echo 'Finished building: $@'
	@echo ' '

SMART_HOME_GARDEN.hex: SMART_HOME_GARDEN.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SMART_HOME_GARDEN.elf  "SMART_HOME_GARDEN.hex"
	@echo 'Finished building: $@'
	@echo ' '

SMART_HOME_GARDEN.eep: SMART_HOME_GARDEN.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex SMART_HOME_GARDEN.elf  "SMART_HOME_GARDEN.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SMART_HOME_GARDEN.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SMART_HOME_GARDEN.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SMART_HOME_GARDEN.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
