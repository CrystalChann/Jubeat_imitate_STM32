################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Middlewares/Third_Party/FatFs/src/option/ccsbcs.c \
../Core/Middlewares/Third_Party/FatFs/src/option/syscall.c 

OBJS += \
./Core/Middlewares/Third_Party/FatFs/src/option/ccsbcs.o \
./Core/Middlewares/Third_Party/FatFs/src/option/syscall.o 

C_DEPS += \
./Core/Middlewares/Third_Party/FatFs/src/option/ccsbcs.d \
./Core/Middlewares/Third_Party/FatFs/src/option/syscall.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Middlewares/Third_Party/FatFs/src/option/%.o Core/Middlewares/Third_Party/FatFs/src/option/%.su: ../Core/Middlewares/Third_Party/FatFs/src/option/%.c Core/Middlewares/Third_Party/FatFs/src/option/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Middlewares-2f-Third_Party-2f-FatFs-2f-src-2f-option

clean-Core-2f-Middlewares-2f-Third_Party-2f-FatFs-2f-src-2f-option:
	-$(RM) ./Core/Middlewares/Third_Party/FatFs/src/option/ccsbcs.d ./Core/Middlewares/Third_Party/FatFs/src/option/ccsbcs.o ./Core/Middlewares/Third_Party/FatFs/src/option/ccsbcs.su ./Core/Middlewares/Third_Party/FatFs/src/option/syscall.d ./Core/Middlewares/Third_Party/FatFs/src/option/syscall.o ./Core/Middlewares/Third_Party/FatFs/src/option/syscall.su

.PHONY: clean-Core-2f-Middlewares-2f-Third_Party-2f-FatFs-2f-src-2f-option

