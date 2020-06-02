#include "strobo.h"
#include "stdint.h"

static void init();
static void changeProp(int intensity, int velocity);
static void tick();

uint16_t eff_sc_counter = 0;
short toggleStateS = 0;

static void (*effect_runnable[3])() = {
	init,
	changeProp,
	tick
};

void* stroboColorido_getRunnables(){
 return effect_runnable;
}


uint8_t colors[7][3] = {
	{255,0,0},
	{0,255,0},
	{0,0,255},
	{255,255,0},
	{255,0,255},
	{255,255,255},
	{0,255,255},
};

RGB nextColor;
int lastColor = 0;

void newColorS() {
	int rand = 0;
	while (1) {
		rand =  getRand(0, 6);
		if(lastColor != rand) {
			break;
		}
	}
	lastColor = rand;
	nextColor.r = colors[rand][0];
	nextColor.g = colors[rand][1];
	nextColor.b = colors[rand][2];
}

void init() {
	newColorS();
}

void changeProp(int intensity, int velocity) {
}

void tick() {
	eff_sc_counter++;

	if(eff_sc_counter == 3000 && toggleStateS == 0) {
		rgb_set_color(nextColor.r, nextColor.g, nextColor.b);
		toggleStateS = 1;
		eff_sc_counter = 0;
	} else if(eff_sc_counter == 50 && toggleStateS == 1) {
		RGB current = getLineColor();
		if(current.r < TICKS_MAX) {
			current.r++;
		}

		if(current.g < TICKS_MAX) {
			current.g++;
		}

		if(current.b < TICKS_MAX) {
			current.b++;
		}


		if(current.r == TICKS_MAX && current.g == TICKS_MAX && current.b == TICKS_MAX) {
			toggleStateS = 0;
			newColorS();
		}

		rgb_set_color_notSafe(current.r, current.g, current.b);
		eff_sc_counter = 0;
	}

}
