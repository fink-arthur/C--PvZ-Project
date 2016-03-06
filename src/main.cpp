#include <iostream>
#include "Engine.h"

#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"
#include "Environment.h"

int Environment::money = 400;
int Environment::health = 25;
int Environment::wave = 0;

int main(int argc, char * argv[])
{
    
    Engine e(argc,argv);
    
    Environment * env = new Environment();

    GraphicEngine * ge = new MyGraphicEngine(env);
    GameEngine * gme = new MyGameEngine(env);
    ControlEngine * ce = new MyControlEngine(env);
    
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
    
    e.start();
    return 0;
}
