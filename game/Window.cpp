//
// Created by niels on 4/15/21.
//

#include <iostream>
#include "Window.h"
uint32_t Window::lastUpdatedTime = 0;
uint32_t Window::deltaTime = 0;
uint32_t Window::currentTime = 0;

bool Window::handleInput() {
    InputManager::renew();
    bool quit = false;
    SDL_Event e;
    while( SDL_PollEvent( &e )) {
        //User requests quit
        if( e.type == SDL_QUIT ) {
            quit = true;
        }
        if(e.type == SDL_KEYUP) {
             InputManager::setKeyUp(e.key.keysym.scancode);
        }
        if(e.type == SDL_KEYDOWN) {
            InputManager::setKeyDown(e.key.keysym.scancode);
        }
    }
    return quit;
}

void Window::clearScreen(Renderer * renderer) {
    SDL_SetRenderDrawColor(renderer->sdlRenderer, 9, 15, 15, 255);
    SDL_RenderClear(renderer->sdlRenderer);
}

void Window::wait() {
    currentTime = SDL_GetTicks();
    deltaTime = currentTime - lastUpdatedTime;
    int32_t timeToSleep = tickInterval - deltaTime;
    if(timeToSleep > 0) {
        SDL_Delay(timeToSleep);
    }
}

void Window::setLastUpdatedTime() {
    lastUpdatedTime = currentTime;
}
