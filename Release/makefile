################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/TIMER_0/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/LCD/subdir.mk
-include APP/POTENTIOMETER/subdir.mk
-include APP/LED_BLINKING_USING_TIMER0/subdir.mk
-include APP/LED_BLINK/subdir.mk
-include APP/LCD_TEST/subdir.mk
-include APP/BUTTON_LED_CONTROL/subdir.mk
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
avr_layered_architecture.lss \

FLASH_IMAGE += \
avr_layered_architecture.hex \

EEPROM_IMAGE += \
avr_layered_architecture.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: avr_layered_architecture.elf secondary-outputs

# Tool invocations
avr_layered_architecture.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,avr_layered_architecture.map -mmcu=atmega16 -o "avr_layered_architecture.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

avr_layered_architecture.lss: avr_layered_architecture.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S avr_layered_architecture.elf  >"avr_layered_architecture.lss"
	@echo 'Finished building: $@'
	@echo ' '

avr_layered_architecture.hex: avr_layered_architecture.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex avr_layered_architecture.elf  "avr_layered_architecture.hex"
	@echo 'Finished building: $@'
	@echo ' '

avr_layered_architecture.eep: avr_layered_architecture.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex avr_layered_architecture.elf  "avr_layered_architecture.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: avr_layered_architecture.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 avr_layered_architecture.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) avr_layered_architecture.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
