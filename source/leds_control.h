/*
 * leds_control.c
 *
 *  Created on: Jan 5, 2020
 *      Author: Mellem
 */
#include <stdint.h>
#include "MK64F12.h"
#include "MK64F12_features.h"

#define RGB_NUMBER_OF_STRIPS 10
#define TICKS_MAX 232

typedef struct RGB_Strip {
	/*
	 * RED
	 */
	uint8_t r_intensity;
	GPIO_Type *r_base;
	uint8_t r_pin;
	/*
	 * GREEN
	 */
	uint8_t g_intensity;
	GPIO_Type *g_base;
	uint8_t g_pin;
	/*
	 * GREEN
	 */
	uint8_t b_intensity;
	GPIO_Type *b_base;
	uint8_t b_pin;
} RGB_Strip;


void rgb_set(int stripIndex, int r, int g, int b);
void turnStripState(short value);
void toogleState();
void rgb_tick();
void rgb_set_color(int r, int g, int b);
int rgb_convert(int value);
