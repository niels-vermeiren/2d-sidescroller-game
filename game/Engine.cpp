//
// Created by niels on 4/10/21.
//

#include <thread>
#include "Engine.h"
#include "../map/tilemap/TileMapParser.h"

Engine::Engine(Renderer * renderer) {
    this->renderer = renderer;
}

Engine::~Engine() {}

void Engine::run() {
    bool quit = false;
    Game * game = new Game(renderer);
    std::cout<<"loading" <<std::endl;
    std::thread t1(&Game::load,game, renderer);

    SDL_Rect r;
    r.x = SCREEN_WIDTH/2 - 175;
    r.y = SCREEN_HEIGHT/2-116;
    r.w = 351;
    r.h = 233;

    // Set render color to blue ( rect will be rendered in this color )
    
    SDL_Surface * loader = IMG_Load("../resources/loader/loading.gif");
    SDL_Texture * loaderTexture = SDL_CreateTextureFromSurface(renderer->sdlRenderer, loader);
    SDL_RenderCopy(renderer->sdlRenderer, loaderTexture, NULL, &r);
    // Render rect
    SDL_RenderPresent(renderer->sdlRenderer);
    t1.join();
    int tick = 0;
    int fpsCount = 0;
    while(!quit) {
        tick ++;
        Uint64 start = SDL_GetPerformanceCounter();
        Window::wait();
        quit = Window::handleInput();
        game->handleCollisions();
        game->update();
        Window::clearScreen(*renderer);
        game->draw(*renderer);
        SDL_RenderPresent(renderer->sdlRenderer);
        Window::setLastUpdatedTime();
        Uint64 end = SDL_GetPerformanceCounter();
        float elapsed = (end - start) / (float)SDL_GetPerformanceFrequency();
        fpsCount += 1.0f / elapsed;
        if (tick % 120 == 0) {
            std::cout << "Current FPS: " << std::to_string(fpsCount/120) << std::endl;
            fpsCount = 0;
        }
    }
    SDL_DestroyWindow(renderer->sdlWindow);
    SDL_Quit();
}