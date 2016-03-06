#pragma once
#include "Checkerboard.h"
#include "Strip.h"
#include "Asteroid.h"
#include "WaveLauncher.h"

class Environment{

	public:
	Environment();
	~Environment();
	void draw();
	void act();
	void update_environment(float x, float y);
	void update_checkerboard(int i, int j);
	void update_strip(int i);
	int line_clicked_checkerboard(float x, float y);
	int column_clicked_checkerboard(float x, float y);
	int column_clicked_strip(float x, float y);
	int collision(int line);
	void restart();

	Checkerboard * board;
	Strip * strip;
	WaveLauncher * launcher;
	std::list<Asteroid*> * asteroids;
	bool running;
	bool game_over;
	static int money;
	static int health;
	static int wave;
};
