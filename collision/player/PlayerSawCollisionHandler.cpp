//
// Created by niels on 5/23/21.
//

#include "PlayerSawCollisionHandler.h"

void PlayerSawCollisionHandler::handleCollision(Player *p, Entity *entity) {
    if(CollisionDetection::rectangleCircleIntersect(p->getCollisionBox(), entity->getRect())) {
        p->setState(new IsHurtState());

        int pCenterX = p->minX() + p->getCollisionBox()->w/2;
        int pCenterY = p->minY() + p->getCollisionBox()->h/2;
        Vector pCenter(pCenterX, pCenterY);

        int entityCenterX = entity->minX() + entity->getRect()->w/2;
        int entityCenterY = entity->minY() + entity->getRect()->h/2;
        Vector circleCenter(entityCenterX, entityCenterY);

        Vector outwardForce = circleCenter - pCenter;

        outwardForce.x = -outwardForce.x / SAW_FLYAWAY_X_FACTOR;
        outwardForce.y = -outwardForce.y / SAW_FLYAWAY_Y_FACTOR;

        p->getDirection() = p->getDirection() + outwardForce;
    }
}
