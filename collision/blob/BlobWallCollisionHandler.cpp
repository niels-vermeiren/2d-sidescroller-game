//
// Created by niels on 6/1/21.
//

#include "BlobWallCollisionHandler.h"

void BlobWallCollisionHandler::handleCollision(BlobEnemy *blob, Entity *entity) {
//If player is located on top of wall and is falling in it
    if(blob->maxX() > entity->minX() && blob->minX()  < entity->maxX()
       && blob->maxY() -1<= entity->minY()
       && blob->maxY() + blob->getDirection().y > entity->minY()) {
        blob->getRect()->y = entity->minY() - blob->getRect()->h;
       /* if (blob->getDirection().y > GRAVITY && blob->getState()->getState() != HURTING
            && blob->getState()->getState() != DYING) blob->setState(new OnGroundState());*/
        blob->getDirection().y = 0;
    }
}
