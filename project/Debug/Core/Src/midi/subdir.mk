################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/midi/song.c \
../Core/Src/midi/tone.c 

OBJS += \
./Core/Src/midi/song.o \
./Core/Src/midi/tone.o 

C_DEPS += \
./Core/Src/midi/song.d \
./Core/Src/midi/tone.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/midi/%.o Core/Src/midi/%.su Core/Src/midi/%.cyclo: ../Core/Src/midi/%.c Core/Src/midi/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Core/Inc/demos -I../Core/Inc/devices -I../Core/Inc/midi -I../Core/Inc/system -I../Core/Inc/tests -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-midi

clean-Core-2f-Src-2f-midi:
	-$(RM) ./Core/Src/midi/song.cyclo ./Core/Src/midi/song.d ./Core/Src/midi/song.o ./Core/Src/midi/song.su ./Core/Src/midi/tone.cyclo ./Core/Src/midi/tone.d ./Core/Src/midi/tone.o ./Core/Src/midi/tone.su

.PHONY: clean-Core-2f-Src-2f-midi

