//
// Created by niels on 06.06.21.
//

#include "Mage.h"


Mage::Mage(Vector direction, SDL_Rect *rect) : FallingEntity(direction, rect) {
    this->direction = direction;
    this->rect = rect;
    this->sprite = new MageSprite();
    this->collisionBox = new SkeletonCollisionBox();
}

void Mage::draw(Renderer renderer) {
    this->sprite->draw(renderer, this->rect, nullptr, isFacingLeft? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

void Mage::update() {
    this->applyGravity();
    this->state->update(this);
    this->rect->x += (int) direction.x;
    this->rect->y += (int) direction.y;
}

AnimatedSprite *Mage::getSprite() {
    return sprite;
}

void Mage::setFacingLeft(bool facingLeft) {
    this->isFacingLeft = facingLeft;
}

bool Mage::facingLeft() const {
    return isFacingLeft;
}

void Mage::reset() {
    this->sprite->resetAnimation();
}

Mage::~Mage() {
    delete sprite;
}

void Mage::setState(MageState *state) {
    this->state = state;
}

MageState *Mage::getState() const {
    return this->state;
}

SDL_Rect *Mage::getCollisionBox() {
    return collisionBox->getCollisionBox(this->rect);
}
