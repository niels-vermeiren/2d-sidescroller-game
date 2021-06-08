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

void Mage::setFacingLeft(bool facingLeft) {
    this->isFacingLeft = facingLeft;
}

bool Mage::facingLeft() const {
    return isFacingLeft;
}

void Mage::reset() {
    Entity::reset();
    this->state = new MageMoveLeftState();
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
    particlePool->addParticle(bullet);
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



    for(Entity * particle : particlePool->getParticles()) {
        particle->setShouldDraw(!(particle->minY() < playerY - SCREEN_WIDTH && particle->maxY() > playerY + SCREEN_HEIGHT ||
        particle->maxX() < playerX - SCREEN_WIDTH || particle->minX() > playerX + SCREEN_WIDTH));
    }

    this->particlePool->clear();
 }

ParticlePool *Mage::getBulletPool() {
    return particlePool;
}
