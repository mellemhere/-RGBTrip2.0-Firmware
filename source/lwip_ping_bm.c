/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2019 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "lwip/opt.h"

#if LWIP_IPV4 && LWIP_RAW

#include "ping.h"
#include "lwip/timeouts.h"
#include "lwip/init.h"
#include "netif/ethernet.h"
#include "enet_ethernetif.h"

#include "board.h"

#include "fsl_device_registers.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "peripherals.h"
#include "lwip/apps/mqtt.h"
#include "leds_control.h"
#include "ir_control.h"
#include "effects/effect_controller.h"
#include "stdint.h"
#include "time.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief MQTT client ID. */
#define EXAMPLE_MQTT_CLIENT_ID "f"

/*! @brief MQTT server host name or IP address. */
#define EXAMPLE_MQTT_SERVER_HOST "192.168.100.10"
//#define EXAMPLE_MQTT_SERVER_HOST "192.168.1.76"

/*! @brief MQTT server port number. */
#define EXAMPLE_MQTT_SERVER_PORT 1885

/* IP address configuration. */
#define configIP_ADDR0 192
#define configIP_ADDR1 168
#define configIP_ADDR2 100
#define configIP_ADDR3 51

/* Netmask configuration. */
#define configNET_MASK0 255
#define configNET_MASK1 255
#define configNET_MASK2 255
#define configNET_MASK3 0

/* Gateway address configuration. */
#define configGW_ADDR0 192
#define configGW_ADDR1 168
#define configGW_ADDR2 100
#define configGW_ADDR3 1

/* MAC address configuration. */
#define configMAC_ADDR                     \
    {                                      \
        0x02, 0x12, 0x13, 0x10, 0x15, 0x11 \
    }

/* Address of PHY interface. */
#define EXAMPLE_PHY_ADDRESS BOARD_ENET0_PHY_ADDRESS

/* System clock name. */
#define EXAMPLE_CLOCK_NAME kCLOCK_CoreSysClk


#ifndef EXAMPLE_NETIF_INIT_FN
/*! @brief Network interface initialization function. */
#define EXAMPLE_NETIF_INIT_FN ethernetif0_init
#endif /* EXAMPLE_NETIF_INIT_FN */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

static void connect_to_mqtt();

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @brief MQTT client data. */
static mqtt_client_t *mqtt_client;

/*! @brief MQTT client information. */
static const struct mqtt_connect_client_info_t mqtt_client_info = {
    .client_id   = EXAMPLE_MQTT_CLIENT_ID,
    .client_user = EXAMPLE_MQTT_CLIENT_ID,
    .client_pass = EXAMPLE_MQTT_CLIENT_ID,
    .keep_alive  = 100,
    .will_topic  = NULL,
    .will_msg    = NULL,
    .will_qos    = 0,
    .will_retain = 0,
};

/*! @brief MQTT broker IP address. */
static ip_addr_t mqtt_addr;

/*! @brief Indicates connection to MQTT broker. */
static volatile bool connected = false;

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Called when subscription request finishes.
 */
static void mqtt_topic_subscribed_cb(void *arg, err_t err)
{
    const char *topic = (const char *)arg;

    if (err == ERR_OK)
    {
        PRINTF("Subscribed to the topic \"%s\".\r\n", topic);
    }
    else
    {
        PRINTF("Failed to subscribe to the topic \"%s\": %d.\r\n", topic, err);
    }
}


/*!
 * @brief Called when there is a message on a subscribed topic.
 */
static void mqtt_incoming_publish_cb(void *arg, const char *topic, u32_t tot_len)
{
    LWIP_UNUSED_ARG(arg);

//    PRINTF("Received %u bytes from the topic \"%s\": \"", tot_len, topic);
}


uint32_t cores[4]= {
		0xF720DF,
		0xF7A05F,
		0xF7609F,
		0xF7E01F
};

/*!
 * @brief Called when recieved incoming published message fragment.
 */
