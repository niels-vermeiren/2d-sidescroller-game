//
// Created by niels on 4/10/21.
//

#include "Entity.h"

Entity::Entity() {
    initialPosition = new SDL_Rect {0,0,0,0};
}

Entity::Entity(Vector direction, SDL_Rect * rect) {
    this->direction = direction;
    this->rect = rect;
    this->initialPosition = new SDL_Rect {rect->x, rect->y, rect->w, rect->h};;
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

void Entity::setVisible(const bool visible) {
    this->visible = visible;
}

void Entity::reset() {
    this->visible = true;
    this->rect = new SDL_Rect {initialPosition->x, initialPosition->y, initialPosition->w, initialPosition->h};
    this->x = this->rect->x;
    this->y = this->rect->y;
    this->direction = {0,0};
}

bool Entity::isShouldDraw() const {
    return shouldDraw;
}

void Entity::setShouldDraw(bool shouldDraw) {
    Entity::shouldDraw = shouldDraw;
}

void Entity::clone(Vector direction, SDL_Rect *rect) {
    this->direction = direction;
    this->rect = rect;
    this->setShouldDraw(true);
    this->visible = true;
    this->x = rect->x;
    this->y = rect->y;
}
