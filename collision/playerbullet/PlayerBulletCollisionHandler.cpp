//
// Created by niels on 10.06.21.
//

#include "PlayerBulletCollisionHandler.h"


void PlayerBulletCollisionHandler::handleCollisions(Skeleton *skeleton, const EntityManager *entities) {
    for(Entity * entity : entities->getEntities()) handleCollision(skeleton, dynamic_cast<PlayerBullet *>(entity));
}

void PlayerBulletCollisionHandler::handleCollisions(Mage *mage, const EntityManager *entities) {
    for(Entity * entity : entities->getEntities()) handleCollision(mage, dynamic_cast<PlayerBullet *>(entity));
}
