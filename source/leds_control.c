/*
 * leds_control.c
 *
 *  Created on: Jan 5, 2020
 *      Author: Mellem
 */
#include "leds_control.h"
#include "fsl_gpio.h"

/*
 * Onde guardamos nossos leds
 */
RGB_Strip rgb_strips[RGB_NUMBER_OF_STRIPS] = {


	//FITA 1
	{
	 //RED
	 .r_intensity = 100,
	 .r_base = GPIOC,
	 .r_pin = 7,
	 //GREEN
	 .g_intensity = 100,
	 .g_base = GPIOC,
	 .g_pin = 5,
	 //BLUE
	 .b_intensity = 100,
	 .b_base = GPIOC,
	 .b_pin = 0,
	},

	//FITA 2
	{
	 //RED
	 .r_intensity = 100,
	 .r_base = GPIOC,
	 .r_pin = 8,
	 //GREEN
	 .g_intensity = 100,
	 .g_base = GPIOC,
	 .g_pin = 1,
	 //BLUE
	 .b_intensity = 100,
	 .b_base = GPIOC,
	 .b_pin = 9,
	},


	//FITA 3
	{
	 //RED
	 .r_intensity = 100,
	 .r_base = GPIOB,
	 .r_pin = 18,
	 //GREEN
	 .g_intensity = 100,
	 .g_base = GPIOB,
	 .g_pin = 20,
	 //BLUE
	 .b_intensity = 100,
	 .b_base = GPIOB,
	 .b_pin = 19,
	},

	//FITA 4
	{
	 //RED
	 .r_intensity = 100,
	 .r_base = GPIOC,
	 .r_pin = 11,
	 //GREEN
	 .g_intensity = 100,
	 .g_base = GPIOB,
	 .g_pin = 11,
	 //BLUE
	 .b_intensity = 100,
	 .b_base = GPIOC,
	 .b_pin = 10,
	},


	//FITA 5
	{
	 //RED
	 .r_intensity = 100,
	 .r_base = GPIOB,
	 .r_pin = 3, // 2
	 //GREEN
	 .g_intensity = 100,
	 .g_base = GPIOD,
	 .g_pin = 4, // 10
	 //BLUE
	 .b_intensity = 100,
	 .b_base = GPIOB,
	 .b_pin = 10, // 3
	},


	//FITA 6
	{
	 //RED
	 .r_intensity = 100,
	 .r_base = GPIOE,
	 .r_pin = 25, // 1
	 //GREEN
	 .g_intensity = 100,
	 .g_base = GPIOD,
	 .g_pin = 1, // 25
	 //BLUE
	 .b_intensity = 100,
	 .b_base = GPIOE,
	 .b_pin = 24, // 24
	},


	//FITA 7
	{
	 //RED
	 .r_intensity = 100,
	 .r_base = GPIOD,
	 .r_pin = 2, //0
	 //GREEN
	 .g_intensity = 100,
	 .g_base = GPIOD,
	 .g_pin = 0, //3
	 //BLUE
	 .b_intensity = 100,
	 .b_base = GPIOD,
	 .b_pin = 3, //2
	},

	//FITA 8
	{
	 //RED
	 .r_intensity = 100,
	 .r_base = GPIOA , //C12 old
	 .r_pin = 2,
	 //GREEN
	 .g_intensity = 100,
	 .g_base = GPIOC,
	 .g_pin = 3, //4
	 //BLUE
	 .b_intensity = 100,
	 .b_base = GPIOC,
	 .b_pin = 4, //3
	},

	//FITA 9
	{
	 //RED
	 .r_intensity = 100,
	 .r_base = GPIOD,
	 .r_pin = 5,
	 //GREEN
	 .g_intensity = 100,
	 .g_base = GPIOB,
	 .g_pin = 23,
	 //BLUE
	 .b_intensity = 100,
	 .b_base = GPIOC,
	 .b_pin = 2,
	},

	//FITA 10
	{
	 //RED
	 .r_intensity = 100,
	 .r_base = GPIOE,
	 .r_pin = 26,
	 //GREEN
	 .g_intensity = 100,
	 .g_base = GPIOB,
	 .g_pin = 9,
	 //BLUE
	 .b_intensity = 100,
	 .b_base = GPIOD,
	 .b_pin = 7,
	}

};


short currentState = 0;
uint32_t intMax = 0;

