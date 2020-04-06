/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

#define SOPT5_UART0TXSRC_UART_TX 0x00u /*!<@brief UART 0 transmit data source select: UART0_TX pin */

/*! @name PORTB16 (number 62), U7[4]/UART0_RX
  @{ */
#define BOARD_INITPINS_DEBUG_UART_RX_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_DEBUG_UART_RX_PIN 16U    /*!<@brief PORTB pin index: 16 */
                                                /* @} */

/*! @name PORTB17 (number 63), U10[1]/UART0_TX
  @{ */
#define BOARD_INITPINS_DEBUG_UART_TX_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_DEBUG_UART_TX_PIN 17U    /*!<@brief PORTB pin index: 17 */
                                                /* @} */

/*! @name PORTC16 (number 90), J1[2]
  @{ */
#define BOARD_INITPINS_TMR_1588_0_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_TMR_1588_0_PIN 16U    /*!<@brief PORTC pin index: 16 */
                                             /* @} */

/*! @name PORTC17 (number 91), J1[4]
  @{ */
#define BOARD_INITPINS_TMR_1588_1_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_TMR_1588_1_PIN 17U    /*!<@brief PORTC pin index: 17 */
                                             /* @} */

/*! @name PORTB1 (number 54), U13[11]/RMII0_MDC
  @{ */
#define BOARD_INITPINS_RMII0_MDC_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_RMII0_MDC_PIN 1U     /*!<@brief PORTB pin index: 1 */
                                            /* @} */

/*! @name PORTB0 (number 53), U13[10]/RMII0_MDIO
  @{ */
#define BOARD_INITPINS_RMII0_MDIO_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_RMII0_MDIO_PIN 0U     /*!<@brief PORTB pin index: 0 */
                                             /* @} */

/*! @name PORTA12 (number 42), U13[12]/RMII0_RXD_1
  @{ */
#define BOARD_INITPINS_RMII0_RXD1_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_RMII0_RXD1_PIN 12U    /*!<@brief PORTA pin index: 12 */
                                             /* @} */

/*! @name PORTA13 (number 43), U13[13]/RMII0_RXD_0
  @{ */
#define BOARD_INITPINS_RMII0_RXD0_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_RMII0_RXD0_PIN 13U    /*!<@brief PORTA pin index: 13 */
                                             /* @} */

/*! @name PORTA14 (number 44), U13[15]/RMII0_CRS_DV
  @{ */
#define BOARD_INITPINS_RMII0_CRS_DV_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_RMII0_CRS_DV_PIN 14U    /*!<@brief PORTA pin index: 14 */
                                               /* @} */

/*! @name PORTA15 (number 45), U13[19]/RMII0_TXEN
  @{ */
#define BOARD_INITPINS_RMII0_TXEN_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_RMII0_TXEN_PIN 15U    /*!<@brief PORTA pin index: 15 */
                                             /* @} */

/*! @name PORTA17 (number 47), U13[21]/RMII0_TXD1
  @{ */
#define BOARD_INITPINS_RMII0_TXD1_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_RMII0_TXD1_PIN 17U    /*!<@brief PORTA pin index: 17 */
                                             /* @} */

/*! @name PORTA16 (number 46), U13[20]/RMII0_TXD0
  @{ */
#define BOARD_INITPINS_RMII0_TXD0_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_RMII0_TXD0_PIN 16U    /*!<@brief PORTA pin index: 16 */
                                             /* @} */

/*! @name PORTA5 (number 39), U13[17]/RMII0_RXER
  @{ */
#define BOARD_INITPINS_RMII0_RXER_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_RMII0_RXER_PIN 5U     /*!<@brief PORTA pin index: 5 */
                                             /* @} */

/*! @name PORTB22 (number 68), LED_RED
  @{ */
#define BOARD_INITPINS_LED_RED_GPIO GPIOB /*!<@brief GPIO device name: GPIOB */
#define BOARD_INITPINS_LED_RED_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_LED_RED_PIN 22U    /*!<@brief PORTB pin index: 22 */
                                          /* @} */

/*! @name PORTB2 (number 55), LED1_R
  @{ */
#define BOARD_INITPINS_LED1_R_GPIO GPIOB /*!<@brief GPIO device name: GPIOB */
#define BOARD_INITPINS_LED1_R_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_LED1_R_PIN 2U     /*!<@brief PORTB pin index: 2 */
                                         /* @} */

/*! @name PORTB3 (number 56), LED1_G
  @{ */
#define BOARD_INITPINS_LED1_G_GPIO GPIOB /*!<@brief GPIO device name: GPIOB */
#define BOARD_INITPINS_LED1_G_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_LED1_G_PIN 3U     /*!<@brief PORTB pin index: 3 */
                                         /* @} */

/*! @name PORTB10 (number 58), LED1_B
  @{ */
