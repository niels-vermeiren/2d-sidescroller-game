//
// Created by niels on 4/10/21.
//

#ifndef INC_2DSIDESCROLLER_ENGINE_H
#define INC_2DSIDESCROLLER_ENGINE_H
#include "Renderer.h"
#include <SDL2/SDL.h>
#include <iostream>
#include "../entity/Player.h"
#include "../entity/Platform.h"
#include "../entity/EntityManager.h"
#include "Window.h"
#include "Game.h"

class Engine {
private:
    Renderer renderer;
public:
    Engine(Renderer renderer);
    ~Engine();
    void run();
};


#endif //INC_2DSIDESCROLLER_ENGINE_H
