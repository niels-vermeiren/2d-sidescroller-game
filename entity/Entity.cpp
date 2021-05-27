//
// Created by niels on 4/10/21.
//

#include "Entity.h"

Entity::Entity() {

}

Entity::Entity(Vector direction, SDL_Rect * rect) {
    this->direction = direction;
    this->rect = rect;
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
}