#define BOARD_INITPINS_LED1_B_GPIO GPIOB /*!<@brief GPIO device name: GPIOB */
#define BOARD_INITPINS_LED1_B_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_LED1_B_PIN 10U    /*!<@brief PORTB pin index: 10 */
                                         /* @} */

/*! @name PORTB11 (number 59), LED2_R
  @{ */
#define BOARD_INITPINS_LED2_R_GPIO GPIOB /*!<@brief GPIO device name: GPIOB */
#define BOARD_INITPINS_LED2_R_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_LED2_R_PIN 11U    /*!<@brief PORTB pin index: 11 */
                                         /* @} */

/*! @name PORTC11 (number 83), LED2_G
  @{ */
#define BOARD_INITPINS_LED2_G_GPIO GPIOC /*!<@brief GPIO device name: GPIOC */
#define BOARD_INITPINS_LED2_G_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_LED2_G_PIN 11U    /*!<@brief PORTC pin index: 11 */
                                         /* @} */

/*! @name PORTC10 (number 82), LED2_B
  @{ */
#define BOARD_INITPINS_LED2_B_GPIO GPIOC /*!<@brief GPIO device name: GPIOC */
#define BOARD_INITPINS_LED2_B_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_LED2_B_PIN 10U    /*!<@brief PORTC pin index: 10 */
                                         /* @} */

/*! @name PORTB20 (number 66), LED3_R
  @{ */
#define BOARD_INITPINS_LED3_R_GPIO GPIOB /*!<@brief GPIO device name: GPIOB */
#define BOARD_INITPINS_LED3_R_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_LED3_R_PIN 20U    /*!<@brief PORTB pin index: 20 */
                                         /* @} */

/*! @name PORTB18 (number 64), LED3_G
  @{ */
#define BOARD_INITPINS_LED3_G_GPIO GPIOB /*!<@brief GPIO device name: GPIOB */
#define BOARD_INITPINS_LED3_G_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_LED3_G_PIN 18U    /*!<@brief PORTB pin index: 18 */
                                         /* @} */

/*! @name PORTB19 (number 65), LED3_B
  @{ */
#define BOARD_INITPINS_LED3_B_GPIO GPIOB /*!<@brief GPIO device name: GPIOB */
#define BOARD_INITPINS_LED3_B_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_LED3_B_PIN 19U    /*!<@brief PORTB pin index: 19 */
                                         /* @} */

/*! @name PORTC1 (number 71), LED4_R
  @{ */
#define BOARD_INITPINS_LED4_R_GPIO GPIOC /*!<@brief GPIO device name: GPIOC */
#define BOARD_INITPINS_LED4_R_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_LED4_R_PIN 1U     /*!<@brief PORTC pin index: 1 */
                                         /* @} */

/*! @name PORTC8 (number 80), LED4_G
  @{ */
#define BOARD_INITPINS_LED4_G_GPIO GPIOC /*!<@brief GPIO device name: GPIOC */
#define BOARD_INITPINS_LED4_G_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_LED4_G_PIN 8U     /*!<@brief PORTC pin index: 8 */
                                         /* @} */

/*! @name PORTC9 (number 81), LED4_B
  @{ */
#define BOARD_INITPINS_LED4_B_GPIO GPIOC /*!<@brief GPIO device name: GPIOC */
#define BOARD_INITPINS_LED4_B_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_LED4_B_PIN 9U     /*!<@brief PORTC pin index: 9 */
                                         /* @} */

/*! @name PORTC0 (number 70), LED5_R
  @{ */
#define BOARD_INITPINS_LED5_R_GPIO GPIOC /*!<@brief GPIO device name: GPIOC */
#define BOARD_INITPINS_LED5_R_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_LED5_R_PIN 0U     /*!<@brief PORTC pin index: 0 */
                                         /* @} */

/*! @name PORTC7 (number 79), LED5_G
  @{ */
#define BOARD_INITPINS_LED5_G_GPIO GPIOC /*!<@brief GPIO device name: GPIOC */
#define BOARD_INITPINS_LED5_G_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_LED5_G_PIN 7U     /*!<@brief PORTC pin index: 7 */
                                         /* @} */

/*! @name PORTC5 (number 77), LED5_B
  @{ */
#define BOARD_INITPINS_LED5_B_GPIO GPIOC /*!<@brief GPIO device name: GPIOC */
#define BOARD_INITPINS_LED5_B_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_LED5_B_PIN 5U     /*!<@brief PORTC pin index: 5 */
                                         /* @} */

/*! @name PORTE26 (number 33), LED6_R
  @{ */
#define BOARD_INITPINS_LED6_R_GPIO GPIOE /*!<@brief GPIO device name: GPIOE */
#define BOARD_INITPINS_LED6_R_PORT PORTE /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_LED6_R_PIN 26U    /*!<@brief PORTE pin index: 26 */
                                         /* @} */

/*! @name PORTB9 (number 57), LED6_G
  @{ */
