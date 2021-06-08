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
    isFacingLeft = false;
}

void Skeleton::draw(Renderer renderer) {
    if(this->shouldDraw)this->sprite->draw(renderer, this->rect, NULL, isFacingLeft? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
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
    Entity::reset();
    this->state = new MoveLeftState();
    this->sprite->resetAnimation();
}

void Skeleton::setState(SkeletonState *state) {
    this->state = state;
}

SkeletonState *Skeleton::getState() const {
    return this->state;
}

SDL_Rect *Skeleton::getCollisionBox() {
   return collisionBox.getCollisionBox(this->rect);
}

Skeleton::~Skeleton() {
    delete sprite;
}

bool Skeleton::facingLeft() const {
    return this->isFacingLeft;
}

SDL_Rect *Skeleton::getAxeCollisionBox() {
    axeCollisionBox.getCollisionBox(this->rect, isFacingLeft);
}

void Skeleton::updatePlayerPos(int playerX, int playerY) {
    this->shouldDraw= (this->minX() > playerX - SCREEN_WIDTH/2 - this->rect->w && minX()  < playerX + SCREEN_WIDTH/2 + this->rect->w
                       || playerX < SCREEN_WIDTH/2 && minX() < playerX + SCREEN_WIDTH) &&
                      (this->minY() > playerY - SCREEN_HEIGHT/2 - this->rect->h && minY()  < playerY + SCREEN_HEIGHT/2 + this->rect->h
                       || playerY > LEVEL_HEIGHT - SCREEN_WIDTH/2 && minY() > playerY -  SCREEN_HEIGHT);
}
