//
// Created by niels on 5/27/21.
//

#include "PlayerCoinCollisionHandler.h"
#include "CollisionDetection.h"

void PlayerCoinCollisionHandler::handleCollision(Player *p, Entity *entity) {
    if(CollisionDetection::rectangleCircleIntersect(p->getRect(), entity->getRect())) {
        entity->setVisible(false);
    }

}
