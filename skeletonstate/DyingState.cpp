//
// Created by niels on 6/1/21.
//

#include "DyingState.h"
#include "../animation/Skeleton1Animation.h"

void DyingState::update(Skeleton1 * skeleton) {
    skeleton->getSprite()->setActiveAnimation(Skeleton1Animation::DEAD);
}

SState DyingState::getState() {
    return DEAD;
}
