//
// Created by niels on 6/2/21.
//

#include "PlayerSkeletonCollisionHandler.h"
#include "../../collision/CollisionDetection.h"
#include "../../skeletonstate/DyingState.h"

void PlayerSkeletonCollisionHandler::handleCollision(Player *p, Skeleton1 *skeleton) {

    SDL_Rect * swordRect = p->getSwordRect();
    if(p->getState()->getState() == ATTACKING && CollisionDetection::rectangleCircleIntersect(swordRect, skeleton->getBoundingRect())) {
        skeleton->setState(new DyingState());
    }

}
