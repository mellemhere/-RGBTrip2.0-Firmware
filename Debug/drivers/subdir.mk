################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_enet.c \
../drivers/fsl_ftfx_cache.c \
../drivers/fsl_ftfx_controller.c \
../drivers/fsl_ftfx_flash.c \
../drivers/fsl_ftfx_flexnvm.c \
../drivers/fsl_ftm.c \
../drivers/fsl_gpio.c \
../drivers/fsl_sim.c \
../drivers/fsl_smc.c \
../drivers/fsl_uart.c 

OBJS += \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_enet.o \
./drivers/fsl_ftfx_cache.o \
./drivers/fsl_ftfx_controller.o \
./drivers/fsl_ftfx_flash.o \
./drivers/fsl_ftfx_flexnvm.o \
./drivers/fsl_ftm.o \
./drivers/fsl_gpio.o \
./drivers/fsl_sim.o \
./drivers/fsl_smc.o \
./drivers/fsl_uart.o 

C_DEPS += \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_enet.d \
./drivers/fsl_ftfx_cache.d \
./drivers/fsl_ftfx_controller.d \
./drivers/fsl_ftfx_flash.d \
./drivers/fsl_ftfx_flexnvm.d \
./drivers/fsl_ftm.d \
./drivers/fsl_gpio.d \
./drivers/fsl_sim.d \
./drivers/fsl_smc.d \
./drivers/fsl_uart.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DPRINTF_ADVANCED_ENABLE=1 -DFRDM_K64F -DFREEDOM -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\drivers" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\board" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\source" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\contrib\apps\ping" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\CMSIS" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\device" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\port\arch" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\compat\posix\arpa" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\compat\posix\net" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\compat\posix" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\compat\posix\sys" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\compat\stdc" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\lwip" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\lwip\priv" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\lwip\prot" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\netif" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\netif\ppp" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\netif\ppp\polarssl" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\utilities" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\port" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\component\serial_manager" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\component\lists" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\component\uart" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\board" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\source" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\drivers" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\device" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\CMSIS" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\contrib\apps\ping" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\port\arch" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\compat\posix\arpa" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\compat\posix\net" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\compat\posix" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\compat\posix\sys" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\compat\stdc" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\lwip" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\lwip\priv" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\lwip\prot" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\netif" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\netif\ppp" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\netif\ppp\polarssl" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\port" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\utilities" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\component\serial_manager" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\component\lists" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\component\uart" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include" -O0 -fno-common -g3 -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