int rgb_convert(int value) {
    return TICKS_MAX - (value * 0.8823);
//	return TICKS_MAX - (0.90 * value);
//////	return TICKS_MAX - (0.90 * value);
}

void rgb_set(int stripIndex, int r, int g, int b) {
	rgb_strips[stripIndex].r_intensity = rgb_convert(r);
	rgb_strips[stripIndex].g_intensity = rgb_convert(g);
	rgb_strips[stripIndex].b_intensity = rgb_convert(b);
}


void rgb_set_color(int r, int g, int b) {
	for(int stripIndex = 0; stripIndex < RGB_NUMBER_OF_STRIPS; stripIndex++) {
		rgb_set(stripIndex, r, g, b);
	}
}

void rgb_set_color_notSafe(int r, int g, int b) {
	for(int stripIndex = 0; stripIndex < RGB_NUMBER_OF_STRIPS; stripIndex++) {
		rgb_strips[stripIndex].r_intensity = r;
		rgb_strips[stripIndex].g_intensity = g;
		rgb_strips[stripIndex].b_intensity = b;
	}
}

void turnStripState(short value) {
	for(int stripIndex = 0; stripIndex < RGB_NUMBER_OF_STRIPS; stripIndex++) {
		GPIO_PinWrite(rgb_strips[stripIndex].r_base, rgb_strips[stripIndex].r_pin, value);
		GPIO_PinWrite(rgb_strips[stripIndex].g_base, rgb_strips[stripIndex].g_pin, value);
		GPIO_PinWrite(rgb_strips[stripIndex].b_base, rgb_strips[stripIndex].b_pin, value);
	}
}

void toogleState() {
	if(currentState == 0) {
		turnStripState(1);
		currentState = 1;
	} else {
		turnStripState(0);
		currentState = 0;
	}
}

void rgb_setInt(uint32_t valor) {
	intMax = valor;
}

#define LIGA 0
#define DESLIGA 1

void rgb_tick(int rgb_current_tick) {
	// && (intMax != 0 && rgb_current_tick >= intMax)
	for(int stripIndex = 0; stripIndex < RGB_NUMBER_OF_STRIPS; stripIndex++) {
		/*
		 * RED
		 * 255 -> 0
		 */
		if(rgb_strips[stripIndex].r_intensity >= intMax) {
			if(rgb_strips[stripIndex].r_intensity <= rgb_current_tick) {
				GPIO_PinWrite(rgb_strips[stripIndex].r_base, rgb_strips[stripIndex].r_pin, DESLIGA);
			} else {
				GPIO_PinWrite(rgb_strips[stripIndex].r_base, rgb_strips[stripIndex].r_pin, LIGA);
			}
		} else {
			GPIO_PinWrite(rgb_strips[stripIndex].r_base, rgb_strips[stripIndex].r_pin, DESLIGA);
		}
		/*
		 * GREEN
		 */
		if(rgb_strips[stripIndex].g_intensity >= intMax) {
			if(rgb_strips[stripIndex].g_intensity <= rgb_current_tick) {
				GPIO_PinWrite(rgb_strips[stripIndex].g_base, rgb_strips[stripIndex].g_pin, DESLIGA);
			} else {
				GPIO_PinWrite(rgb_strips[stripIndex].g_base, rgb_strips[stripIndex].g_pin, LIGA);
			}
		} else {
			GPIO_PinWrite(rgb_strips[stripIndex].g_base, rgb_strips[stripIndex].g_pin, DESLIGA);
		}

		/*
		 * BLUE
		 */
		if(rgb_strips[stripIndex].b_intensity >= intMax) {
			if(rgb_strips[stripIndex].b_intensity <= rgb_current_tick) {
				GPIO_PinWrite(rgb_strips[stripIndex].b_base, rgb_strips[stripIndex].b_pin, DESLIGA);
			} else {
				GPIO_PinWrite(rgb_strips[stripIndex].b_base, rgb_strips[stripIndex].b_pin, LIGA);
			}
		} else {
			GPIO_PinWrite(rgb_strips[stripIndex].b_base, rgb_strips[stripIndex].b_pin, DESLIGA);
		}
	}
}

RGB getLineColor() {
	RGB ret;
	ret.r = rgb_strips[0].r_intensity;
	ret.g = rgb_strips[0].g_intensity;
	ret.b = rgb_strips[0].b_intensity;

	return ret;
}

