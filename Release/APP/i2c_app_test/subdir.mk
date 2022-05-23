################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/i2c_app_test/i2c_app.c 

OBJS += \
./APP/i2c_app_test/i2c_app.o 

C_DEPS += \
./APP/i2c_app_test/i2c_app.d 


# Each subdirectory must supply rules for building sources it contributes
APP/i2c_app_test/%.o: ../APP/i2c_app_test/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


