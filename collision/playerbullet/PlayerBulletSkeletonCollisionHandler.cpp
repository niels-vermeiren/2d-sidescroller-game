//
// Created by niels on 10.06.21.
//

#include "PlayerBulletSkeletonCollisionHandler.h"
#include "../../collision/CollisionDetection.h"
#include "../../skeletonstate/DyingState.h"


void PlayerBulletSkeletonCollisionHandler::handleCollision(Skeleton *skeleton, PlayerBullet *bullet) {
    if(CollisionDetection::rectangleCircleIntersect(skeleton->getCollisionBox(), bullet->getCollisionBox()))  {
        if(bullet->isVisible()) {
            skeleton->setState(new DyingState());
            skeleton->getRect()->x += bullet->isFacingLeft() ? -12 : 12;
        }
        bullet->setVisibility(false);
    }
}
