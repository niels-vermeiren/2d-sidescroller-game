//
// Created by niels on 4/17/21.
//

#include <iostream>
#include "Game.h"
#include "../map/tilemap/SawMapParser.h"
#include "../collision/PlayerCoinCollisionHandler.h"
#include "../map/tilemap/CoinMapParser.h"

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

    auto * r1 = new Rotated_Rect({1,6}, {3,8}, {5,6}, {3,4});
    auto * r2 = new Rotated_Rect({5,5}, {8,5}, {8,2}, {5,2});
    bool collides = CollisionDetection::rotatedRectanglesIntersect(r1, r2);
    std::cout << collides <<std::endl;
}

void Game::update() {
    this->player->update();
    this->spikes->update();
    this->saws->update();
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
    this->player->draw(renderer);
}

void Game::reset() {
    this->player->reset();
    this->coins->reset();
}

void Game::handleCollisions() {
    playerSawCollisionHandler->handleCollisions(player, saws);
    playerSpikeCollisionHandler->handleCollisions(player, spikes);
    playerWallCollisionHandler->handleCollisions(player, tileMap);
    playerCoinCollisionHandler->handleCollisions(player, coins);
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

