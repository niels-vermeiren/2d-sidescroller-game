//
// Created by niels on 6/2/21.
//

#include "AttackingState.h"
#include "../entity/Skeleton.h"
#include "../animation/SkeletonAnimation.h"
#include "IdleState.h"
#include "../command/skeleton/SkeletonStandStillCommand.h"

SState AttackingState::getState() {
    return ATTACK;
}

void AttackingState::update(Skeleton *skeleton) {
    auto * cmd = new SkeletonStandStillCommand(skeleton);
    cmd->execute();
    tick++;
    if (tick % 30 == 0) {
        skeleton->setState(new IdleState());
    }
    skeleton->getSprite()->setActiveAnimation(SkeletonAnimation::ATTACK);
}
