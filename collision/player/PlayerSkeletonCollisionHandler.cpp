//
// Created by niels on 6/2/21.
//

#include "PlayerSkeletonCollisionHandler.h"
#include "../../collision/CollisionDetection.h"
#include "../../skeletonstate/DyingState.h"
#include "../../playerstate/IsHurtState.h"
#include "../../stats/PlayerStats.h"
#include "../../sound/JukeBox.h"

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
        sDirection->x += skeleton->minX() < p->minX() ? -PLAYER_BULLET_SKELETON_HIT_PUSH : PLAYER_BULLET_SKELETON_HIT_PUSH;
        JukeBox::getInstance()->playSound(JukeBox::SKELETON_HIT, true);
        skeleton->setState(new DyingState());
    }

    //Skeleton attacks player with axe
    if(sState == ATTACK && (skeleton->getSprite()->getCurrentFrame() == 6 || skeleton->getSprite()->getCurrentFrame() == 5)  && CollisionDetection::rectanglesIntersect(pCollisionBox, sAxeBox)) {
        p->setState(new IsHurtState());
        PlayerStats::getInstance().takeDamage(SKELETON_ATTACK_DAMAGE);
        pDirection->x += skeleton->isFacingLeft() ? -PLAYER_BULLET_SKELETON_HIT_PUSH : PLAYER_BULLET_SKELETON_HIT_PUSH;
    }
}
