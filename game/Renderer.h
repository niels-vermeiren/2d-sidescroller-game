//
// Created by niels on 4/10/21.
//

#ifndef INC_2DSIDESCROLLER_RENDERER_H
#define INC_2DSIDESCROLLER_RENDERER_H
#include <SDL2/SDL.h>

class Renderer {
public:
    SDL_Window * sdlWindow;
    SDL_Renderer * sdlRenderer;
    static Renderer & getInstance();
};

#endif //INC_2DSIDESCROLLER_RENDERER_H
