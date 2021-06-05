//
// Created by niels on 4/17/21.
//

#include "Game.h"
#include "../map/tilemap/SawMapParser.h"
#include "../collision/player/PlayerCoinCollisionHandler.h"
#include "../map/tilemap/CoinMapParser.h"
#include "../animation/SkeletonAnimation.h"
#include "../collision/skeleton/SkeletonWallCollisionHandler.h"
#include "../entityai//SkeletonAI.h"

Game::Game(Renderer * renderer) {
    this->renderer = renderer;
}

void Game::update() {
    this->player->update();
    this->spikes->update();
    this->saws->update();
    this->skeleton->update();
    this->skeleton2->update();
    this->skeletonAI->update();
    this->skeletonAI2->update();
    if(InputManager::keyPressed(SDL_SCANCODE_R)) {
        reset();
    }
}

void Game::draw(Renderer renderer) {
    this->background->draw(renderer);
    this->spikes->draw(renderer);
    this->saws->draw(renderer);
    this->tileMap->draw(renderer);
    this->coins->draw(renderer);
    this->skeleton->draw(renderer);
    this->skeleton2->draw(renderer);
    this->player->draw(renderer);
}

void Game::reset() {
    this->player->reset();
    this->coins->reset();
    this->skeleton->reset();
    this->skeleton2->reset();
}

void Game::handleCollisions() {
    playerSawCollisionHandler->handleCollisions(player, saws);
    playerSpikeCollisionHandler->handleCollisions(player, spikes);
    playerWallCollisionHandler->handleCollisions(player, tileMap);
    playerCoinCollisionHandler->handleCollisions(player, coins);
    playerSkeletonAttackCollisionHandler->handleCollision(player, skeleton);
    playerSkeletonAttackCollisionHandler->handleCollision(player, skeleton2);
    skeletonWallCollisionHandler->handleCollisions(skeleton, tileMap);
    skeletonWallCollisionHandler->handleCollisions(skeleton2, tileMap);

}

Game::~Game() {
    delete background;
    delete player;
    delete tileMap;
    delete coins;
    delete playerWallCollisionHandler;
    delete playerSawCollisionHandler;
    delete playerSpikeCollisionHandler;
    delete playerCoinCollisionHandler;
}

void Game::load(Renderer *renderer) {
    SDL_Rect rect = {10, 400, 44, 127};
    this->player = new Player({0, 0}, &rect);
    auto * tilemapParser = new TileMapParser(new TilesetTextureHolder(renderer));
    this->tileMap = tilemapParser->mapToEntities();
    Observable * playerObservable = player;
    this->background = new Background();
    for(auto * obs:this->tileMap->getEntities()) {
        playerObservable->addObserver(obs);
    }
    playerObservable->addObserver(background);
    auto * spikesMap = new SpikeMapParser();
    spikes = spikesMap->mapToEntities();
    for(auto * obs:this->spikes->getEntities()) {
        playerObservable->addObserver(obs);
    }
    auto * sawMap = new SawMapParser();
    saws = sawMap->mapToEntities();
    for(auto * obs:this->saws->getEntities()) {
        playerObservable->addObserver(obs);
    }
    auto * coinMap = new CoinMapParser();
    coins = coinMap->mapToEntities();
    for(auto * obs:this->coins->getEntities()) {
        playerObservable->addObserver(obs);
    }
    playerWallCollisionHandler = new PlayerWallCollisionHandler();
    playerSawCollisionHandler = new PlayerSawCollisionHandler();
    playerSpikeCollisionHandler = new PlayerSpikeCollisionHandler();
    playerCoinCollisionHandler = new PlayerCoinCollisionHandler();
    skeletonWallCollisionHandler = new SkeletonWallCollisionHandler();
    SDL_Rect * skeletonRect = new SDL_Rect {2000, 10, 155, 149};
    Vector skeletonDirection (0, 0);
    skeleton = new Skeleton(skeletonDirection, skeletonRect);
    this->skeletonAI = new SkeletonAI(skeleton, tileMap);playerSkeletonAttackCollisionHandler = new PlayerSkeletonCollisionHandler();

    SDL_Rect * skeletonRect2 = new SDL_Rect {1000, 10, 155, 149};
    Vector skeletonDirection2 (0, 0);
    skeleton2 = new Skeleton(skeletonDirection2, skeletonRect2);
    this->skeletonAI2 = new SkeletonAI(skeleton2, tileMap);

    playerObservable->addObserver(skeletonAI2);
}

