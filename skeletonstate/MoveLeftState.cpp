//
// Created by niels on 6/3/21.
//

#include "MoveLeftState.h"
#include "../animation/SkeletonAnimation.h"
#include "../command/skeleton/SkeletonMoveLeftCommand.h"

void MoveLeftState::update(Skeleton *skeleton1) {
    skeleton1->getSprite()->setActiveAnimation(SkeletonAnimation::WALKING);
    SkeletonMoveLeftCommand cmd(skeleton1);
    cmd.execute();
}

SState MoveLeftState::getState() {
    return MOVE_LEFT;
}
