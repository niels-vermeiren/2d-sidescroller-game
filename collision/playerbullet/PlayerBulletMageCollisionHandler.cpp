//
// Created by niels on 10.06.21.
//

#include "PlayerBulletMageCollisionHandler.h"
#include "../CollisionDetection.h"
#include "../../magestate/MageDeadState.h"

void PlayerBulletMageCollisionHandler::handleCollision(Mage *skeleton, PlayerBullet *bullet) {
    if(CollisionDetection::rectangleCircleIntersect(skeleton->getCollisionBox(), bullet->getCollisionBox()))  {
        if(bullet->isVisible()) {
            skeleton->setState(new MageDeadState());
            skeleton->getRect()->x += bullet->isFacingLeft() ? -12 : 12;
        }
        bullet->setVisibility(false);
    }
}
