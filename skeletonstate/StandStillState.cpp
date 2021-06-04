//
// Created by niels on 6/3/21.
//

#include "StandStillState.h"
#include "../command/skeleton/SkeletonStandStillCommand.h"
#include "../animation/SkeletonAnimation.h"

SState StandStillState::getState() {
    return IDLE;
}

void StandStillState::update(Skeleton *skeleton) {
    skeleton->getSprite()->setActiveAnimation(SkeletonAnimation::IDLE);
    auto * standStillCmd = new SkeletonStandStillCommand(skeleton);
    standStillCmd->execute();
}
