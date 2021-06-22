//
// Created by niels on 4/10/21.
//

#include <thread>
#include <future>
#include "Engine.h"
#include "../map/tilemap/TileMapParser.h"
#include "../sound/JukeBox.h"

#include "LevelLoader.h"
#include "Level.h"
#include <chrono>

Engine::Engine(Renderer * renderer) {
    this->renderer = renderer;
}

Engine::~Engine() {}

typedef struct {
    Level * game;
    std::promise<bool> * p;
    SDL_mutex *pMutex;
} ThreadData;

int threadFunction(void *game) {
    ThreadData  * data = static_cast<ThreadData *>(game);
    data->game->load(data->pMutex);
    SDL_mutexP(data->pMutex);
    data->game->loadTextures();
    SDL_mutexV(data->pMutex);
    JukeBox::getInstance()->loadSounds();
    JukeBox::getInstance()->playMusic(JukeBox::BACKGROUND);
    data->game->update();
    data->game->draw();
    data->p->set_value(true);
    return 1;
}

void Engine::run() {

    bool quit = false;
    Level * game = new Level();

    SDL_Surface *loader = IMG_Load("../resources/loader/loading1.png");
    SDL_Texture *loaderTexture = SDL_CreateTextureFromSurface(renderer->sdlRenderer, loader);
    SDL_Point * center = new SDL_Point{128, 128};
    SDL_Rect * loadingRect = new SDL_Rect{SCREEN_WIDTH / 2 - 128, SCREEN_HEIGHT / 2 - 128, 256, 256};
    double angle = 0.0;
    int returnValue;
    SDL_FreeSurface(loader);
    TTF_Init();
    TTF_Font * gFont = TTF_OpenFont( "../resources/font/trulymadly.ttf", 28 );
    LTexture * lTexture = new LTexture(gFont);

    auto * renderMutex = SDL_CreateMutex();
    std::promise<bool> p;
    auto future = p.get_future();
    ThreadData * data = static_cast<ThreadData *>(malloc(sizeof(ThreadData)));
    data->game = game;
    data->p = &p;
    data->pMutex = renderMutex;
    SDL_Thread  * thread = SDL_CreateThread(threadFunction, "thread1", data);
    lTexture->loadFromRenderedText("Loading game assets, loading level..." , {255,255,255}, renderer);

    while(future.wait_for(std::chrono::milliseconds (0)) != std::future_status::ready) {
        Window::wait();
        angle+=2.5;
        Window::clearScreen(renderer);
        SDL_RenderCopyEx(renderer->sdlRenderer, loaderTexture, NULL, loadingRect, angle, center, SDL_FLIP_NONE);
        SDL_mutexP(renderMutex);
        lTexture->render( SCREEN_WIDTH - SCREEN_WIDTH/2 - lTexture->getWidth()/2, SCREEN_HEIGHT-SCREEN_HEIGHT/2-lTexture->getHeight()/2 + 200);
        SDL_mutexV(renderMutex);
        SDL_RenderPresent(renderer->sdlRenderer);
        Window::setLastUpdatedTime();
    }
    game->reset();
    int tick = 0;
    int fpsCount = 0;

    while(!quit) {
        Window::setLastUpdatedTime();
        Uint64 start = SDL_GetPerformanceCounter();
        tick ++;
        game->handleCollisions();
        game->update();
        Window::clearScreen(renderer);
        game->draw();
        quit = Window::handleInput();
        SDL_RenderPresent(renderer->sdlRenderer);
        Window::wait();
        Uint64 end = SDL_GetPerformanceCounter();
        float elapsed = (end - start) / (float)SDL_GetPerformanceFrequency();
        fpsCount += 1.0f / elapsed;
        if (tick % 120 == 0) {
            std::cout << "Current FPS: " << std::to_string(fpsCount/120) << std::endl;
            fpsCount = 0;
        }
    }
    SDL_DestroyTexture(loaderTexture);
    SDL_DestroyMutex(renderMutex);
    SDL_DestroyWindow(renderer->sdlWindow);
    SDL_Quit();
}