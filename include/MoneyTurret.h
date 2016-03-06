#pragma once
#include "Turret.h"
#include <time.h>

class MoneyTurret: public Turret {

	public:
	MoneyTurret(float x, float y, int damage, float at_sp, float bul_sp, float r_, float g_, float b_):
		Turret(x,y,damage,at_sp,bul_sp,r_,g_,b_){}
	~MoneyTurret();
	void act();
	void draw();

	long int time1 = time(0) * 1000;
	long int time2;
};
