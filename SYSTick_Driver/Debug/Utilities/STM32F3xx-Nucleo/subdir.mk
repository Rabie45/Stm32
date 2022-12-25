################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Utilities/STM32F3xx-Nucleo/stm32f3xx_nucleo.c 

OBJS += \
./Utilities/STM32F3xx-Nucleo/stm32f3xx_nucleo.o 

C_DEPS += \
./Utilities/STM32F3xx-Nucleo/stm32f3xx_nucleo.d 


# Each subdirectory must supply rules for building sources it contributes
Utilities/STM32F3xx-Nucleo/%.o: ../Utilities/STM32F3xx-Nucleo/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F3 -DSTM32F30 -DSTM32F303RETx -DNUCLEO_F303RE -DDEBUG -DSTM32F303xE -DUSE_HAL_DRIVER -DUSE_RTOS_SYSTICK -I"E:/Embbedded-C/RTOS_workspace/Systick_Driver/HAL_Driver/Inc/Legacy" -I"E:/Embbedded-C/RTOS_workspace/Systick_Driver/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"E:/Embbedded-C/RTOS_workspace/Systick_Driver/Middlewares/Third_Party/FreeRTOS/Source/include" -I"E:/Embbedded-C/RTOS_workspace/Systick_Driver/inc" -I"E:/Embbedded-C/RTOS_workspace/Systick_Driver/Utilities/STM32F3xx-Nucleo" -I"E:/Embbedded-C/RTOS_workspace/Systick_Driver/CMSIS/device" -I"E:/Embbedded-C/RTOS_workspace/Systick_Driver/CMSIS/core" -I"E:/Embbedded-C/RTOS_workspace/Systick_Driver/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"E:/Embbedded-C/RTOS_workspace/Systick_Driver/HAL_Driver/Inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


