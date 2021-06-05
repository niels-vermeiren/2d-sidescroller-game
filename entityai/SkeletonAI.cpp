//
// Created by niels on 6/2/21.
//

#include "SkeletonAI.h"

SkeletonAI::SkeletonAI(Skeleton *skeleton, EntityManager *walls) {
    playerX = 0, playerY = 0;
    this->skeleton = skeleton;
    //Get wall under skeleton
    for(Entity * entity : walls->getEntities()) {
        bool wallIsUnderEnemy = entity->minY() >= skeleton->maxY() && entity->minX() < skeleton->maxX() && entity->maxX() > skeleton->minX();

        if(wallIsUnderEnemy) {
            this->wall = entity;
            break;
        }
    }
    skeleton->setState(new MoveLeftState());
}

void SkeletonAI::update() {
    if(skeleton->getState()->getState() == DEAD) return;
    changeDirectionWhenOnEdgeWall();
    attackClosePlayer();
    walkOnWhenPlayerIsOutOfRange();
}

void SkeletonAI::updatePlayerPos(int x, int y) {
    this->playerX = x;
    this->playerY = y;
}

void SkeletonAI::attackClosePlayer() {
    tick++;
    if(tick % SKELETON_TIME_BETWEEN_ATTACKS == 0) hasAttacked = false;

    //If player is not on same height as enemy, skeleton is not attacking or skeleton has already attacked, do nothing
    if(skeleton->getBoundingRect()->y > playerY && skeleton->getBoundingRect()->y + skeleton->getBoundingRect()->h < playerY
    || (skeleton->getState()->getState() == ATTACK || hasAttacked)) return;

    bool playerCloseOnLeft = playerX > skeleton->getBoundingRect()->x + skeleton->getBoundingRect()->w - SKELETON_ATTACK_MIN_PLAYER_DISTANCE
            && playerX <skeleton->getBoundingRect()->x;

    bool playerCloseOnRight = playerX < skeleton->getBoundingRect()->x + SKELETON_ATTACK_MIN_PLAYER_DISTANCE &&  playerX > skeleton->getBoundingRect()->x;

    if (playerCloseOnLeft || playerCloseOnRight){
        skeleton->setFacingLeft(playerCloseOnLeft);
        skeleton->getSprite()->resetAnimation();
        skeleton->setState(new AttackingState());
        tick = 0;
        hasAttacked = true;
    }
}

void SkeletonAI::walkOnWhenPlayerIsOutOfRange() {
    if ((playerX < skeleton->getBoundingRect()->x - SKELETON_ATTACK_MIN_PLAYER_DISTANCE && playerX < skeleton->getBoundingRect()->x
         || playerX > skeleton->getBoundingRect()->x + SKELETON_ATTACK_MIN_PLAYER_DISTANCE && playerX > skeleton->getBoundingRect()->x
         || skeleton->getBoundingRect()->y > playerY && skeleton->getBoundingRect()->y + skeleton->getBoundingRect()->h < playerY)
        && (skeleton->getState()->getState() == IDLE || skeleton->getState()->getState() == ATTACK)) {
        skeleton->setState(new MoveLeftState());
        hasAttacked = false;
    }
}

void SkeletonAI::changeDirectionWhenOnEdgeWall() {
    //Don't fall off of platform, turn around
    if(skeleton->getBoundingRect()->x + skeleton->getBoundingRect()->w + skeleton->getDirection().x > wall->maxX() ) {
        skeleton->setState(new MoveLeftState());
    }
    if(skeleton->getBoundingRect()->x - skeleton->getDirection().x < wall->minX()) {
        skeleton->setState(new MoveRightState());
    }
}
