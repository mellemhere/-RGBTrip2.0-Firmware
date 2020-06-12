#include "strobo.h"
#include "stdint.h"

static void init();
static void changeProp(int intensity, int velocity);
static void tick();

uint16_t stroboColorido_eff_counter = 0;
short toggleStateS = 0;

static void (*stroboColorido_effect_runnable[3])() = {
	init,
	changeProp,
	tick
};

void* stroboColorido_getRunnables(){
 return stroboColorido_effect_runnable;
}


uint8_t colors[7][3] = {
	{200,0,0},
	{0,200,0},
	{0,0,200},
	{200,200,0},
	{200,0,200},
	{200,200,200},
	{0,200,200},
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
	stroboColorido_eff_counter = 0;
}

void changeProp(int intensity, int velocity) {
}

void tick() {
	stroboColorido_eff_counter++;

	if(stroboColorido_eff_counter == 3000 && toggleStateS == 0) {
		rgb_set_color(nextColor.r, nextColor.g, nextColor.b);
		toggleStateS = 1;
		stroboColorido_eff_counter = 0;
	} else if(stroboColorido_eff_counter == 50 && toggleStateS == 1) {
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
		stroboColorido_eff_counter = 0;
	}

}
