################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Middlewares/Third_Party/FatFs/src/diskio.c \
../Core/Middlewares/Third_Party/FatFs/src/ff.c \
../Core/Middlewares/Third_Party/FatFs/src/ff_gen_drv.c 

OBJS += \
./Core/Middlewares/Third_Party/FatFs/src/diskio.o \
./Core/Middlewares/Third_Party/FatFs/src/ff.o \
./Core/Middlewares/Third_Party/FatFs/src/ff_gen_drv.o 

C_DEPS += \
./Core/Middlewares/Third_Party/FatFs/src/diskio.d \
./Core/Middlewares/Third_Party/FatFs/src/ff.d \
./Core/Middlewares/Third_Party/FatFs/src/ff_gen_drv.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Middlewares/Third_Party/FatFs/src/%.o Core/Middlewares/Third_Party/FatFs/src/%.su: ../Core/Middlewares/Third_Party/FatFs/src/%.c Core/Middlewares/Third_Party/FatFs/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Middlewares-2f-Third_Party-2f-FatFs-2f-src

clean-Core-2f-Middlewares-2f-Third_Party-2f-FatFs-2f-src:
	-$(RM) ./Core/Middlewares/Third_Party/FatFs/src/diskio.d ./Core/Middlewares/Third_Party/FatFs/src/diskio.o ./Core/Middlewares/Third_Party/FatFs/src/diskio.su ./Core/Middlewares/Third_Party/FatFs/src/ff.d ./Core/Middlewares/Third_Party/FatFs/src/ff.o ./Core/Middlewares/Third_Party/FatFs/src/ff.su ./Core/Middlewares/Third_Party/FatFs/src/ff_gen_drv.d ./Core/Middlewares/Third_Party/FatFs/src/ff_gen_drv.o ./Core/Middlewares/Third_Party/FatFs/src/ff_gen_drv.su

.PHONY: clean-Core-2f-Middlewares-2f-Third_Party-2f-FatFs-2f-src

