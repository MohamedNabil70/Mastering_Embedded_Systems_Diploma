################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/KPD_program.c \
../HAL/LCD_program.c 

OBJS += \
./HAL/KPD_program.o \
./HAL/LCD_program.o 

C_DEPS += \
./HAL/KPD_program.d \
./HAL/LCD_program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/KPD_program.o: ../HAL/KPD_program.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"M:/Study/SELF LEARNING/Mastering Embedded Systems/Diploma_direc/STM32CubeIDE/Drivers/HAL/inc" -I../Inc -I"M:/Study/SELF LEARNING/Mastering Embedded Systems/Diploma_direc/STM32CubeIDE/Drivers/STM32F103C8_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/KPD_program.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/LCD_program.o: ../HAL/LCD_program.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"M:/Study/SELF LEARNING/Mastering Embedded Systems/Diploma_direc/STM32CubeIDE/Drivers/HAL/inc" -I../Inc -I"M:/Study/SELF LEARNING/Mastering Embedded Systems/Diploma_direc/STM32CubeIDE/Drivers/STM32F103C8_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/LCD_program.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

