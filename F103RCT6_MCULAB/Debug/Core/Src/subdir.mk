################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/7seg.c \
../Core/Src/automatic.c \
../Core/Src/button.c \
../Core/Src/global.c \
../Core/Src/main.c \
../Core/Src/manual.c \
../Core/Src/matrix.c \
../Core/Src/s_button.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c \
../Core/Src/timer.c \
../Core/Src/traffic_light.c 

OBJS += \
./Core/Src/7seg.o \
./Core/Src/automatic.o \
./Core/Src/button.o \
./Core/Src/global.o \
./Core/Src/main.o \
./Core/Src/manual.o \
./Core/Src/matrix.o \
./Core/Src/s_button.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o \
./Core/Src/timer.o \
./Core/Src/traffic_light.o 

C_DEPS += \
./Core/Src/7seg.d \
./Core/Src/automatic.d \
./Core/Src/button.d \
./Core/Src/global.d \
./Core/Src/main.d \
./Core/Src/manual.d \
./Core/Src/matrix.d \
./Core/Src/s_button.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d \
./Core/Src/timer.d \
./Core/Src/traffic_light.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/7seg.cyclo ./Core/Src/7seg.d ./Core/Src/7seg.o ./Core/Src/7seg.su ./Core/Src/automatic.cyclo ./Core/Src/automatic.d ./Core/Src/automatic.o ./Core/Src/automatic.su ./Core/Src/button.cyclo ./Core/Src/button.d ./Core/Src/button.o ./Core/Src/button.su ./Core/Src/global.cyclo ./Core/Src/global.d ./Core/Src/global.o ./Core/Src/global.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/manual.cyclo ./Core/Src/manual.d ./Core/Src/manual.o ./Core/Src/manual.su ./Core/Src/matrix.cyclo ./Core/Src/matrix.d ./Core/Src/matrix.o ./Core/Src/matrix.su ./Core/Src/s_button.cyclo ./Core/Src/s_button.d ./Core/Src/s_button.o ./Core/Src/s_button.su ./Core/Src/stm32f1xx_hal_msp.cyclo ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.cyclo ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.cyclo ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su ./Core/Src/timer.cyclo ./Core/Src/timer.d ./Core/Src/timer.o ./Core/Src/timer.su ./Core/Src/traffic_light.cyclo ./Core/Src/traffic_light.d ./Core/Src/traffic_light.o ./Core/Src/traffic_light.su

.PHONY: clean-Core-2f-Src

