//
// Created by niels on 06.06.21.
//

#include "MageAI.h"
#include "../magestate/MageMoveLeftState.h"
#include "../magestate/MageMoveRightState.h"
#include "../magestate/MageAttackState.h"

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
    mage->setState(new MageAttackState());
    mage->setFacingLeft(false);
}

void MageAI::updatePlayerPos(int playerX, int playerY) {
    this->playerX = playerX;
    this->playerY = playerY;
}

void MageAI::update() {
    changeDirectionWhenOnEdgeWall();
}

void MageAI::changeDirectionWhenOnEdgeWall() {
    mage->setState(new MageAttackState());
    /*//Don't fall off of platform, turn around
    if(mage->getCollisionBox()->x + mage->getCollisionBox()->w + mage->getDirection().x > wall->maxX() ) {
        mage->setState(new MageMoveLeftState());
    }
    if(mage->getCollisionBox()->x - mage->getDirection().x < wall->minX()) {
        mage->setState(new MageMoveRightState());
    }*/
}
