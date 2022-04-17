################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/BUTTON_LED_CONTROL/button_led_control.c 

OBJS += \
./APP/BUTTON_LED_CONTROL/button_led_control.o 

C_DEPS += \
./APP/BUTTON_LED_CONTROL/button_led_control.d 


# Each subdirectory must supply rules for building sources it contributes
APP/BUTTON_LED_CONTROL/%.o: ../APP/BUTTON_LED_CONTROL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


