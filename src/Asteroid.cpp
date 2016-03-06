#include "Asteroid.h"
#include "GraphicPrimitives.h"
#include <ctime>
#include <sys/time.h>

Asteroid::~Asteroid(){

}

void Asteroid::draw(){
	float myPosX[] = {posX - 0.05f, posX, posX + 0.05f, posX + 0.1f, posX, posX - 0.05f};
	std::vector<float> posXVect (myPosX, myPosX + sizeof(myPosX) / sizeof(int));
	float myPosY[] = {posY + 0.05f, posY + 0.1f, posY + 0.05f, posY, posY - 0.05f, posY - 0.05f};
	std::vector<float> posYVect (myPosY, myPosY + sizeof(myPosY) / sizeof(int));
	GraphicPrimitives::drawFillPolygone2D(posXVect, posYVect, 1.0f, 1.0f, 1.0f);
}

void Asteroid::act(){
	if (slowed) {
		posX = posX - (0.5 * speed);
	}
	else {
		posX = posX - speed;
	}
	struct timeval tp2;
	gettimeofday(&tp2, NULL);
	time2 = tp2.tv_sec * 1000000 + tp2.tv_usec;
	if (((time2 - time1) > 2000000) & slowed) {
		slowed -= 1;
		struct timeval tp1;
		gettimeofday(&tp1, NULL);
		time1 = tp1.tv_sec * 1000000 + tp1.tv_usec;
	}
}
