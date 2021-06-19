//
// Created by niels on 6/2/21.
//

#include "AttackingState.h"
#include "../entity/Skeleton.h"
#include "../animation/SkeletonAnimation.h"
#include "IdleState.h"300
#include "../command/skeleton/SkeletonStandStillCommand.h"
#include "MoveLeftState.h"

SState AttackingState::getState() {
    return ATTACK;
}

void AttackingState::update(Skeleton *skeleton) {
    auto * cmd = new SkeletonStandStillCommand(skeleton);
    cmd->execute();
    tick++;
    if (tick % SKELETON_ATTACK_DURATION == 0) {
        skeleton->setState(new MoveLeftState());
    }
    skeleton->getSprite()->setActiveAnimation(SkeletonAnimation::ATTACK);
}
