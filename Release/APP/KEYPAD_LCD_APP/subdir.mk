################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/KEYPAD_LCD_APP/keypad_LCD_app.c 

OBJS += \
./APP/KEYPAD_LCD_APP/keypad_LCD_app.o 

C_DEPS += \
./APP/KEYPAD_LCD_APP/keypad_LCD_app.d 


# Each subdirectory must supply rules for building sources it contributes
APP/KEYPAD_LCD_APP/%.o: ../APP/KEYPAD_LCD_APP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


