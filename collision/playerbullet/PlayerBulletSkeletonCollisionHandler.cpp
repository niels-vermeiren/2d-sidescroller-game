//
// Created by niels on 10.06.21.
//

#include "PlayerBulletSkeletonCollisionHandler.h"
#include "../../collision/CollisionDetection.h"
#include "../../skeletonstate/DyingState.h"


void PlayerBulletSkeletonCollisionHandler::handleCollision(Skeleton *skeleton, PlayerBullet *bullet) {
    if(CollisionDetection::rectangleCircleIntersect(skeleton->getCollisionBox(), bullet->getCollisionBox()))  {
        if(bullet->isVisible()) {
            skeleton->getDirection().x = bullet->isFacingLeft() ? -ENEMY_FLYAWAY_WHEN_HIT_BY_PLAYER_BULLET : ENEMY_FLYAWAY_WHEN_HIT_BY_PLAYER_BULLET;
            skeleton->setState(new DyingState());
        }
        bullet->setVisibility(false);
    }
}
