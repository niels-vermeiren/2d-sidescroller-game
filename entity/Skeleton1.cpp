//
// Created by niels on 6/1/21.
//

#include "Skeleton1.h"
#include "../sprite/Skeleton1Sprite.h"
#include "../skeletonstate/WalkingState.h"
#include "../skeletonstate/IdleState.h"

Skeleton1::Skeleton1(Vector direction, SDL_Rect *rect) : FallingEntity(direction, rect) {
    this->sprite = new Skeleton1Sprite();
    isFacingLeft = false;
    this->state = new IdleState();
}

void Skeleton1::draw(Renderer renderer) {
    this->sprite->draw(renderer, this->rect, NULL, isFacingLeft? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

AnimatedSprite * Skeleton1::getSprite() {
    return sprite;
}

void Skeleton1::setFacingLeft(bool facingLeft) {
    this->isFacingLeft = facingLeft;
}

void Skeleton1::reset() {
    this->state = new IdleState();
    this->sprite->resetAnimation();
}

void Skeleton1::update() {
    this->state->update(this);
    this->applyGravity();
    this->rect->x += (int) direction.x;
    this->rect->y += (int) direction.y;
}

Skeleton1::~Skeleton1() {
    delete sprite;
}

void Skeleton1::setState(SkeletonState *state) {
    this->state = state;
}

SkeletonState *Skeleton1::getState() const {
    return this->state;
}

SDL_Rect *Skeleton1::getBoundingRect() {
    return new SDL_Rect {rect->x+25, rect->y+41, 47, 106};
}
