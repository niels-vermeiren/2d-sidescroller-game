//
// Created by niels on 6/1/21.
//

#include "Skeleton.h"
#include "../sprite/SkeletonSprite.h"
#include "../skeletonstate/MoveLeftState.h"

Skeleton::Skeleton(Vector direction, SDL_Rect *rect) : FallingEntity(direction, rect) {
    this->sprite = new SkeletonSprite();
    isFacingLeft = false;
    this->state = new MoveLeftState();
}

void Skeleton::draw(Renderer renderer) {
    this->sprite->draw(renderer, this->rect, NULL, isFacingLeft? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

void Skeleton::update() {
    this->state->update(this);
    this->applyGravity();
    this->rect->x += (int) direction.x;
    this->rect->y += (int) direction.y;
}

AnimatedSprite * Skeleton::getSprite() {
    return sprite;
}

void Skeleton::setFacingLeft(bool facingLeft) {
    this->isFacingLeft = facingLeft;
}

void Skeleton::reset() {
    this->state = new MoveLeftState();
    this->sprite->resetAnimation();
}

void Skeleton::setState(SkeletonState *state) {
    this->state = state;
}

SkeletonState *Skeleton::getState() const {
    return this->state;
}

SDL_Rect *Skeleton::getBoundingRect() {
    if(!this->facingLeft()) return new SDL_Rect {rect->x+40, rect->y+41, 47, 106};
    else return new SDL_Rect {rect->x+70, rect->y+41, 47, 106};
}

Skeleton::~Skeleton() {
    delete sprite;
}

bool Skeleton::facingLeft() const {
    return this->isFacingLeft;
}

SDL_Rect *Skeleton::getReverseBoundingRect() {
    if(this->facingLeft()) return new SDL_Rect {rect->x+40, rect->y+41, 47, 106};
    else return new SDL_Rect {rect->x+70, rect->y+41, 47, 106};
}
