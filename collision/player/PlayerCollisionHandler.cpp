//
// Created by niels on 5/23/21.
//

#include "PlayerCollisionHandler.h"

void PlayerCollisionHandler::handleCollisions(Player *p, const EntityManager *entities) {
    for (Entity * entity : entities->getEntities()) {
        handleCollision(p, entity);
    }
}

