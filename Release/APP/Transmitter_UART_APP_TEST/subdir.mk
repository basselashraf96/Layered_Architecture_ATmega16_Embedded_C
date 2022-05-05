################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/Transmitter_UART_APP_TEST/uart_app_test.c 

OBJS += \
./APP/Transmitter_UART_APP_TEST/uart_app_test.o 

C_DEPS += \
./APP/Transmitter_UART_APP_TEST/uart_app_test.d 


# Each subdirectory must supply rules for building sources it contributes
APP/Transmitter_UART_APP_TEST/%.o: ../APP/Transmitter_UART_APP_TEST/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


