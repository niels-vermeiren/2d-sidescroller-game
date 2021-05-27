#include <iostream>
#include <SDL2/SDL.h>
#include "game/Renderer.h"
#include "game/Engine.h"
#include "defs.h"

int main() {


    SDL_Init (SDL_INIT_VIDEO);



    SDL_Window* window = nullptr;
    window = SDL_CreateWindow
            (
                    TITLE, SDL_WINDOWPOS_UNDEFINED,
                    SDL_WINDOWPOS_UNDEFINED,
                    SCREEN_WIDTH,
                    SCREEN_HEIGHT,
                    SDL_WINDOW_SHOWN
            );


    SDL_Surface *pSurface = SDL_GetWindowSurface(window);
    // Setup renderer
    SDL_Renderer* sdlRenderer = nullptr;
    sdlRenderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);

    Renderer & renderer = Renderer::getInstance();
    renderer.sdlRenderer = sdlRenderer;
    renderer.sdlWindow = window;

    Engine game(renderer);
    game.run();

    return EXIT_SUCCESS;
}
