//
// Created by niels on 6/2/21.
//

#include "IdleState.h"
#include "../animation/Skeleton1Animation.h"
SState IdleState::getState() {
    return IDLE;
}

void IdleState::update(Skeleton1 *skeleton) {
    skeleton->getSprite()->setActiveAnimation(Skeleton1Animation::IDLE);
}
