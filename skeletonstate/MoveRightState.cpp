//
// Created by niels on 6/3/21.
//

#include "MoveRightState.h"
#include "../animation/SkeletonAnimation.h"
#include "../command/skeleton/SkeletonMoveRightCommand.h"

SState MoveRightState::getState() {
    return MOVE_RIGHT;
}

void MoveRightState::update(Skeleton *skeleton1) {
    skeleton1->getSprite()->setActiveAnimation(SkeletonAnimation::WALKING);
    SkeletonMoveRightCommand cmd(skeleton1);
    cmd.execute();
}
