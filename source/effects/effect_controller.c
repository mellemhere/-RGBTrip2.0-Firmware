#include "effect_controller.h"
#include "fsl_gpio.h"
#include "time.h"

void (*effect_runnable[3])();

/*
 * Estamos em efeito?
 */
short currentlyInEffect = 0;

/*
 * ID do efeito atual
 */
int currentEffectID = 0;


void startEffect(int effectID, int effectSpeed, int effectIntensity) {
	currentEffectID = effectID;

	switch(effectID) {
	case 1:
		memcpy(effect_runnable, camaleao_getRunnables(), sizeof(effect_runnable));
		break;
	case 2:
		memcpy(effect_runnable, strobo_getRunnables(), sizeof(effect_runnable));
		break;
	case 3:
		memcpy(effect_runnable, stroboColorido_getRunnables(), sizeof(effect_runnable));
		break;
	case 4:
		memcpy(effect_runnable, stroboDoSom_getRunnables(), sizeof(effect_runnable));
		break;
	default:
		/*
		 * Na duvida faz camaleao
		 */
		currentEffectID = 1;
		memcpy(effect_runnable, camaleao_getRunnables(), sizeof(effect_runnable));
		break;
	}

	effect_runnable[0](); //Inicia

	if(effectIntensity != 0 || effectSpeed != 0) {
		effect_runnable[1](effectIntensity, effectSpeed); // Passa possiveis configuracoes
	}

	currentlyInEffect = 1;
}

void stopEffect(){
	currentlyInEffect = 0;
}

void effectTick(){
	/*
	 * Executa o tick do efeito, se estivermos em efeito..
	 */
	if(currentlyInEffect) {
		effect_runnable[2](); // tick
	}
}

short hasEffect() {
	return currentlyInEffect;
}

int getRand(int min, int max) {
	return rand() % max + min;
}
