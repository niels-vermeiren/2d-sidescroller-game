//
// Created by niels on 6/2/21.
//

#include "PlayerSkeletonCollisionHandler.h"
#include "../../collision/CollisionDetection.h"
#include "../../skeletonstate/DyingState.h"

void PlayerSkeletonCollisionHandler::handleCollision(Player *p, Skeleton *skeleton) {

    SDL_Rect * swordRect = p->getSwordRect();
    if(p->getState()->getState() == ATTACKING && CollisionDetection::rectanglesIntersect(swordRect, skeleton->getBoundingRect())
    && skeleton->getState()->getState() != DEAD) {
        skeleton->getDirection() = Vector(skeleton->minX() + skeleton->getRect()->w/2, 0) - Vector(p->minX() + p->getRect()->w/2, 0);
        skeleton->getDirection().x /= 16;
        skeleton->setState(new DyingState());
    }

}
