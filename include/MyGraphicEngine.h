#pragma once
#include "Environment.h"
#include "Engine.h"

class MyGraphicEngine:public GraphicEngine {
    
	public:
    MyGraphicEngine(Environment * env_):env(env_){}
    virtual void Draw();
    
    Environment * env;
};
