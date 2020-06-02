#include "camaleao.h"
#include "stdint.h"

static void init();
static void changeProp(int intensity, int velocity);
static void tick();

uint16_t eff_counter = 0;

static void (*effect_runnable[3])() = {
	init,
	changeProp,
	tick
};


RGB rgb_goal;

void* camaleao_getRunnables(){
 return effect_runnable;
}


void newColor() {
	rgb_goal.r = getRand(20, 235);
	rgb_goal.g = getRand(20, 235);
	rgb_goal.b = getRand(20, 235);
}

void init() {
	//Incia com um objetivo de cor
	newColor();
}

void changeProp(int intensity, int velocity) {

}

void tick() {
	eff_counter++;

	if(eff_counter == 500) {
		RGB current = getLineColor();
		short modified = 0;

		if(current.r != rgb_goal.r) {
			modified = 1;
			if(current.r > rgb_goal.r) {
				current.r--;
			} else if(current.r < rgb_goal.r) {
				current.r++;
			}
		}


		if(current.g != rgb_goal.g) {
			modified = 1;
			if(current.g > rgb_goal.g) {
				current.g--;
			} else if(current.g < rgb_goal.g) {
				current.g++;
			}
		}


		if(current.b != rgb_goal.b) {
			modified = 1;
			if(current.b > rgb_goal.b) {
				current.b--;
			} else if(current.b < rgb_goal.b) {
				current.b++;
			}
		}

		if(modified == 0) {
			newColor();
		}

		rgb_set_color_notSafe(current.r, current.g, current.b);

		eff_counter = 0;
	}

}
