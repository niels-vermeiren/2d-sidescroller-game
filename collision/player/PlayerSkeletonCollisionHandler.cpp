//
// Created by niels on 6/2/21.
//

#include "PlayerSkeletonCollisionHandler.h"
#include "../../collision/CollisionDetection.h"
#include "../../skeletonstate/DyingState.h"
#include "../../playerstate/IsHurtState.h"

void PlayerSkeletonCollisionHandler::handleCollision(Player *p, Skeleton *skeleton) {
    SDL_Rect * pCollisionBox = p->getCollisionBox();
    SDL_Rect * pKnifeBox = p->getKnifeCollisionBox();
    Vector * pDirection = &p->getDirection();
    PState pState = p->getState()->getState();
    SDL_Rect * sCollisionBox = skeleton->getCollisionBox();
    Vector * sDirection = &skeleton->getDirection();
    SDL_Rect * sAxeBox = skeleton->getAxeCollisionBox();
    SState sState = skeleton->getState()->getState();

    if(pState == HURTING || pState == DYING || sState == DEAD) return;

    //Player hits skeleton with knife
    if(CollisionDetection::rectanglesIntersect(pKnifeBox, sCollisionBox) && pState == ATTACKING) {
        sDirection->x += skeleton->minX() < p->minX() ? -PLAYER_SKELETON_HIT_PUSH : PLAYER_SKELETON_HIT_PUSH ;
        skeleton->setState(new DyingState());
    }

    //Skeleton attacks player with axe
    if(sState == ATTACK && skeleton->getSprite()->getCurrentFrame() == 6 && CollisionDetection::rectanglesIntersect(pCollisionBox, sAxeBox)) {
        p->setState(new IsHurtState());
        pDirection->x += skeleton->facingLeft() ? -PLAYER_SKELETON_HIT_PUSH : PLAYER_SKELETON_HIT_PUSH;
    }

    /*bool playerOnSameHeightEnemy = p->minY() + pCollisionBox->h < sCollisionBox->y + sCollisionBox->h && p->minY() + pCollisionBox->h / 2 > sCollisionBox->y;

    //Player hits skeleton from the left
    if(playerOnSameHeightEnemy && pCollisionBox->x - pDirection->x <= sCollisionBox->x && pCollisionBox->x + pCollisionBox->w > sCollisionBox->x) {
        pDirection->x -= PLAYER_SKELETON_HIT_PUSH ;
        p->setState(new IsHurtState());
    }

    //Player hits skeleton from the right
    if(playerOnSameHeightEnemy && pCollisionBox->x - pDirection->x >= sCollisionBox->x + sCollisionBox->w && pCollisionBox->x < sCollisionBox->x + sCollisionBox->w) {
        pDirection->x += PLAYER_SKELETON_HIT_PUSH ;
        p->setState(new IsHurtState());
    }*/
}
