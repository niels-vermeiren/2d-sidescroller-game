//
// Created by niels on 6/1/21.
//

#include "BlobCollisionHandler.h"

void BlobCollisionHandler::handleCollisions(BlobEnemy *blob, const EntityManager *entities) {
    for(Entity * entity : entities->getEntities()) {
        handleCollision(blob, entity);
    }
}
