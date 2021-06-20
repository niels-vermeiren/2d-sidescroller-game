//
// Created by niels on 4/27/21.
//

#include "Wall.h"

#include <utility>

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

void Wall::draw(Renderer renderer) {
    if(!shouldDraw) return;
    for(Entity * platform : platforms) {
        platform->draw(renderer);
    }
}

void Wall::setPlatforms(std::vector<Entity *> tiles) {
    this->platforms = std::move(tiles);
}

Wall::~Wall() {
    for(Entity * entity : platforms) delete entity;
}

const std::vector<Entity *> &Wall::getPlatforms() const {
    return platforms;
}
