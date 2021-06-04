//
// Created by niels on 6/2/21.
//

#include "IdleState.h"
#include "../animation/SkeletonAnimation.h"
SState IdleState::getState() {
    return IDLE;
}

void IdleState::update(Skeleton *skeleton) {
    skeleton->getSprite()->setActiveAnimation(SkeletonAnimation::IDLE);
}
