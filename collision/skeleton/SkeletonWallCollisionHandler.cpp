//
// Created by niels on 6/1/21.
//

#include "SkeletonWallCollisionHandler.h"
#include "../../skeletonstate/MoveLeftState.h"
#include "../../skeletonstate/MoveRightState.h"

void SkeletonWallCollisionHandler::handleCollision(Skeleton * skeleton, Entity *entity) {
//If player is located on top of wall and is falling in it
    if(skeleton->maxX() > entity->minX() && skeleton->minX()  < entity->maxX()
       && skeleton->maxY() -1<= entity->minY()
       && skeleton->maxY() + skeleton->getDirection().y > entity->minY()) {
        skeleton->getRect()->y = entity->minY() - skeleton->getRect()->h;
        skeleton->getDirection().y = 0;
    }

    //If p is located on the left of the entity, and moving against it
    if(skeleton->minY() < entity->maxY() && skeleton->maxY() > entity->minY() &&
       skeleton->getReverseBoundingRect()->x + skeleton->getReverseBoundingRect()->w  - skeleton->getDirection().x <= entity->minX() && skeleton->getReverseBoundingRect()->x + skeleton->getReverseBoundingRect()->w  > entity->minX()) {
        skeleton->getRect()->x = entity->minX() - skeleton->getReverseBoundingRect()->w * 2;
        if(skeleton->getState()->getState() != DEAD) skeleton->setState(new MoveLeftState());
    }
    //If skeleton is located on the right of the entity, and moving against it
    if(skeleton->minY() < entity->maxY() && skeleton->maxY() > entity->minY() &&
       skeleton->getReverseBoundingRect()->x + skeleton->getDirection().x <= entity->maxX() && skeleton->getReverseBoundingRect()->x + 50 > entity->maxX()) {
        skeleton->getRect()->x = entity->maxX();
        if(skeleton->getState()->getState() != DEAD) skeleton->setState(new MoveRightState());
    }

}
