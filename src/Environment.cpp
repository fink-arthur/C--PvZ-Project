#include "Environment.h"
#include "Turret.h"
#include "MoneyTurret.h"
#include "SlowTurret.h"
#include "GraphicPrimitives.h"
#include <iostream>

Environment::Environment() {
	board = new Checkerboard;
	strip = new Strip;
	asteroids = new std::list<Asteroid*> [board->number_of_lines];
	launcher = new WaveLauncher(asteroids);
	running = false;
	game_over = false;
}

Environment::~Environment() {
	delete board;
	delete strip;
	delete [] asteroids;
}

/* This function draws all the environment, the board with all the turrets and their bullets,
 * the strip, the asteroid and the game over message if necessary */
void Environment::draw() {
	board->draw();
	strip->draw();
	for (int i = 0; i < board->number_of_lines; i++) {
		for (std::list<Asteroid*>::iterator it = asteroids[i].begin(); it != asteroids[i].end(); ++it) {
			(*it)->draw();
		}
	}
	if (game_over) {
		char game_overBuffer [50];
		sprintf (game_overBuffer,"Game Over");
		GraphicPrimitives::drawText2D(game_overBuffer,-0.1f,0.0f,0.0f,0.0f, 0.0f);
		char game_over2Buffer [50];
		sprintf (game_over2Buffer,"Press any key to restart");
		GraphicPrimitives::drawText2D(game_over2Buffer,-0.1f,-0.15f,0.0f,0.0f, 0.0f);
	}
}

/* This function calls the act method on all the elements if the game is running and
 * not in a game over state */
void Environment::act() {
	if (running & !game_over) {
		board->act();
		int finished_launching = launcher->launch(); // warns us when all the asteroids are launched

		// this loop will call act on all the asteroids plus a swap if necessary
		for (int i = 0; i < board->number_of_lines; i++) {
			// Make the player lose one health when an asteroid reaches the left side of the screen
			if (!asteroids[i].empty() && asteroids[i].back()->posX <= -1.0f) {
				asteroids[i].pop_back();
				Environment::health -= 1;
			}

			// This part of the function will call act on each asteroid and swap their position
			// in the list if one takes over another
			if (asteroids[i].empty()) {
			}
			else if ((asteroids[i].size() < 2) & !asteroids[i].empty()) {
				asteroids[i].front()->act();
			}
			else {
				auto it2 = asteroids[i].begin();
				auto it1 = it2++;
				auto e = asteroids[i].end();
				for (;;) {
					(*it1)->act();

					if ((*it1)->posX < (*it2)->posX) {
						std::swap(*it1, *it2);
					}
					it1 = it2++;
					if (it2 == e) {
						(*it1)->act();
						break;
					}
				}
			}

		}

		// calls the colission method on each line of asteroid
		for (int i = 0; i < board->number_of_lines; i++) {
			collision(i);
		}

		// we check if there are no more asteroids
		bool no_more_asteroids = true;
		for (int i = 0; i < board->number_of_lines; i++) {
			if (!asteroids[i].empty()) {
				no_more_asteroids = false;
			}
		}
		// if all the asteroids have been launched and destroyd the wave is finished
		if (finished_launching & no_more_asteroids) {
			board->clear_turrets_bullets();
			running = false;
		}

		// if we have no more health the game stops
		if (health <= 0) {
			game_over = true;
		}
	}
}

/* Updates the environment, choosing between either the board or the strip depending
 * on where you clicked */
void Environment::update_environment(float x, float y) {
	if (game_over) {
		restart();
	}
	else if (y > -0.6f) {
		int i = line_clicked_checkerboard(x, y);
		int j = column_clicked_checkerboard(x, y);
		update_checkerboard(i, j);
	}
	else {
		update_strip(column_clicked_strip(x, y));
	}
}

/* Updates the strip with on a click on the element i */
void Environment::update_strip(int i) {
	if ((i >= 8) & !running) {
		running = true;
		launcher->new_wave();
		wave += 1;
	}
	if (i < 8 & i >= 2) {
		strip->setSelection(i - 2);
	}
}

