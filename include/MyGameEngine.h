#pragma once
#include "Engine.h"
#include "Environment.h"

class MyGameEngine:public GameEngine {

	public:
    MyGameEngine(Environment * env_):env(env_){}
    virtual void idle();

    long int time1 = time(0)*1000;
    long int time2;
    Environment * env;
};
