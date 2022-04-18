################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/TIMER_0/timer0.c 

OBJS += \
./MCAL/TIMER_0/timer0.o 

C_DEPS += \
./MCAL/TIMER_0/timer0.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/TIMER_0/%.o: ../MCAL/TIMER_0/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


