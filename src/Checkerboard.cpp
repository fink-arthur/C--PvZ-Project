#include "Checkerboard.h"
#include "GraphicPrimitives.h"


Checkerboard::Checkerboard() {
	block_height = 0.20f;
	block_width = 0.20f;
	number_of_lines = (2.0f - strip_size) / block_height;
	number_of_columns = 2.0f / block_width;
	// checkers_array is a pseudo-multidimensional array
	checkers_array = new Turret * [number_of_columns * number_of_lines];
	for (int i = 0; i < number_of_lines; i++) {
		for (int j = 0; j < number_of_columns; j++){
			checkers_array[i * number_of_columns + j] = NULL;
		}
	}
}

Checkerboard::~Checkerboard(){
	delete [] checkers_array;
}

/*This function draws the checkerboard and leaves enough place for the rest of the ui*/
void Checkerboard::draw(){
	// This loop draws the checkerboard itself
	for (int j = 0; j < number_of_lines; j++){
		for (int i = 0; i < number_of_columns; i++) {
			if ((i % 2 == 0) & (j % 2 == 0)){
				GraphicPrimitives::drawFillRect2D(-1.0f + (i * block_width),-1.0f + (j * block_height),block_width,block_height,1.0f,0.0f,0.0f);
			}
			else if ((i % 2 == 0) & (j % 2 == 1)){
				GraphicPrimitives::drawFillRect2D(-1.0f + (i * block_width),-1.0f + (j * block_height),block_width,block_height,0.0f,1.0f,0.0f);
			}
			else if ((i % 2 == 1) & (j % 2 == 0)){
				GraphicPrimitives::drawFillRect2D(-1.0f + (i * block_width),-1.0f + (j * block_height),block_width,block_height,0.0f,1.0f,0.0f);
			}
			else {
				GraphicPrimitives::drawFillRect2D(-1.0f + (i * block_width),-1.0f + (j * block_height),block_width,block_height,1.0f,0.0f,0.0f);
			}
		}
	}
	// This loop draws the turret placed on the checkerboard
	for (int i = 0; i < number_of_lines; i++) {
		for (int j = 0; j < number_of_columns; j++){
			Turret * tmp = checkers_array[i * number_of_columns + j];
			if (tmp != NULL) {
				tmp->draw();
			}
		}
	}
}

void Checkerboard::act() {
	// This loop makes the turret placed on the checkerboard act
	for (int i = 0; i < number_of_lines; i++) {
		for (int j = 0; j < number_of_columns; j++){
			Turret * tmp = checkers_array[i * number_of_columns + j];
			if (tmp != NULL) {
				tmp->act();
			}
		}
	}
}

/* Clears all the bullets in all the turrets in the array */
void Checkerboard::clear_turrets_bullets() {
	for (int i = 0; i < number_of_lines; i++) {
		for (int j = 0; j < number_of_columns; j++){
			Turret * tmp = checkers_array[i * number_of_columns + j];
			if (tmp != NULL) {
				tmp->clear_bullets();
			}
		}
	}
}

/* Clears all the turrets in the array */
void Checkerboard::clear_turrets() {
	clear_turrets_bullets();
	delete [] checkers_array;
	checkers_array = new Turret * [number_of_columns * number_of_lines];
	for (int i = 0; i < number_of_lines; i++) {
		for (int j = 0; j < number_of_columns; j++){
			checkers_array[i * number_of_columns + j] = NULL;
		}
	}
}
