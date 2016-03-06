#include "MoneyTurret.h"
#include "Environment.h"
#include "GraphicPrimitives.h"
#include <ctime>
#include <sys/time.h>

MoneyTurret::~MoneyTurret(){

}

/* This function makes the player gain 4 money every second the game is running */
void MoneyTurret::act() {
	struct timeval tp2;
	gettimeofday(&tp2, NULL);
	time2 = tp2.tv_sec * 1000000 + tp2.tv_usec;
	if ((time2 - time1) > 1000000) {
		Environment::money += 4;
		struct timeval tp1;
		gettimeofday(&tp1, NULL);
		time1 = tp1.tv_sec * 1000000 + tp1.tv_usec;
	}
}

/* This function draws the turret */
void MoneyTurret::draw() {
	GraphicPrimitives::drawFillRect2D(posX - 0.003f, posY - 0.05f, 0.1f, 0.1f, r, g, b);
	GraphicPrimitives::drawFillRect2D(posX - 0.01f, posY + 0.06f, 0.12f, 0.026f, 0.0f, 0.0f, 0.0f);
	for( int i = 0; i < health_points; i++) {
		GraphicPrimitives::drawFillRect2D((posX - 0.008f) + (i * 0.023), posY + 0.062f, 0.023f, 0.02f, 1.0f, 1.0f, 1.0f);
	}
}
