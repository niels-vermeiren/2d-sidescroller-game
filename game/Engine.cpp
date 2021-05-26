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
    while(!quit) {
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
        std::cout << "Current FPS: " << std::to_string(1.0f / elapsed) << std::endl;
    }
    SDL_DestroyWindow(renderer.sdlWindow);
    SDL_Quit();
}