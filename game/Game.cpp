//
// Created by niels on 4/17/21.
//

#include "Game.h"
#include "../map/tilemap/SawMapParser.h"

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
    auto * sawMap = new SawMapParser();
    saws = sawMap->mapToEntities();
    playerWallCollisionHandler = new PlayerWallCollisionHandler();
    playerSawCollisionHandler = new PlayerSawCollisionHandler();
    playerSpikeCollisionHandler = new PlayerSpikeCollisionHandler();
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
    this->player->draw(renderer);
}

void Game::reset() {
    this->player->reset();
}

void Game::handleCollisions() {
    playerWallCollisionHandler->handleCollisions(player, tileMap);
    playerSawCollisionHandler->handleCollisions(player, saws);
    playerSpikeCollisionHandler->handleCollisions(player, spikes);
}

Game::~Game() {
    delete background;
    delete player;
    delete tileMap;
    delete playerWallCollisionHandler;
    delete playerSawCollisionHandler;
    delete playerSpikeCollisionHandler;
}

