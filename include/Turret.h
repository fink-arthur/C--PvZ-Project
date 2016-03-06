#pragma once
#include "Drawable.h"
#include <list>
#include <time.h>

class Turret: public Drawable{

	public:
	Turret(float x, float y, int damage, float at_sp, float bul_sp, float r_, float g_, float b_):
		posX(x + 0.05f),
		posY(y + 0.1f),
		bullet_damage(damage),
		attack_speed(at_sp),
		bullet_speed(bul_sp),
		r(r_),
		g(g_),
		b(b_),
		health_points(5){}
	~Turret();
	void draw();
	void act();
	void clear_bullets();

	float posX;
	float posY;
	float r;
	float g;
	float b;
	float length = 0.1f;
	float attack_speed;
	float bullet_speed;
	int bullet_damage;
	int health_points;
	long int time1 = time(0) * 1000;
	long int time2;
	std::list<float> bullets;
};
