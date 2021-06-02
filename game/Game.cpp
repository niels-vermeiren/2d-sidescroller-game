//
// Created by niels on 4/17/21.
//

#include "Game.h"
#include "../map/tilemap/SawMapParser.h"
#include "../collision/player/PlayerCoinCollisionHandler.h"
#include "../map/tilemap/CoinMapParser.h"
#include "../animation/Skeleton1Animation.h"
#include "../collision/player/PlayerSkeletonCollisionHandler.h"
#include "../collision/skeleton1/Skeleton1WallCollisionHandler.h"
#include "../skeletonstate/AttackingState.h"

Game::Game(Renderer * renderer) {
    SDL_Rect rect = {10, 400, 44, 127};
    Vector direction = {0, 0};
    this->player = new Player(direction, &rect);
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
    skeletonWallCollisionHandler = new Skeleton1WallCollisionHandler();
    playerSkeletonAttackCollisionHandler = new PlayerSkeletonCollisionHandler();

    SDL_Rect * skeletonRect = new SDL_Rect {10, 10, 155, 149};
    Vector skeletonDirection (0, 0);
    skeleton1 = new Skeleton1(skeletonDirection, skeletonRect);
    skeleton1->setState(new AttackingState());
}

void Game::update() {
    this->player->update();
    this->spikes->update();
    this->saws->update();
    this->skeleton1->update();
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
    this->skeleton1->draw(renderer);
    this->player->draw(renderer);
}

void Game::reset() {
    this->player->reset();
    this->coins->reset();
    this->skeleton1->reset();
}

void Game::handleCollisions() {
    playerSawCollisionHandler->handleCollisions(player, saws);
    playerSpikeCollisionHandler->handleCollisions(player, spikes);
    playerWallCollisionHandler->handleCollisions(player, tileMap);
    playerCoinCollisionHandler->handleCollisions(player, coins);
    skeletonWallCollisionHandler->handleCollisions(skeleton1, tileMap);
    playerSkeletonAttackCollisionHandler->handleCollision(player, skeleton1);
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

