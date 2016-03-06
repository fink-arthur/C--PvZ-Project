#pragma once
#include "Engine.h"
#include "Environment.h"

class MyControlEngine:public ControlEngine {

	public:
    MyControlEngine(Environment * env_):env(env_){}
    virtual void MouseCallback(int button, int state, int x, int y);
    virtual void KeyboardCallback(unsigned charkey, int, int y);

    Environment * env;
};