static void mqtt_incoming_data_cb(void *arg, const u8_t *data, u16_t len, u8_t flags)
{
    int i;

    LWIP_UNUSED_ARG(arg);

    int command_type = data[0];
    int tamanho_do_comando = 0;

    switch(command_type) {
    /*
     * EFEITO
     */
    case 0:
    	tamanho_do_comando = 3;
    	break;
	/*
	* LUZ CHURRAS
	*/
    case 1:
    	tamanho_do_comando = 3;
    	break;
	/*
	* LUZ POOL
	*/
    case 2:
    	tamanho_do_comando = 1;
    	break;
    }

    int comando[3];

    for (i = 0; i < tamanho_do_comando; i++)
    {
    	comando[i] = data[i+1];
    }

    /*
     * Inicia/para efeitos
     */
    if(command_type == 0) {
    	if(comando[0] == 255) {
    		stopEffect();
    	} else {
    		if(hasEffect()) {
    			stopEffect();
    		}

            startEffect(comando[0], comando[1], comando[2]);
    	}

    	return;
    }

    /*
     * Muda cor da fita
     */
    if(command_type == 1) {
		if(hasEffect()) {
			stopEffect();
		}

        rgb_set_color(comando[0], comando[1], comando[2]);
    	return;
    }

    /*
     * Muda cor da piscina
     */
    if(command_type == 2) {
    	ir_send_command(comando[0]);
    	return;
    }

}

/*!
 * @brief Subscribe to MQTT topics.
 */
static void mqtt_subscribe_topics(mqtt_client_t *client)
{
    static const char *topics[] = {"led"};
    int qos[]                   = {0};
    err_t err;
    int i;

    mqtt_set_inpub_callback(client, mqtt_incoming_publish_cb, mqtt_incoming_data_cb,
                            LWIP_CONST_CAST(void *, &mqtt_client_info));

    for (i = 0; i < ARRAY_SIZE(topics); i++)
    {
        err = mqtt_subscribe(client, topics[i], qos[i], mqtt_topic_subscribed_cb, LWIP_CONST_CAST(void *, topics[i]));

        if (err == ERR_OK)
        {
            PRINTF("Subscribing to the topic \"%s\" with QoS %d...\r\n", topics[i], qos[i]);
        }
        else
        {
            PRINTF("Failed to subscribe to the topic \"%s\" with QoS %d: %d.\r\n", topics[i], qos[i], err);
        }
    }
}

/*!
 * @brief Called when connection state changes.
 */
static void mqtt_connection_cb(mqtt_client_t *client, void *arg, mqtt_connection_status_t status)
{
    const struct mqtt_connect_client_info_t *client_info = (const struct mqtt_connect_client_info_t *)arg;

    connected = (status == MQTT_CONNECT_ACCEPTED);

    switch (status)
    {
        case MQTT_CONNECT_ACCEPTED:
            PRINTF("MQTT client \"%s\" connected.\r\n", client_info->client_id);
            mqtt_subscribe_topics(client);
            break;

        case MQTT_CONNECT_DISCONNECTED:
            PRINTF("MQTT client \"%s\" not connected.\r\n", client_info->client_id);
            /* Try to reconnect 1 second later */
            sys_timeout(1000, connect_to_mqtt, NULL);
            break;

        case MQTT_CONNECT_TIMEOUT:
            PRINTF("MQTT client \"%s\" connection timeout.\r\n", client_info->client_id);
            /* Try again 1 second later */
            sys_timeout(1000, connect_to_mqtt, NULL);
            break;

        case MQTT_CONNECT_REFUSED_PROTOCOL_VERSION:
        case MQTT_CONNECT_REFUSED_IDENTIFIER:
        case MQTT_CONNECT_REFUSED_SERVER:
        case MQTT_CONNECT_REFUSED_USERNAME_PASS:
        case MQTT_CONNECT_REFUSED_NOT_AUTHORIZED_:
            PRINTF("MQTT client \"%s\" connection refused: %d.\r\n", client_info->client_id, (int)status);
            /* Try again 10 seconds later */
            sys_timeout(10000, connect_to_mqtt, NULL);
            break;

        default:
            PRINTF("MQTT client \"%s\" connection status: %d.\r\n", client_info->client_id, (int)status);
            /* Try again 10 seconds later */
            sys_timeout(10000, connect_to_mqtt, NULL);
            break;
    }
}

/*!
 * @brief Starts connecting to MQTT broker. To be called on tcpip_thread.
 */
static void connect_to_mqtt()
{
    PRINTF("Connecting to MQTT broker at %s...\r\n", ipaddr_ntoa(&mqtt_addr));

    mqtt_client_connect(mqtt_client, &mqtt_addr, EXAMPLE_MQTT_SERVER_PORT, mqtt_connection_cb,
                        LWIP_CONST_CAST(void *, &mqtt_client_info), &mqtt_client_info);
}

//
///*!
// * @brief Called when publish request finishes.
// */
//static void mqtt_message_published_cb(void *arg, err_t err)
//{
//	// nao nos importamos
//}


/*!
 * @brief Interrupt service for SysTick timer.
 */
void SysTick_Handler(void)
{
    time_isr();
}



short x = 0;
int counter = 0;
short effectTickFlag = 0;

