/*
 * Efeitos
 */
#include "effect/camaleao.h"
#include "effect/strobo.h"
#include "effect/stroboDoSom.h"


void startEffect(int effectID, int effectSpeed, int effectIntensity);
void stopEffect();
void effectTick();
short hasEffect();
int getRand(int min, int max);
