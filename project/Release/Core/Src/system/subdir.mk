################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/system/SysClock.c \
../Core/Src/system/printf.c \
../Core/Src/system/stm32l4xx_hal_msp.c \
../Core/Src/system/stm32l4xx_it.c \
../Core/Src/system/syscalls.c \
../Core/Src/system/sysmem.c \
../Core/Src/system/system_stm32l4xx.c \
../Core/Src/system/systick.c 

OBJS += \
./Core/Src/system/SysClock.o \
./Core/Src/system/printf.o \
./Core/Src/system/stm32l4xx_hal_msp.o \
./Core/Src/system/stm32l4xx_it.o \
./Core/Src/system/syscalls.o \
./Core/Src/system/sysmem.o \
./Core/Src/system/system_stm32l4xx.o \
./Core/Src/system/systick.o 

C_DEPS += \
./Core/Src/system/SysClock.d \
./Core/Src/system/printf.d \
./Core/Src/system/stm32l4xx_hal_msp.d \
./Core/Src/system/stm32l4xx_it.d \
./Core/Src/system/syscalls.d \
./Core/Src/system/sysmem.d \
./Core/Src/system/system_stm32l4xx.d \
./Core/Src/system/systick.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/system/%.o Core/Src/system/%.su Core/Src/system/%.cyclo: ../Core/Src/system/%.c Core/Src/system/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-system

clean-Core-2f-Src-2f-system:
	-$(RM) ./Core/Src/system/SysClock.cyclo ./Core/Src/system/SysClock.d ./Core/Src/system/SysClock.o ./Core/Src/system/SysClock.su ./Core/Src/system/printf.cyclo ./Core/Src/system/printf.d ./Core/Src/system/printf.o ./Core/Src/system/printf.su ./Core/Src/system/stm32l4xx_hal_msp.cyclo ./Core/Src/system/stm32l4xx_hal_msp.d ./Core/Src/system/stm32l4xx_hal_msp.o ./Core/Src/system/stm32l4xx_hal_msp.su ./Core/Src/system/stm32l4xx_it.cyclo ./Core/Src/system/stm32l4xx_it.d ./Core/Src/system/stm32l4xx_it.o ./Core/Src/system/stm32l4xx_it.su ./Core/Src/system/syscalls.cyclo ./Core/Src/system/syscalls.d ./Core/Src/system/syscalls.o ./Core/Src/system/syscalls.su ./Core/Src/system/sysmem.cyclo ./Core/Src/system/sysmem.d ./Core/Src/system/sysmem.o ./Core/Src/system/sysmem.su ./Core/Src/system/system_stm32l4xx.cyclo ./Core/Src/system/system_stm32l4xx.d ./Core/Src/system/system_stm32l4xx.o ./Core/Src/system/system_stm32l4xx.su ./Core/Src/system/systick.cyclo ./Core/Src/system/systick.d ./Core/Src/system/systick.o ./Core/Src/system/systick.su

.PHONY: clean-Core-2f-Src-2f-system

