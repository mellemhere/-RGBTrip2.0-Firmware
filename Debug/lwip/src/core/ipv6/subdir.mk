################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lwip/src/core/ipv6/dhcp6.c \
../lwip/src/core/ipv6/ethip6.c \
../lwip/src/core/ipv6/icmp6.c \
../lwip/src/core/ipv6/inet6.c \
../lwip/src/core/ipv6/ip6.c \
../lwip/src/core/ipv6/ip6_addr.c \
../lwip/src/core/ipv6/ip6_frag.c \
../lwip/src/core/ipv6/mld6.c \
../lwip/src/core/ipv6/nd6.c 

OBJS += \
./lwip/src/core/ipv6/dhcp6.o \
./lwip/src/core/ipv6/ethip6.o \
./lwip/src/core/ipv6/icmp6.o \
./lwip/src/core/ipv6/inet6.o \
./lwip/src/core/ipv6/ip6.o \
./lwip/src/core/ipv6/ip6_addr.o \
./lwip/src/core/ipv6/ip6_frag.o \
./lwip/src/core/ipv6/mld6.o \
./lwip/src/core/ipv6/nd6.o 

C_DEPS += \
./lwip/src/core/ipv6/dhcp6.d \
./lwip/src/core/ipv6/ethip6.d \
./lwip/src/core/ipv6/icmp6.d \
./lwip/src/core/ipv6/inet6.d \
./lwip/src/core/ipv6/ip6.d \
./lwip/src/core/ipv6/ip6_addr.d \
./lwip/src/core/ipv6/ip6_frag.d \
./lwip/src/core/ipv6/mld6.d \
./lwip/src/core/ipv6/nd6.d 


# Each subdirectory must supply rules for building sources it contributes
lwip/src/core/ipv6/%.o: ../lwip/src/core/ipv6/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DPRINTF_ADVANCED_ENABLE=1 -DFRDM_K64F -DFREEDOM -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\component\serial_manager" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\drivers" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\CMSIS" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\contrib\apps\ping" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\component\uart" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\port" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\board" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\source" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\device" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\port\arch" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\compat\posix\arpa" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\compat\posix\net" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\compat\posix" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\compat\posix\sys" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\compat\stdc" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\lwip" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\lwip\priv" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\lwip\prot" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\netif" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\netif\ppp" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\netif\ppp\polarssl" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\component\lists" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\utilities" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\drivers" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\board" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\source" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\contrib\apps\ping" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\CMSIS" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\device" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\port\arch" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\compat\posix\arpa" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\compat\posix\net" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\compat\posix" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\compat\posix\sys" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\compat\stdc" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\lwip" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\lwip\priv" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\lwip\prot" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\netif" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\netif\ppp" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include\netif\ppp\polarssl" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\utilities" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\port" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\component\serial_manager" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\component\lists" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\component\uart" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm\lwip\src\include" -I"D:\nxp\new_workspace\frdmk64f_mqtt_test_lwip_ping_bm" -O0 -fno-common -g3 -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


