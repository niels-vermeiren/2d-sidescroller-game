//
// Created by niels on 06.06.21.
//

#include "MageWallCollisionHandler.h"
#include "../../magestate/MageMoveLeftState.h"
#include "../../magestate/MageMoveRightState.h"

void MageWallCollisionHandler::handleCollision(Mage *mage, Entity *entity) {
    SDL_Rect * boundingBox = mage->getRect();
    SDL_Rect * collisionBox = mage->getCollisionBox();
    Vector * direction = &mage->getDirection();

    //Mage falls down on wall
    if(collisionBox->x + collisionBox->w > entity->minX() && collisionBox->x < entity->maxX() && mage->maxY() - 2 <= entity->minY() && mage->maxY() + direction->y > entity->minY()) {
        boundingBox->y = entity->minY() - boundingBox->h +1;
        direction->y = 0;
    }

    bool mageOnSameHeight = mage->minY() < entity->maxY() && mage->maxY() > entity->minY();

    //Mage collides with wall on the right
    if(mageOnSameHeight && collisionBox->x + collisionBox->w - direction->x <= entity->minX() && collisionBox->x + collisionBox->w > entity->minX()) {
        boundingBox->x = entity->minX() - collisionBox->w * 2;
        if(mage->getState()->getState() != DOOD) mage->setState(new MageMoveLeftState());
    }

    //Mage collides with wall on the left
    if(mageOnSameHeight && collisionBox->x + direction->x <= entity->maxX() && collisionBox->x + collisionBox->w  > entity->maxX()) {
        boundingBox->x = entity->maxX();
        if(mage->getState()->getState() != DOOD) mage->setState(new MageMoveRightState());
    }
}
