//
// Created by niels on 6/2/21.
//

#include "PlayerSkeletonCollisionHandler.h"
#include "../../collision/CollisionDetection.h"
#include "../../skeletonstate/DyingState.h"
#include "../../playerstate/IsHurtState.h"

void PlayerSkeletonCollisionHandler::handleCollision(Player *p, Skeleton *skeleton) {
    //Attack from player
    SDL_Rect * swordRect = p->getSwordRect();
    if(p->getState()->getState() == ATTACKING && CollisionDetection::rectanglesIntersect(swordRect, skeleton->getBoundingRect())
    && skeleton->getState()->getState() != DEAD ) {
        skeleton->getDirection() = Vector(skeleton->minX() + skeleton->getRect()->w/2, 0) - Vector(p->minX() + p->getRect()->w/2, 0);
        skeleton->getDirection().x /= 16;
        skeleton->setState(new DyingState());
    }
    //If p is located on the left of the entity, and moving against it
    if(p->minY() < skeleton->getBoundingRect()->y + skeleton->getBoundingRect()->h && p->maxY() > skeleton->getBoundingRect()->y &&
       p->maxX() - p->getDirection().x <= skeleton->getBoundingRect()->x && p->maxX()  > skeleton->getBoundingRect()->x
       && skeleton->getState()->getState() != DEAD) {
        p->getDirection().x -= 9;
        p->setState(new IsHurtState());
    }
    //If p is located on the right of the skeleton, and moving against it
    if(p->minY() < skeleton->getBoundingRect()->y + skeleton->getBoundingRect()->h && p->maxY() > skeleton->getBoundingRect()->y &&
       p->minX() - p->getDirection().x >= skeleton->getBoundingRect()->x + skeleton->getBoundingRect()->w &&
       p->minX() < skeleton->getBoundingRect()->x + skeleton->getBoundingRect()->w && skeleton->getState()->getState() != DEAD) {
        p->getDirection().x += 9;
        p->setState(new IsHurtState());
    }
    //Atack from skeleton
    if(skeleton->getState()->getState() != ATTACK || skeleton->getSprite()->getCurrentFrame() != 6 || p->getState()->getState() == HURTING
    || p->getState()->getState() == DYING) return;

    if(CollisionDetection::rectanglesIntersect(p->getRect(), skeleton->getAxeAttackBoundingBox())) {
        p->setState(new IsHurtState());
        if (skeleton->facingLeft()) {
            p->getDirection().x -= 9;
        } else {
            p->getDirection().x += 9;
        }
    }


}
