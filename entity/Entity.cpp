//
// Created by niels on 4/10/21.
//

#include "Entity.h"
#include "../defs.h"

Entity::Entity() {
    initialPosition = new SDL_Rect {0,0,0,0};
}

Entity::Entity(Vector direction, SDL_Rect * rect) {
    this->initialPosition = new SDL_Rect {rect->x, rect->y, rect->w, rect->h};;
    this->direction = direction;
    this->rect = rect;
    this->x = rect->x;
    this->y = rect->y;
}

Vector &Entity::getDirection() {
    return this->direction;
}

SDL_Rect * Entity::getRect() {
    return this->rect;
}

int Entity::maxX() const {
    return this->rect->x + this->rect->w;
}

int Entity::maxY() const {
    return this->rect->y + this->rect->h;
}

int Entity::minX() const {
    return this->rect->x;
}

int Entity::minY() const {
    return this->rect->y;
}

void Entity::isVisible(const bool isVisible) {
    this->visible = isVisible;
}

void Entity::reset() {
    this->visible = true;
    this->rect = new SDL_Rect {initialPosition->x, initialPosition->y, initialPosition->w, initialPosition->h};
    this->x = this->rect->x;
    this->y = this->rect->y;
    this->direction = {0,0};
}

bool Entity::shouldBeDrawn() const {
    return shouldDraw;
}

void Entity::clone(Vector direction, SDL_Rect *rect) {
    this->direction = direction;
    this->rect = rect;
    this->visible = true;
    this->x = rect->x;
    this->y = rect->y;
}

void Entity::updatePlayerPos(int playerX, int playerY) {
    this->shouldDraw= (this->minX() > playerX - SCREEN_WIDTH/2 - this->rect->w && minX()  < playerX + SCREEN_WIDTH/2 + this->rect->w
                       || playerX < SCREEN_WIDTH/2 && minX() < playerX + SCREEN_WIDTH) &&
                      (this->minY() > playerY - SCREEN_HEIGHT/2 - this->rect->h && minY()  < playerY + SCREEN_HEIGHT/2 + this->rect->h
                       || playerY > LEVEL_HEIGHT - SCREEN_WIDTH/2 && minY() > playerY -  SCREEN_HEIGHT);}

void Entity::update() {}
