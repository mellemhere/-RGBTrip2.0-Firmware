#include "stroboDoSom.h"
#include "stdint.h"


#define DEMO_ADC16_BASE ADC0
#define DEMO_ADC16_CHANNEL_GROUP 0U

static void init();
static void changeProp(int intensity, int velocity);
static void tick();

static void (*effect_runnable[3])() = {
	init,
	changeProp,
	tick
};


int sds_cores[3] = {2, 2, 40};

uint8_t sds_colors[4][3] = {
	{2,2,50},
	{40,0,0},
	{30,30,30},
	{2,40,2}
};

int sds_lastColor = 0;
int sds_counter = 0;

void sds_newColor() {
	sds_lastColor++;
	if(sds_lastColor > 3) {
		sds_lastColor = 0;
	}
	sds_cores[0] = sds_colors[sds_lastColor][0];
	sds_cores[1] = sds_colors[sds_lastColor][1];
	sds_cores[2] = sds_colors[sds_lastColor][2];
}


void* stroboDoSom_getRunnables(){
 return effect_runnable;
}

void init() {
	sds_newColor();
}

void changeProp(int intensity, int velocity) {
}

void tick() {
	sds_counter++;
	if(sds_counter == 40000) {
		sds_counter = 0;
		sds_newColor();
	}

	uint32_t valorADC = 4095 - ADC16_GetChannelConversionValue(DEMO_ADC16_BASE, DEMO_ADC16_CHANNEL_GROUP);

	if(valorADC < 1000) {
		valorADC = 0;
	}
	else{
		valorADC -= 1000;
	}



	/*
	 *  Ganho maximo
	 *  255 - good_red.
	 *
	 *  3095 -> 255
	 *  valorADC -> x
	 *
	 *  300x = 255*valor
	 *
	 */
	int intensity = (255 * valorADC) / 3095;

	int maisForte = 0;

	for(int i = 0; i < 3; i++) {
		if(sds_cores[i] > maisForte) {
			maisForte = sds_cores[i];
		}
	}

	if(sds_lastColor == 1) {
		intensity *= 1.50;
	}

	/*
	 * cor mais forte -> 100%
	 * cor comparasao -> x
	 */
	int red   = sds_cores[0]   + (intensity * (sds_cores[0]/maisForte));
	int green = sds_cores[1]   + (intensity * (sds_cores[1]/maisForte));
	int blue  = sds_cores[2]   + (intensity * (sds_cores[2]/maisForte));

	rgb_set_color(red, green, blue);
}
