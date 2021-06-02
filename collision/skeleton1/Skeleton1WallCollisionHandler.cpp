//
// Created by niels on 6/1/21.
//

#include "Skeleton1WallCollisionHandler.h"

void Skeleton1WallCollisionHandler::handleCollision(Skeleton1 * skeleton, Entity *entity) {
//If player is located on top of wall and is falling in it
    if(skeleton->maxX() > entity->minX() && skeleton->minX()  < entity->maxX()
       && skeleton->maxY() -1<= entity->minY()
       && skeleton->maxY() + skeleton->getDirection().y > entity->minY()) {
        skeleton->getRect()->y = entity->minY() - skeleton->getRect()->h;
        skeleton->getDirection().y = 0;
    }
}
