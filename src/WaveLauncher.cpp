#include "WaveLauncher.h"
#include <ctime>
#include <sys/time.h>
#include <stdlib.h>

/* This function launches the waves of asteroids first on only one line and wave by wave we increment
 * that number by one, with one asteroid popping on a random line every second */
int WaveLauncher::launch(){
	if (current_number < number_of_asteroids) {
		int mod = ((wave > 8) ? 8 : wave);
		struct timeval tp2;
		gettimeofday(&tp2, NULL);
		time2 = tp2.tv_sec * 1000000 + tp2.tv_usec;
		if (time2 - time1 > 1000000){
			int r = rand() % mod;
			int ra = rand() % 100;
			if (ra < 70) {
				ast[r].push_front(new Asteroid(0.9f,-1.0f + (r * 0.2f) + 0.09f,health_of_asteroids,speed_of_asteroids));
			}
			else {
				ast[r].push_front(new Asteroid(0.9f,-1.0f + (r * 0.2f) + 0.09f,health_of_asteroids * 2,speed_of_asteroids * 2));
			}
			current_number += 1;
			struct timeval tp1;
			gettimeofday(&tp1, NULL);
			time1 = tp1.tv_sec * 1000000 + tp1.tv_usec;
		}
		return 0;
	}
	return 1;
}

/* This function ups the game's difficulty every wave */
void WaveLauncher::new_wave() {
	wave += 1;
	current_number = 0;
	health_of_asteroids *= 1.3;
	speed_of_asteroids *= 1.15;
	number_of_asteroids *= 1.2;
}

/* This function retarts the wave with their initial values */
void WaveLauncher::restart() {
	wave = 0;
	number_of_asteroids = 10;
	speed_of_asteroids = 0.01f;
	health_of_asteroids = 100;
}
