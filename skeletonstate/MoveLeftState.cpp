//
// Created by niels on 6/3/21.
//

#include "MoveLeftState.h"
#include "../animation/SkeletonAnimation.h"
#include "../command/skeleton/SkeletonMoveLeftCommand.h"
#include "../magestate/MageMoveLeftState.h"


void MoveLeftState::update(Skeleton *skeleton) {
    skeleton->getSprite()->setActiveAnimation(SkeletonAnimation::WALKING);
    SkeletonMoveLeftCommand cmd(skeleton);
    cmd.execute();
}

SState MoveLeftState::getState() {
    return MOVE_LEFT;
}