/* Updates the checkers_array [i][j] element if the game isn't over */
void Environment::update_checkerboard(int i, int j) {
	Turret * tmp = board->checkers_array[i * board->number_of_columns + j];
	if ((tmp == NULL) & !game_over & !running) {
		if (strip->selection == 0 & money >= 40) {
			board->checkers_array[i * board->number_of_columns + j] = new Turret (-1.0f + (j * board->block_width), -1.0f + (i * board->block_height), 20, 1.0f, 0.01f,0.2f, 0.8f, 1.0f);
			money -= 40;
		}
		else if (strip->selection == 1 & money >= 80) {
			board->checkers_array[i * board->number_of_columns + j] = new Turret (-1.0f + (j * board->block_width), -1.0f + (i * board->block_height), 40, 1.0f, 0.01f,0.4f, 1.0f, 0.6f);
			money -= 80;
		}
		else if (strip->selection == 2 & money >= 40) {
			board->checkers_array[i * board->number_of_columns + j] = new Turret (-1.0f + (j * board->block_width), -1.0f + (i * board->block_height), 10, 0.5f, 0.01f,0.6f, 0.2f, 0.4f);
			money -= 40;
		}
		else if (strip->selection == 3 & money >= 80) {
			board->checkers_array[i * board->number_of_columns + j] = new Turret (-1.0f + (j * board->block_width), -1.0f + (i * board->block_height), 20, 0.5f, 0.01f,0.4f, 0.2f, 0.6f);
			money -= 80;
		}
		else if (strip->selection == 4 & money >= 70) {
			board->checkers_array[i * board->number_of_columns + j] = new MoneyTurret(-1.0f + (j * board->block_width), -1.0f + (i * board->block_height), 0, 0.5f, 0.01f, 1.0f, 1.0f, 1.0f);
			money -= 70;
		}
		else if (strip->selection == 5 & money >= 30) {
			board->checkers_array[i * board->number_of_columns + j] = new SlowTurret(-1.0f + (j * board->block_width), -1.0f + (i * board->block_height), -1, 0.5f, 0.01f, 0.5f, 0.5f, 1.0f);
			money -= 30;
		}
	}
}

/* Returns the line clicked on the checkerboard */
int Environment::line_clicked_checkerboard(float x, float y) {
	return board->number_of_lines - ((y + 1.0f) / board->block_height) + 2;
}

/* Returns the column clicked on the checkerboard */
int Environment::column_clicked_checkerboard(float x, float y) {
	return (x + 1.0f) / board->block_width;
}

/* Returns the column clicked on the strip */
int Environment::column_clicked_strip(float x, float y) {
	return (x + 1.0f) / 0.2f;
}

/* This function retarts the game with all the initial values */
void Environment::restart() {
	health = 25;
	money = 400;
	wave = 0;
	running = false;
	game_over = false;
	board->clear_turrets();
	for (int i = 0; i < board->number_of_lines; i++) {
		while (!asteroids[i].empty()) {
			asteroids[i].pop_back();
		}
	}
	launcher->restart();
}

/* This function will look at the last asteroid and the last bullet of each turret on the same
 * line and look if there is a collision */
int Environment::collision(int line) {
	if (!asteroids[line].empty()) { // if the line is empty we do nothing
		Asteroid* it = asteroids[line].back();
		float posX = it->posX;
		for (int j = 0; j < board->number_of_columns; j++){
			Turret * tmp = board->checkers_array[line * board->number_of_columns + j];
			if (tmp != NULL) {
				// if there are bullets we look at it's position compared to the asteroid's
				if (!tmp->bullets.empty()) {
					float it2 = tmp->bullets.back();
					if (it2 > posX) {
						tmp->bullets.pop_back();
						if (tmp->bullet_damage == -1) { // special bullet that slows instead of doing damage
							it->slowed += 2;
						}
						else {
							it->health_points -= tmp->bullet_damage;
						}
						// if the asteroid has less than 0 health we destroy it and gain 10 money
						if (it->health_points <= 0) {
							Environment::money += 10;
							asteroids[line].pop_back();
							// we stop the function if the asteroid line is empty
							if (asteroids[line].empty()) {
								return 0;
							}
						}
					}
				}
				// we look if the asteroid can collide with the turret itself
				if ((tmp->posX > posX)) {
					tmp->health_points -= 1;
					asteroids[line].pop_back();
					// if it has no more health point we destroy the turret
					if (tmp->health_points <= 0) {
						delete tmp;
						board->checkers_array[line * board->number_of_columns + j] = NULL;
					}
					// we stop the function if the asteroid line is empty
					if (asteroids[line].empty()) {
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
