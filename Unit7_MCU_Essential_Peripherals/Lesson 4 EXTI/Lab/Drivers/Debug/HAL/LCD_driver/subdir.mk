################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LCD_driver/LCD_program.c 

OBJS += \
./HAL/LCD_driver/LCD_program.o 

C_DEPS += \
./HAL/LCD_driver/LCD_program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LCD_driver/LCD_program.o: ../HAL/LCD_driver/LCD_program.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"M:/Study/SELF LEARNING/Mastering Embedded Systems/Diploma_direc/STM32CubeIDE/Drivers/STM32F103C6_Drivers/inc" -I"M:/Study/SELF LEARNING/Mastering Embedded Systems/Diploma_direc/STM32CubeIDE/Drivers/HAL/KeyPad_driver" -I"M:/Study/SELF LEARNING/Mastering Embedded Systems/Diploma_direc/STM32CubeIDE/Drivers/HAL/LCD_driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/LCD_driver/LCD_program.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

