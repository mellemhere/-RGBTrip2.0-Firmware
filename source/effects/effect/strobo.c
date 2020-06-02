#include "strobo.h"
#include "stdint.h"

static void init();
static void changeProp(int intensity, int velocity);
static void tick();

uint16_t eff_s_counter = 0;
short toggleState = 0;

static void (*effect_runnable[3])() = {
	init,
	changeProp,
	tick
};

void* strobo_getRunnables(){
 return effect_runnable;
}



void init() {
	/*
	 * Faz nada
	 */
}

void changeProp(int intensity, int velocity) {
}

void tick() {
	eff_s_counter++;

	if(eff_s_counter == 5000) {
		if(toggleState) {
			rgb_set_color(0, 0, 0);
			toggleState = 0;
		} else {
			rgb_set_color(255, 255, 255);
			toggleState = 1;
		}
		eff_s_counter = 0;
	}

}
