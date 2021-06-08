//
// Created by niels on 08.06.21.
//

#include "PlayerMageBulletCollisionHandler.h"
#include "../../collision/CollisionDetection.h"
#include "../../playerstate/IsHurtState.h"

void PlayerMageBulletCollisionHandler::handleCollision(Player *p, Entity *entity) {
    MageBullet * bullet = dynamic_cast<MageBullet *>(entity);
    if(CollisionDetection::rectangleCircleIntersect(p->getCollisionBox(), bullet->getCollisionBox())) {
        if(p->getState()->getState() != HURTING && p->getState()->getState() != DYING) p->setState(new IsHurtState());
        entity->setVisible(false);
    }
}
