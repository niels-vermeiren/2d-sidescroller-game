//
// Created by niels on 10.06.21.
//

#include "PlayerBulletMageCollisionHandler.h"
#include "../CollisionDetection.h"
#include "../../magestate/MageDeadState.h"

void PlayerBulletMageCollisionHandler::handleCollision(Mage *mage, PlayerBullet *bullet) {
    if(CollisionDetection::rectangleCircleIntersect(mage->getCollisionBox(), bullet->getCollisionBox()))  {
        if(bullet->isVisible()) {
            mage->getDirection().x = bullet->isFacingLeft() ? -ENEMY_FLYAWAY_WHEN_HIT_BY_PLAYER_BULLET : ENEMY_FLYAWAY_WHEN_HIT_BY_PLAYER_BULLET;
            mage->setState(new MageDeadState());
        }
        bullet->setVisibility(false);
    }
}
