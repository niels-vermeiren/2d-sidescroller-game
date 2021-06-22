//
// Created by niels on 22.06.21.
//

#include "PortalCollisionHandler.h"

void PortalCollisionHandler::handleCollisions(Player *player, const EntityManager *entities) {
    for(auto * entity : entities->getEntities()) {
        handleCollision(player, entity);
    }
}
