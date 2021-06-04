//
// Created by niels on 6/1/21.
//

#include "SkeletonCollisionHandler.h"

void SkeletonCollisionHandler::handleCollisions(Skeleton *skeleton, const EntityManager *entities) {
    for(Entity * entity : entities->getEntities()) {
        handleCollision(skeleton, entity);
    }
}