/* PORTC_IRQn interrupt handler */
void PORTA_IRQHandler(void) {
	GPIO_PortClearInterruptFlags(BOARD_INITPINS_INPUT_ADC_GPIO, 1U << BOARD_INITPINS_INPUT_ADC_PIN);
	counter = 0;
	FTM_StartTimer(FTM0_PERIPHERAL, kFTM_SystemClock);
}


/*
 * 116 ---> METADE
 */

/* FTM0_IRQn interrupt handler */
void FTM0_IRQHANDLER(void) {
  FTM_ClearStatusFlags(FTM0_PERIPHERAL, kFTM_TimeOverflowFlag);
  counter++;
  /*  Place your code here */
  if(counter == TICKS_MAX) {
	  FTM_StopTimer(FTM0_PERIPHERAL);
	  counter = 0;
  }

}


void FTM1_IRQHANDLER(void) {
  FTM_ClearStatusFlags(FTM1_PERIPHERAL, kFTM_TimeOverflowFlag);
  ir_tick();
}

void FTM2_IRQHANDLER(void) {
  FTM_ClearStatusFlags(FTM2_PERIPHERAL, kFTM_TimeOverflowFlag);
  ir_blast();
  effectTickFlag = 1;
}

/*!
 * @brief Main function.
 */
int main(void)
{
    struct netif netif;

    ip4_addr_t netif_ipaddr, netif_netmask, netif_gw;
    ethernetif_config_t enet_config = {
        .phyAddress = EXAMPLE_PHY_ADDRESS,
        .clockName  = EXAMPLE_CLOCK_NAME,
        .macAddress = configMAC_ADDR
    };

    SYSMPU_Type *base = SYSMPU;
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();
    BOARD_InitPeripherals();

    /* Disable SYSMPU. */
    base->CESR &= ~SYSMPU_CESR_VLD_MASK;

    time_init();

    IP4_ADDR(&netif_ipaddr, configIP_ADDR0, configIP_ADDR1, configIP_ADDR2, configIP_ADDR3);
    IP4_ADDR(&netif_netmask, configNET_MASK0, configNET_MASK1, configNET_MASK2, configNET_MASK3);
    IP4_ADDR(&netif_gw, configGW_ADDR0, configGW_ADDR1, configGW_ADDR2, configGW_ADDR3);

    lwip_init();

    netif_add(&netif, &netif_ipaddr, &netif_netmask, &netif_gw, &enet_config, EXAMPLE_NETIF_INIT_FN, ethernet_input);
    netif_set_default(&netif);
    netif_set_up(&netif);

    PRINTF("\r\n************************************************\r\n");
    PRINTF(" Oi mundo! Minhas informacoes de rede sao: \r\n");
    PRINTF("************************************************\r\n");
    PRINTF(" IPv4 Address     : %u.%u.%u.%u\r\n", ((u8_t *)&netif_ipaddr)[0], ((u8_t *)&netif_ipaddr)[1],
           ((u8_t *)&netif_ipaddr)[2], ((u8_t *)&netif_ipaddr)[3]);
    PRINTF(" IPv4 Subnet mask : %u.%u.%u.%u\r\n", ((u8_t *)&netif_netmask)[0], ((u8_t *)&netif_netmask)[1],
           ((u8_t *)&netif_netmask)[2], ((u8_t *)&netif_netmask)[3]);
    PRINTF(" IPv4 Gateway     : %u.%u.%u.%u\r\n", ((u8_t *)&netif_gw)[0], ((u8_t *)&netif_gw)[1],
           ((u8_t *)&netif_gw)[2], ((u8_t *)&netif_gw)[3]);
    PRINTF("************************************************\r\n");

    ipaddr_aton(EXAMPLE_MQTT_SERVER_HOST, &mqtt_addr);


    EnableIRQ(PORTA_IRQn);

    PRINTF("INICIANDO MQTT\r\n");
    mqtt_client = mqtt_client_new();
    if (mqtt_client == NULL) {
    	PRINTF("mqtt_client_new() failed.\r\n");
    	return 1;
    }

    connect_to_mqtt();

    time_t t;
    srand(time(&t));

	FTM_StartTimer(FTM2_PERIPHERAL, kFTM_SystemClock);
    while (1)
    {
    	rgb_tick(counter);

    	if(effectTickFlag) {
    		effectTick();
    		effectTickFlag = 0;
    	}

        /* Poll the driver, get any outstanding frames */
        ethernetif_input(&netif);
        sys_check_timeouts(); /* Handle all system timeouts for all core protocols */
    }
}
#endif
