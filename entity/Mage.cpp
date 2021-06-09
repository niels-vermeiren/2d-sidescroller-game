//
// Created by niels on 06.06.21.
//

#include <iostream>
#include "Mage.h"
#include "collisionbox/MageStaffCollisionBox.h"
#include "../defs.h"
#include "../magestate/MageMoveLeftState.h"


Mage::Mage(Vector direction, SDL_Rect *rect) : FallingEntity(direction, rect) {
    this->direction = direction;
    this->sprite = new MageSprite();
    this->collisionBox = new SkeletonCollisionBox();
    this->staffCollisionBox = new MageStaffCollisionBox();
    this->particlePool = new ParticlePool();
}

void Mage::draw(Renderer renderer) {
    for (Entity * entity : particlePool->getParticles()) entity->draw(renderer);
    if(this->shouldDraw)this->sprite->draw(renderer, this->rect, nullptr, isFacingLeft? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

void Mage::update() {
    this->applyGravity();
    this->state->update(this);
    for (Entity * entity : particlePool->getParticles()) entity->update();
    this->rect->x += (int) direction.x;
    this->rect->y += (int) direction.y;
}

AnimatedSprite *Mage::getSprite() {
    return sprite;
}

void Mage::setState(MageState *state) {
    this->state = state;
}

MageState *Mage::getState() const {
    return this->state;
}

bool Mage::isShouldAttack() const {
    return canAttack;
}

void Mage::setShouldAttack(bool shouldAttack) {
    this->canAttack = shouldAttack;
}

void Mage::setFacingLeft(bool facingLeft) {
    this->isFacingLeft = facingLeft;
}

void Mage::addBullet(MageBullet *bullet) {
    particlePool->addParticle(bullet);
}

ParticlePool *Mage::getBulletPool() {
    return particlePool;
}

SDL_Rect *Mage::getCollisionBox() {
    return collisionBox->getCollisionBox(this->rect);
}

SDL_Rect *Mage::getStaffCollisionBox() const {
    return staffCollisionBox->getCollisionBox(rect, isFacingLeft);
}


void Mage::reset() {
    Entity::reset();
    this->state = new MageMoveLeftState();
    this->sprite->resetAnimation();
}

void Mage::updatePlayerPos(int playerX, int playerY) {
    this->Entity::updatePlayerPos(playerX, playerY);
    this->particlePool->clear();
 }

Mage::~Mage() {
    delete sprite;
}
