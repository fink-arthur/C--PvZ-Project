#pragma once
#include "Drawable.h"
#include "Turret.h"

class Checkerboard:public Drawable{

	public:
	Checkerboard();
	~Checkerboard();
	virtual void draw();
	virtual void act();
	void clear_turrets_bullets();
	void clear_turrets();

	float block_width;
	float block_height;
	int number_of_columns;
	int number_of_lines;
	float strip_size = 0.4;
	Turret ** checkers_array;
};
