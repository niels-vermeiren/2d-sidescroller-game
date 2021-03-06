//
// Created by niels on 08.06.21.
//

#include "PlayerMageBulletCollisionHandler.h"
#include "../../collision/CollisionDetection.h"
#include "../../playerstate/IsHurtState.h"
#include "../../stats/PlayerStats.h"

void PlayerMageBulletCollisionHandler::handleCollision(Player *p, Entity *entity) {
    auto * bullet = dynamic_cast<MageBullet *>(entity);
    if(CollisionDetection::rectangleCircleIntersect(p->getCollisionBox(), bullet->getCollisionBox())) {
        if(entity->isVisible() && p->getState()->getState() != HURTING && p->getState()->getState() != DYING) {
            p->setState(new IsHurtState());
            PlayerStats::getInstance().takeDamage(MAGE_ATTACK_DAMAGE);
        }
        entity->setVisibility(false);
    }
}
