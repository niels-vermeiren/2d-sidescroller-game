//
// Created by niels on 6/1/21.
//

#include "BlobEnemy.h"
#include "../sprite/BlobEnemySprite.h"

BlobEnemy::BlobEnemy(Vector direction, SDL_Rect *rect) : FallingEntity(direction, rect) {
    this->sprite = new BlobEnemySprite();
    isFacingLeft = false;

}

void BlobEnemy::draw(Renderer renderer) {
    this->sprite->draw(renderer, this->rect, NULL, isFacingLeft? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

AnimatedSprite * BlobEnemy::getSprite() {
    return sprite;
}

void BlobEnemy::setFacingLeft(bool facingLeft) {
    this->isFacingLeft = facingLeft;
}

void BlobEnemy::reset() {
    this->sprite->resetAnimation();
}

void BlobEnemy::update() {
    //this->state->update(this);
    this->applyGravity();
    this->rect->x += (int) direction.x;
    this->rect->y += (int) direction.y;
}

BlobEnemy::~BlobEnemy() {
    delete sprite;
}
