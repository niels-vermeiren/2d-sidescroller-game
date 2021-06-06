//
// Created by niels on 06.06.21.
//

#include "MageCollisionHandler.h"

void MageCollisionHandler::handleCollisions(Mage *mage, const EntityManager *entities) {
    for(Entity * entity : entities->getEntities()) {
        handleCollision(mage, entity);
    }
}
