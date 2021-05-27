//
// Created by niels on 4/10/21.
//

#include "Engine.h"
#include "../map/tilemap/TileMapParser.h"

Engine::Engine(Renderer renderer) {
    this->renderer = renderer;
}

Engine::~Engine() {}

void Engine::run() {
    bool quit = false;
    Game game(&renderer);
    int tick = 0;
    int fpsCount = 0;
    while(!quit) {
        tick ++;
        Uint64 start = SDL_GetPerformanceCounter();
        Window::wait();
        quit = Window::handleInput();
        game.handleCollisions();
        game.update();
        Window::clearScreen(renderer);
        game.draw(renderer);
        SDL_RenderPresent(renderer.sdlRenderer);
        Window::setLastUpdatedTime();
        Uint64 end = SDL_GetPerformanceCounter();
        float elapsed = (end - start) / (float)SDL_GetPerformanceFrequency();
        fpsCount += 1.0f / elapsed;
        if (tick % 120 == 0) {
            std::cout << "Current FPS: " << std::to_string(fpsCount/120) << std::endl;
            fpsCount = 0;
        }
    }
    SDL_DestroyWindow(renderer.sdlWindow);
    SDL_Quit();
}