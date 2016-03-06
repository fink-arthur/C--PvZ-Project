#pragma once
#include "Drawable.h"
#include <time.h>

class Asteroid: public Drawable {

	public:
	Asteroid(float x, float y, int health, float sp):posX(x),posY(y),health_points(health),speed(sp),slowed(0){}
	~Asteroid();
	void draw();
	void act();

	float posX;
	float posY;
	float speed;
	int health_points;
	int slowed;
	long int time1 = time(0) * 1000;
	long int time2;
};
