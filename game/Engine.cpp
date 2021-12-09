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
#include "Scoreboard.h"
#include <chrono>

Engine::Engine(Renderer * renderer) {
    this->renderer = renderer;
}

Engine::~Engine() {}

typedef struct {
    Level * game;
    std::promise<bool> * p;
    std::string level;
} ThreadData;

int threadFunction(void *game) {
    ThreadData  * data = static_cast<ThreadData *>(game);;
    data->game->load(data->level);
    data->p->set_value(true);

    return 1;
}

void Engine::run() {

    bool quit = false;
    Level * game = Level::getInstance();
    SDL_Surface *loader = IMG_Load("../resources/loader/loading1.png");
    SDL_Texture *loaderTexture = SDL_CreateTextureFromSurface(renderer->sdlRenderer, loader);
    SDL_Point * center = new SDL_Point{128, 128};
    SDL_Rect * loadingRect = new SDL_Rect{SCREEN_WIDTH / 2 - 128, SCREEN_HEIGHT / 2 - 128, 256, 256};
    double angle = 0.0;
    int returnValue;
    TTF_Init();
    TTF_Font * gFont = TTF_OpenFont( "../resources/font/trulymadly.ttf", 28 );
    lTexture = new LTexture(gFont);
    lTexture->loadFromRenderedText("Loading 2d-SideScroller levels..." , {255,255,255});

    std::promise<bool> finished1;
    auto future1 = finished1.get_future();
    std::promise<bool> finished2;
    auto future2 = finished2.get_future();
    std::promise<bool> finished3;
    auto future3 = finished3.get_future();
    std::promise<bool> finished4;
    auto future4 = finished4.get_future();
    std::promise<bool> finished5;
    auto future5 = finished5.get_future();
    auto * data = new ThreadData ();
    data->game = game;
    data->p = &finished1;
    data->level = LevelLoader::LEVEL_1;
    SDL_Thread  * thread = SDL_CreateThread(threadFunction, "thread1", data);
    auto * data2 =new ThreadData ();
    data2->game = game;
    data2->p = &finished2;
    data2->level = LevelLoader::LEVEL_2;
    SDL_Thread * thread2 = SDL_CreateThread(threadFunction, "thread2", data2);
    auto * data3 =new ThreadData ();
    data3->game = game;
    data3->p = &finished3;
    data3->level = LevelLoader::LEVEL_3;
    SDL_Thread * thread3 = SDL_CreateThread(threadFunction, "thread3", data3);
    auto * data4 = new ThreadData ();
    data4->game = game;
    data4->p = &finished4;
    data4->level = LevelLoader::LEVEL_4;
    SDL_Thread * thread4 = SDL_CreateThread(threadFunction, "thread4", data4);
    auto * data5 = new ThreadData ();
    data5->game = game;
    data5->p = &finished5;
    data5->level = LevelLoader::DEV_LEVEL;
    SDL_Thread * thread5 = SDL_CreateThread(threadFunction, "thread5", data5);

    bool level1Finished = future1.wait_for(std::chrono::milliseconds (0)) == std::future_status::ready;
    bool level2Finished = future2.wait_for(std::chrono::milliseconds (0)) == std::future_status::ready;
    bool level3Finished = future3.wait_for(std::chrono::milliseconds (0)) == std::future_status::ready;
    bool level4Finished = future4.wait_for(std::chrono::milliseconds (0)) == std::future_status::ready;
    bool level5Finished = future5.wait_for(std::chrono::milliseconds (0)) == std::future_status::ready;

    while(!level1Finished || !level2Finished || !level3Finished|| !level4Finished || !level5Finished) {
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
        level5Finished = future5.wait_for(std::chrono::milliseconds (0)) == std::future_status::ready;
        char buff[250];
        snprintf(buff, sizeof(buff), " Levels %s%s%s%s%s loaded.", level1Finished?"1, ":"", level2Finished?"2, ":"", level3Finished?"3, ":"", level4Finished?"4, ":"", level5Finished?"5":"");
        std::string levelsLoaded = buff;
        bool someLevelLoaded = level1Finished || level2Finished || level3Finished|| level4Finished || level5Finished;
        if(someLevelLoaded) lTexture->loadFromRenderedText("Loading 2d-SideScroller.." + levelsLoaded , {255,255,255});

    }
    Window::clearScreen(renderer);

    SDL_RenderCopyEx(renderer->sdlRenderer, loaderTexture, NULL, loadingRect, angle, center, SDL_FLIP_NONE);
    lTexture->loadFromRenderedText("Loading 2d-SideScroller levels done. Finishing..." , {255,255,255});
    lTexture->render( SCREEN_WIDTH - SCREEN_WIDTH/2 - lTexture->getWidth()/2, SCREEN_HEIGHT-SCREEN_HEIGHT/2-lTexture->getHeight()/2 + 200);
    SDL_RenderPresent(renderer->sdlRenderer);
    game->loadTextures(LevelLoader::LEVEL_1);
    game->loadTextures(LevelLoader::LEVEL_2);
    game->loadTextures(LevelLoader::LEVEL_3);
    game->loadTextures(LevelLoader::LEVEL_4);
    game->loadTextures(LevelLoader::DEV_LEVEL);
    JukeBox::getInstance()->loadSounds();
    JukeBox::getInstance()->playMusic(JukeBox::BACKGROUND);
    game->reset();
    game->update();
    Scoreboard * scoreboard = new Scoreboard();
    int tick = 0;
    int fpsCount = 0;

    while(!quit) {
        Uint64 start = SDL_GetPerformanceCounter();
        Window::setLastUpdatedTime();
        tick ++;

        Window::clearScreen(renderer);
        if(game->getCurrentLevel() == 6) {
            SDL_Rect * newvp = new SDL_Rect{0, 0, SCREEN_WIDTH,SCREEN_HEIGHT};
            SDL_RenderSetViewport(renderer->sdlRenderer, newvp);
            scoreboard->draw();
        } else {
            game->handleCollisions();
            game->update();
            game->draw();
        }

        quit = Window::handleInput();
        SDL_RenderPresent(renderer->sdlRenderer);
        Window::wait();
        Uint64 end = SDL_GetPerformanceCounter();
        float elapsed = (end - start) / (float)SDL_GetPerformanceFrequency();
        fpsCount += 1.0f / elapsed;
        if (tick % 700 == 0) {
            std::cout << "Current FPS: " << std::to_string(fpsCount/700) << std::endl;
            fpsCount = 0;
        }
    }
    SDL_DestroyTexture(loaderTexture);
    SDL_DestroyWindow(renderer->sdlWindow);
    SDL_Quit();
}