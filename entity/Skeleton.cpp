//
// Created by niels on 6/1/21.
//

#include "Skeleton.h"
#include "../sprite/SkeletonSprite.h"
#include "../skeletonstate/MoveLeftState.h"
#include "../defs.h"

Skeleton::Skeleton(Vector direction, SDL_Rect *rect) : FallingEntity(direction, rect) {
    this->sprite = new SkeletonSprite();
    this->state = new MoveLeftState();
    facingLeft = false;
}

void Skeleton::draw(Renderer renderer) {
    if(this->shouldDraw)
        this->sprite->draw(renderer, this->rect, NULL, facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
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

SkeletonState *Skeleton::getState() const {
    return this->state;
}

void Skeleton::setState(SkeletonState *state) {
    this->state = state;
}

SDL_Rect *Skeleton::getCollisionBox() {
    return collisionBox.getCollisionBox(this->rect);
}

SDL_Rect *Skeleton::getAxeCollisionBox() {
   return axeCollisionBox.getCollisionBox(this->rect, facingLeft);
}

void Skeleton::reset() {
    Entity::reset();
    this->state = new MoveLeftState();
    this->sprite->resetAnimation();
}

Skeleton::~Skeleton() {
    delete sprite;
}
