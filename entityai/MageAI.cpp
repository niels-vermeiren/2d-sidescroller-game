//
// Created by niels on 06.06.21.
//

#include <iostream>
#include "MageAI.h"
#include "../magestate/MageMoveLeftState.h"
#include "../magestate/MageMoveRightState.h"

MageAI::MageAI(Mage *mage, EntityManager *walls) {
    playerX = 0, playerY = 0;
    this->mage = mage;
    //Get wall under mage
    for(Entity * entity : walls->getEntities()) {
        bool wallIsUnderEnemy = entity->minY() >= mage->maxY() && entity->minX() < mage->maxX() && entity->maxX() > mage->minX();

        if(wallIsUnderEnemy) {
            this->wall = entity;
            break;
        }
    }
    attackState = new MageAttackState();
    mage->setState(new MageMoveRightState());
    mage->setFacingLeft(false);
}

void MageAI::updatePlayerPos(int playerX, int playerY) {
    this->playerX = playerX;
    this->playerY = playerY;
}

void MageAI::update() {
    if (mage->getState()->getState() == DOOD) return;
    changeDirectionWhenOnEdgeWall();
    facePlayerAndAttack();
    shoot();
}

void MageAI::changeDirectionWhenOnEdgeWall() {
    if (mage->getState()->getState() == STAFF_ATTACK) return;
    if (mage->getState()->getState() == STILL) return;
    //Don't fall off of platform, turn around
    if(mage->getCollisionBox()->x + mage->getCollisionBox()->w + mage->getDirection().x > wall->maxX() ) {
        mage->setState(new MageMoveLeftState());
    }
    if(mage->getCollisionBox()->x - mage->getDirection().x < wall->minX()) {
        mage->setState(new MageMoveRightState());
    }
}

void MageAI::facePlayerAndAttack() {
    bool shouldWalkLeft = playerX < mage->getCollisionBox()->x + mage->getCollisionBox()->w/2;
    Vector v = Vector(playerX, playerY) - Vector(mage->getStaffCollisionBox()->x + mage->getStaffCollisionBox()->w/2,
                                                 mage->getStaffCollisionBox()->y + mage->getStaffCollisionBox()->h/2);
    float  length = v.length();
    if (mage->shouldBeDrawn() && length < MAGE_ATTACK_RANGE) {
        if (!mage->getState()->getState() != STAFF_ATTACK) mage->setState(attackState);
        mage->setFacingLeft(playerX < mage->getCollisionBox()->x + mage->getCollisionBox()->w/2);
    } else {
        if(mage->getState()->getState() != RIGHT && mage->getState()->getState() != LEFT) {
            if(shouldWalkLeft) mage->setState(new MageMoveLeftState());
            else mage->setState(new MageMoveRightState());
        }
    }
}

void MageAI::shoot() {
    if(!mage->isShouldAttack() || !mage->shouldBeDrawn()) return;

    Vector magePosVector = Vector(mage->getStaffCollisionBox()->x-4, mage->getStaffCollisionBox()->y-4);
    Vector playerPosVector = Vector(playerX, playerY);
    Vector bulletVector =  playerPosVector - magePosVector;
    bulletVector.normalize();
    bulletVector.x *= MAGE_BULLET_SPEED;
    bulletVector.y *= MAGE_BULLET_SPEED;
    auto * bulletRect = new SDL_Rect {mage->getStaffCollisionBox()->x-9, mage->getStaffCollisionBox()->y-32, 40, 40};
    auto * bullet = new MageBullet(bulletRect, bulletVector);
    mage->addBullet(bullet);
    mage->setShouldAttack(false);
}
