//
// Created by niels on 6/1/21.
//

#include "DyingState.h"
#include "../animation/SkeletonAnimation.h"
#include "../command/Command.h"
#include "../command/skeleton/SkeletonSlowDownCommand.h"

void DyingState::update(Skeleton * skeleton) {
    skeleton->getCollisionBox()->w = 30;
    if (!skeleton->isFacingLeft()) skeleton->getCollisionBox()->x += 20;
    skeleton->getSprite()->setActiveAnimation(SkeletonAnimation::DEAD);
    Command * slowDown = new SkeletonSlowDownCommand(skeleton);
    slowDown->execute();
}

SState DyingState::getState() {
    return DEAD;
}
