#pragma once
#include "Asteroid.h"
#include <list>

class WaveLauncher {

	public:
	WaveLauncher(std::list<Asteroid*> * ast_):
		ast(ast_),
		wave(0),
		number_of_asteroids(10),
		speed_of_asteroids(0.01f),
		health_of_asteroids(50){}
	~WaveLauncher();
	int launch();
	void new_wave();
	void restart();

	std::list<Asteroid*> * ast;
	long int time1 = 0;
	long int time2;
	int wave;
	int current_number;
	int number_of_asteroids;
	float speed_of_asteroids;
	int health_of_asteroids;
};
