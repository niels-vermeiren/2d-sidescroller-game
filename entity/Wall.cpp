//
// Created by niels on 4/27/21.
//

#include "Wall.h"

Wall::Wall() {
    this->rect = new SDL_Rect();
}

Wall::Wall(int x, int y, int w, int h) {
    this->rect = new SDL_Rect();
    this->rect->x = x;
    this->rect->y = y;
    this->rect->w = w;
    this->rect->h = h;
}

void Wall::update() {

}

void Wall::draw(Renderer renderer) {
    for(Entity * platform : platforms) {
        platform->draw(renderer);
    }
}

void Wall::addPlatform(Entity *platform) {
    this->platforms.push_back(platform);
}

void Wall::setPlatforms(std::vector<Entity *> platforms) {
    this->platforms = platforms;
}

void Wall::updatePlayerPos(int playerX, int playerY) {
    for(EntityObserver * platform : platforms) {
        platform->updatePlayerPos(playerX, playerY);
    }
}

Wall::~Wall() {
    for(Entity * entity : platforms) delete entity;
}
