//
// Created by niels on 06.06.21.
//

#include <iostream>
#include "Mage.h"
#include "collisionbox/MageStaffCollisionBox.h"
#include "../defs.h"


Mage::Mage(Vector direction, SDL_Rect *rect) : FallingEntity(direction, rect) {
    this->direction = direction;
    this->rect = rect;
    this->sprite = new MageSprite();
    this->collisionBox = new SkeletonCollisionBox();
    this->staffCollisionBox = new MageStaffCollisionBox();
}

void Mage::draw(Renderer renderer) {
    if(this->shouldDraw)this->sprite->draw(renderer, this->rect, nullptr, isFacingLeft? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
    for (Entity * entity : bullets) entity->draw(renderer);
}

void Mage::update() {
    this->applyGravity();
    this->state->update(this);
    for (Entity * entity : bullets) entity->update();
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

SDL_Rect *Mage::getStaffCollisionBox() const {
    return staffCollisionBox->getCollisionBox(rect, isFacingLeft);
}

void Mage::addBullet(MageBullet *bullet) {

    bullets.push_back(bullet);
}

bool Mage::isShouldAttack() const {
    return shouldAttack;
}

void Mage::setShouldAttack(bool shouldAttack) {
   this->shouldAttack = shouldAttack;
}

void Mage::updatePlayerPos(int playerX, int playerY) {
    this->shouldDraw= (this->minX() > playerX - SCREEN_WIDTH/2 - this->rect->w && minX()  < playerX + SCREEN_WIDTH/2 + this->rect->w
                       || playerX < SCREEN_WIDTH/2 && minX() < playerX + SCREEN_WIDTH) &&
                      (this->minY() > playerY - SCREEN_HEIGHT/2 - this->rect->h && minY()  < playerY + SCREEN_HEIGHT/2 + this->rect->h
                       || playerY > LEVEL_HEIGHT - SCREEN_WIDTH/2 && minY() > playerY -  SCREEN_HEIGHT);
 }
