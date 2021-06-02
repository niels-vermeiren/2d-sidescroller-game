//
// Created by niels on 6/1/21.
//

#include "Skeleton1CollisionHandler.h"

void Skeleton1CollisionHandler::handleCollisions(Skeleton1 *blob, const EntityManager *entities) {
    for(Entity * entity : entities->getEntities()) {
        handleCollision(blob, entity);
    }
}
