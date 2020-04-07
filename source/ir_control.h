/*
 * ir_control.c
 *
 *  Created on: Jan 5, 2020
 *      Author: Mellem
 */
#include <stdint.h>
#include "MK64F12.h"
#include "MK64F12_features.h"
#include "stdint.h"

void ir_tick();
void ir_send_command(uint32_t comand);
void ir_blast();
