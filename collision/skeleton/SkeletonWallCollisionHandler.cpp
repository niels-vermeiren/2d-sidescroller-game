//
// Created by niels on 6/1/21.
//

#include "SkeletonWallCollisionHandler.h"
#include "../../skeletonstate/MoveLeftState.h"
#include "../../skeletonstate/MoveRightState.h"

void SkeletonWallCollisionHandler::handleCollision(Skeleton * skeleton, Entity *entity) {
    SDL_Rect * boundingBox = skeleton->getRect();
    SDL_Rect * collisionBox = skeleton->getCollisionBox();
    Vector * direction = &skeleton->getDirection();

    //If player is located on top of wall and is falling in it
    if(collisionBox->x + collisionBox->w > entity->minX() && collisionBox->x < entity->maxX() && skeleton->maxY() -1<= entity->minY() && skeleton->maxY() + direction->y > entity->minY()) {
        boundingBox->y = entity->minY() - boundingBox->h;
        direction->y = 0;
    }

    bool skeletonOnSameHeight = skeleton->minY() < entity->maxY() && skeleton->maxY() > entity->minY();

    //If p is located on the left of the entity, and moving against it
    if(skeletonOnSameHeight && collisionBox->x + collisionBox->w - direction->x <= entity->minX() && collisionBox->x + collisionBox->w > entity->minX()) {
        boundingBox->x = entity->minX() - collisionBox->w * 2;
        if(skeleton->getState()->getState() != DEAD) skeleton->setState(new MoveLeftState());
    }
    //If skeleton is located on the right of the entity, and moving against it
    if(skeletonOnSameHeight && collisionBox->x + direction->x <= entity->maxX() && collisionBox->x + collisionBox->w  > entity->maxX()) {
        boundingBox->x = entity->maxX();
        if(skeleton->getState()->getState() != DEAD) skeleton->setState(new MoveRightState());
    }
}