#define BOARD_INITPINS_LED6_G_GPIO GPIOB /*!<@brief GPIO device name: GPIOB */
#define BOARD_INITPINS_LED6_G_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_LED6_G_PIN 9U     /*!<@brief PORTB pin index: 9 */
                                         /* @} */

/*! @name PORTD7 (number 100), LED6_B
  @{ */
#define BOARD_INITPINS_LED6_B_GPIO GPIOD /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_LED6_B_PORT PORTD /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_LED6_B_PIN 7U     /*!<@brief PORTD pin index: 7 */
                                         /* @} */

/*! @name PORTB23 (number 69), LED7_R
  @{ */
#define BOARD_INITPINS_LED7_R_GPIO GPIOB /*!<@brief GPIO device name: GPIOB */
#define BOARD_INITPINS_LED7_R_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_LED7_R_PIN 23U    /*!<@brief PORTB pin index: 23 */
                                         /* @} */

/*! @name PORTD5 (number 98), LED7_G
  @{ */
#define BOARD_INITPINS_LED7_G_GPIO GPIOD /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_LED7_G_PORT PORTD /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_LED7_G_PIN 5U     /*!<@brief PORTD pin index: 5 */
                                         /* @} */

/*! @name PORTC2 (number 72), LED7_B
  @{ */
#define BOARD_INITPINS_LED7_B_GPIO GPIOC /*!<@brief GPIO device name: GPIOC */
#define BOARD_INITPINS_LED7_B_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_LED7_B_PIN 2U     /*!<@brief PORTC pin index: 2 */
                                         /* @} */

/*! @name PORTC3 (number 73), LED8_R
  @{ */
#define BOARD_INITPINS_LED8_R_GPIO GPIOC /*!<@brief GPIO device name: GPIOC */
#define BOARD_INITPINS_LED8_R_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_LED8_R_PIN 3U     /*!<@brief PORTC pin index: 3 */
                                         /* @} */

/*! @name PORTC12 (number 84), LED8_G
  @{ */
#define BOARD_INITPINS_LED8_G_GPIO GPIOC /*!<@brief GPIO device name: GPIOC */
#define BOARD_INITPINS_LED8_G_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_LED8_G_PIN 12U    /*!<@brief PORTC pin index: 12 */
                                         /* @} */

/*! @name PORTC4 (number 76), LED8_B
  @{ */
#define BOARD_INITPINS_LED8_B_GPIO GPIOC /*!<@brief GPIO device name: GPIOC */
#define BOARD_INITPINS_LED8_B_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_LED8_B_PIN 4U     /*!<@brief PORTC pin index: 4 */
                                         /* @} */

/*! @name PORTD0 (number 93), LED9_R
  @{ */
#define BOARD_INITPINS_LED9_R_GPIO GPIOD /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_LED9_R_PORT PORTD /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_LED9_R_PIN 0U     /*!<@brief PORTD pin index: 0 */
                                         /* @} */

/*! @name PORTD2 (number 95), LED9_G
  @{ */
#define BOARD_INITPINS_LED9_G_GPIO GPIOD /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_LED9_G_PORT PORTD /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_LED9_G_PIN 2U     /*!<@brief PORTD pin index: 2 */
                                         /* @} */

/*! @name PORTD3 (number 96), LED9_B
  @{ */
#define BOARD_INITPINS_LED9_B_GPIO GPIOD /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_LED9_B_PORT PORTD /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_LED9_B_PIN 3U     /*!<@brief PORTD pin index: 3 */
                                         /* @} */

/*! @name PORTD1 (number 94), LED10_R
  @{ */
#define BOARD_INITPINS_LED10_R_GPIO GPIOD /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_LED10_R_PORT PORTD /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_LED10_R_PIN 1U     /*!<@brief PORTD pin index: 1 */
                                          /* @} */

/*! @name PORTE25 (number 32), LED10_G
  @{ */
#define BOARD_INITPINS_LED10_G_GPIO GPIOE /*!<@brief GPIO device name: GPIOE */
#define BOARD_INITPINS_LED10_G_PORT PORTE /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_LED10_G_PIN 25U    /*!<@brief PORTE pin index: 25 */
                                          /* @} */

/*! @name PORTE24 (number 31), LED10_B
  @{ */
#define BOARD_INITPINS_LED10_B_GPIO GPIOE /*!<@brief GPIO device name: GPIOE */
#define BOARD_INITPINS_LED10_B_PORT PORTE /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_LED10_B_PIN 24U    /*!<@brief PORTE pin index: 24 */
                                          /* @} */

/*! @name PORTA1 (number 35), INPUT_ADC
  @{ */
#define BOARD_INITPINS_INPUT_ADC_GPIO GPIOA /*!<@brief GPIO device name: GPIOA */
#define BOARD_INITPINS_INPUT_ADC_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_INPUT_ADC_PIN 1U     /*!<@brief PORTA pin index: 1 */
                                            /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
