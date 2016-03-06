
#include "MyControlEngine.h"


void MyControlEngine::MouseCallback(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    	float xf = (x - 400) / 400.0f; // Gives the percentage instead of the exact position
    	float yf = (y - 300) / 300.0f; // Gives the percentage instead of the exact position
    	env->update_environment(xf,yf);
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {

    }
}

void::MyControlEngine::KeyboardCallback(unsigned charkey, int x, int y) {
	env->restart();
}
