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
    std::string level;
} ThreadData;

int threadFunction(void *game) {
    ThreadData  * data = static_cast<ThreadData *>(game);;
    data->game->load(data->pMutex, data->level);
    data->p->set_value(true);

    return 1;
}

void Engine::run() {

    bool quit = false;
    Level * game = new Level();
    auto * renderMutex = SDL_CreateMutex();
    SDL_Surface *loader = IMG_Load("../resources/loader/loading1.png");
    SDL_Texture *loaderTexture = SDL_CreateTextureFromSurface(renderer->sdlRenderer, loader);
    SDL_Point * center = new SDL_Point{128, 128};
    SDL_Rect * loadingRect = new SDL_Rect{SCREEN_WIDTH / 2 - 128, SCREEN_HEIGHT / 2 - 128, 256, 256};
    double angle = 0.0;
    int returnValue;
    TTF_Init();
    TTF_Font * gFont = TTF_OpenFont( "../resources/font/trulymadly.ttf", 28 );
    lTexture = new LTexture(gFont);
    lTexture->loadFromRenderedText("Loading 2d-SideScroller levels..." , {255,255,255}, renderer);

    std::promise<bool> finished1;
    auto future1 = finished1.get_future();
    std::promise<bool> finished2;
    auto future2 = finished2.get_future();
    std::promise<bool> finished3;
    auto future3 = finished3.get_future();
    std::promise<bool> finished4;
    auto future4 = finished4.get_future();
    auto * data = new ThreadData ();
    data->game = game;
    data->p = &finished1;
    data->pMutex = renderMutex;
    data->level = LevelLoader::LEVEL_1;
    SDL_Thread  * thread = SDL_CreateThread(threadFunction, "thread1", data);
    auto * data2 =new ThreadData ();
    data2->game = game;
    data2->p = &finished2;
    data2->pMutex = renderMutex;
    data2->level = LevelLoader::LEVEL_2;
    SDL_Thread * thread2 = SDL_CreateThread(threadFunction, "thread2", data2);
    auto * data3 = new ThreadData ();
    data3->game = game;
    data3->p = &finished3;
    data3->pMutex = renderMutex;
    data3->level = LevelLoader::LEVEL_3;
    SDL_Thread * thread3 = SDL_CreateThread(threadFunction, "thread3", data3);
    auto * data4 = new ThreadData ();
    data4->game = game;
    data4->p = &finished4;
    data4->pMutex = renderMutex;
    data4->level = LevelLoader::DEV_LEVEL;
    SDL_Thread * thread4 = SDL_CreateThread(threadFunction, "thread4", data4);



    bool level1Finished = future1.wait_for(std::chrono::milliseconds (0)) == std::future_status::ready;
    bool level2Finished = future2.wait_for(std::chrono::milliseconds (0)) == std::future_status::ready;
    bool level3Finished = future3.wait_for(std::chrono::milliseconds (0)) == std::future_status::ready;
    bool level4Finished = future4.wait_for(std::chrono::milliseconds (0)) == std::future_status::ready;


    while(!level1Finished || !level2Finished || !level3Finished|| !level4Finished) {
        Window::wait();
        angle+=2.5;
        Window::clearScreen(renderer);

        SDL_RenderCopyEx(renderer->sdlRenderer, loaderTexture, NULL, loadingRect, angle, center, SDL_FLIP_NONE);
        lTexture->render( SCREEN_WIDTH - SCREEN_WIDTH/2 - lTexture->getWidth()/2, SCREEN_HEIGHT-SCREEN_HEIGHT/2-lTexture->getHeight()/2 + 200);
        SDL_RenderPresent(renderer->sdlRenderer);
        Window::setLastUpdatedTime();
        level1Finished = future1.wait_for(std::chrono::milliseconds (0)) == std::future_status::ready;
        level2Finished = future2.wait_for(std::chrono::milliseconds (0)) == std::future_status::ready;
        level3Finished = future3.wait_for(std::chrono::milliseconds (0)) == std::future_status::ready;
        level4Finished = future4.wait_for(std::chrono::milliseconds (0)) == std::future_status::ready;
        char buff[250];
        snprintf(buff, sizeof(buff), " Levels %s%s%s%s loaded.", level1Finished?"1, ":"", level2Finished?"2, ":"", level3Finished?"3, ":"", level4Finished?"4":"");
        std::string levelsLoaded = buff;
        if(level4Finished) lTexture->loadFromRenderedText("Loading 2d-SideScroller.." + levelsLoaded , {255,255,255}, renderer);

    }
    Window::clearScreen(renderer);

    SDL_RenderCopyEx(renderer->sdlRenderer, loaderTexture, NULL, loadingRect, angle, center, SDL_FLIP_NONE);
    lTexture->loadFromRenderedText("Loading 2d-SideScroller levels done. Finishing..." , {255,255,255}, renderer);
    lTexture->render( SCREEN_WIDTH - SCREEN_WIDTH/2 - lTexture->getWidth()/2, SCREEN_HEIGHT-SCREEN_HEIGHT/2-lTexture->getHeight()/2 + 200);
    SDL_RenderPresent(renderer->sdlRenderer);
    game->loadTextures(LevelLoader::LEVEL_1);
    game->loadTextures(LevelLoader::LEVEL_2);
    game->loadTextures(LevelLoader::LEVEL_3);
    game->loadTextures(LevelLoader::DEV_LEVEL);
    JukeBox::getInstance()->loadSounds();
    JukeBox::getInstance()->playMusic(JukeBox::BACKGROUND);
    game->reset();
    game->update();

    int tick = 0;
    int fpsCount = 0;

    while(!quit) {
        Uint64 start = SDL_GetPerformanceCounter();
        Window::setLastUpdatedTime();
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