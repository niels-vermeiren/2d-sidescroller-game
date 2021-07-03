//
// Created by niels on 4/15/21.
//

#ifndef INC_2DSIDESCROLLER_WINDOW_H
#define INC_2DSIDESCROLLER_WINDOW_H
#include <SDL2/SDL.h>
#include "Renderer.h"
#include "../input/InputManager.h"
class Window {
public:
    static bool handleInput();
    static void clearScreen(Renderer * renderer);
    static void wait();
    static void setLastUpdatedTime();
    static const int FPS = 65;
    static uint32_t lastUpdatedTime, deltaTime, currentTime;
    static const uint32_t tickInterval = 1000/FPS;
};


#endif //INC_2DSIDESCROLLER_WINDOW_H
