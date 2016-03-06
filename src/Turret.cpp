#include "Turret.h"
#include "GraphicPrimitives.h"
#include <ctime>
#include <sys/time.h>
#include <iostream>

Turret::~Turret() {

}

/* This function draws the turret */
void Turret::draw() {
	GraphicPrimitives::drawFillTriangle2D(posX, posY + 0.5 * length, posX + length, posY, posX, posY - 0.5 * length, r, g, b);
	GraphicPrimitives::drawFillRect2D(posX - 0.01f, posY + 0.06f, 0.12f, 0.026f, 0.0f, 0.0f, 0.0f);
	for( int i = 0; i < health_points; i++) {
		GraphicPrimitives::drawFillRect2D((posX - 0.008f) + (i * 0.023), posY + 0.062f, 0.023f, 0.02f, 1.0f, 1.0f, 1.0f);
	}
	for (std::list<float>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
			GraphicPrimitives::drawFillRect2D(*it, posY, 0.02f, 0.02f, 1.0f, 0.0f, 1.0f);
		}
}
 /* This function makes all the bullet of the turret move and destroys, creates a new bullet
  * based on the attack speed of the turret, the one that go further than the right side of the screen */
void Turret::act() {
	struct timeval tp2;
	gettimeofday(&tp2, NULL);
	time2 = tp2.tv_sec * 1000000 + tp2.tv_usec;
	if ((time2 - time1) > (attack_speed * 1000000)) {
		bullets.push_front(posX + length);
		struct timeval tp1;
		gettimeofday(&tp1, NULL);
		time1 = tp1.tv_sec * 1000000 + tp1.tv_usec;
	}
	for (std::list<float>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
		*it = *it + bullet_speed;
	}
	if (bullets.back() > 1.0f) {
		bullets.pop_back();
	}
}

/* This function clears all the bullets of the turret */
void Turret::clear_bullets() {
	while (!bullets.empty()) {
		bullets.pop_back();
	}
}
