################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/LCD_TEST/lcd_test_app.c 

OBJS += \
./APP/LCD_TEST/lcd_test_app.o 

C_DEPS += \
./APP/LCD_TEST/lcd_test_app.d 


# Each subdirectory must supply rules for building sources it contributes
APP/LCD_TEST/%.o: ../APP/LCD_TEST/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


