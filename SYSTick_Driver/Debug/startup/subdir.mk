################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32f303xe.s 

OBJS += \
./startup/startup_stm32f303xe.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -I"E:/Embbedded-C/RTOS_workspace/Systick_Driver/HAL_Driver/Inc/Legacy" -I"E:/Embbedded-C/RTOS_workspace/Systick_Driver/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"E:/Embbedded-C/RTOS_workspace/Systick_Driver/Middlewares/Third_Party/FreeRTOS/Source/include" -I"E:/Embbedded-C/RTOS_workspace/Systick_Driver/inc" -I"E:/Embbedded-C/RTOS_workspace/Systick_Driver/Utilities/STM32F3xx-Nucleo" -I"E:/Embbedded-C/RTOS_workspace/Systick_Driver/CMSIS/device" -I"E:/Embbedded-C/RTOS_workspace/Systick_Driver/CMSIS/core" -I"E:/Embbedded-C/RTOS_workspace/Systick_Driver/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"E:/Embbedded-C/RTOS_workspace/Systick_Driver/HAL_Driver/Inc" -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


