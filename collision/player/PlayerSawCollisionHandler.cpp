//
// Created by niels on 5/23/21.
//

#include "PlayerSawCollisionHandler.h"
#include "../../stats/PlayerStats.h"

void PlayerSawCollisionHandler::handleCollision(Player *p, Entity *entity) {
    if(CollisionDetection::rectangleCircleIntersect(p->getCollisionBox(), entity->getRect())) {
        bool hurting = p->getState()->getState() == HURTING;
        bool dying = p->getState()->getState() == DYING;


        p->setState(new IsHurtState());

        int pCenterX = p->getCollisionBox()->x + p->getCollisionBox()->w/2;
        int pCenterY = p->getCollisionBox()->y + p->getCollisionBox()->h/2;
        Vector pCenter(pCenterX, pCenterY);

        int entityCenterX = entity->minX() + entity->getRect()->w/2;
        int entityCenterY = entity->minY() + entity->getRect()->h/2;
        Vector circleCenter(entityCenterX, entityCenterY);

        Vector outwardForce =   circleCenter - pCenter;
        outwardForce.normalize();
        outwardForce.multiply(-OUTWARD_FORCE_SAW_X, -OUTWARD_FORCE_SAW_Y);

        if(outwardForce.x < MIN_OUTWARD_FORCE_SAW && outwardForce.x > -MIN_OUTWARD_FORCE_SAW) {
            outwardForce.x *= EXTRA_SAW_X_FORCE_IF_UNDER_MIN;
        }

        if(outwardForce.y < MIN_OUTWARD_FORCE_SAW && outwardForce.y > -MIN_OUTWARD_FORCE_SAW) {
            outwardForce.y *= EXTRA_SAW_Y_FORCE_IF_UNDER_MIN;
        }
        p->getDirection() = p->getDirection() + outwardForce;
        if(hurting || dying) return;
        PlayerStats::getInstance().takeDamage(SAW_ATTACK_DAMAGE);
    }
}
