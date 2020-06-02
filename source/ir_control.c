#include "leds_control.h"
#include "fsl_gpio.h"
#include "fsl_ftm.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "stdint.h"


uint32_t current_command = 0;
short ledState = 0;
short toggleLed = 0;
short in_blast_mode = 0;

void ir_blast() {
	if(in_blast_mode) {
		if(toggleLed == 1) {
			if(ledState == 0) {
				GPIO_PinWrite(BOARD_INITPINS_IR_OUT_GPIO, BOARD_INITPINS_IR_OUT_PIN, 1);
				ledState = 1;
			} else {
				GPIO_PinWrite(BOARD_INITPINS_IR_OUT_GPIO, BOARD_INITPINS_IR_OUT_PIN, 0);
				ledState = 0;
			}
		} else {
			GPIO_PinWrite(BOARD_INITPINS_IR_OUT_GPIO, BOARD_INITPINS_IR_OUT_PIN, 0);
		}
	}
}

/*
 *  0 => FICA EM ALTO 9ms (16)
 *  1 => FICA EM BAIXO 4.5 (8)
 *  2 => ENDERECO 0
 *  3 => COMANDO
 *  4 => ALTA POR 1 tick
 */
int estadoDoEnvio = 0;
int tick_count = 0;
int tick_toggle = 0;
int position = 23;

void ir_tick() {
	switch (estadoDoEnvio) {
	case 0: // ------ PULSO ALTO
		if(tick_count <= 16) {
			toggleLed = 1;

			tick_count++;
			if(tick_count == 16) {
				tick_count = 0;
				estadoDoEnvio++;
			}
		}
		break;
	case 1: // ------ PULSO BAIXO
		if(tick_count <= 8) {
			toggleLed = 0;

			tick_count++;
			if(tick_count == 8) {
				tick_count = 0;
				estadoDoEnvio++;
			}
		}
		break;
	case 2: // ------ ENDERECO
		if(tick_count <= 8) {

			if(tick_toggle == 1) {
				toggleLed = 0;
				tick_toggle = 0;
				tick_count++;
			} else {
				toggleLed = 1;
				tick_toggle = 1;
			}

			if(tick_count == 8) {
				tick_count = 0;
				tick_toggle = 0;
				toggleLed = 0;
				estadoDoEnvio++;
			}
		}
		break;
	case 3:
		if(position == -1 && tick_toggle == 0) {
			estadoDoEnvio++;
			tick_count = 0;
			tick_toggle = 0;
		} else {
			if(tick_toggle == 0) {
				int currentBit = current_command & (1 << position);
				if(currentBit == 0) {
					tick_toggle = 1;
				} else {
					tick_toggle = 3;
				}

				toggleLed = 1;
				position--;
			} else {
				tick_toggle--;
				toggleLed = 0;
			}
		}
		break;
	case 4:
		if (tick_count == 0) {
			toggleLed = 1;
			tick_count = 1;
		} else {
			toggleLed = 0;
			estadoDoEnvio = -1; // Para maquina de estado
			FTM_StopTimer(FTM1_PERIPHERAL);
			in_blast_mode = 0;
		}
		break;
	}

}

void ir_send_command(uint32_t comand) {
	current_command = comand;
	position = 23;
	estadoDoEnvio = 0;
	tick_count = 0;
	FTM_StartTimer(FTM1_PERIPHERAL, kFTM_SystemClock);
	in_blast_mode = 1;
}
