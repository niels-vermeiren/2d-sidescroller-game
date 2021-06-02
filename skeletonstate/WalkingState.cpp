//
// Created by niels on 6/1/21.
//

#include "WalkingState.h"
#include "../animation/Skeleton1Animation.h"

SState WalkingState::getState() {
    return MOVING;
}

void WalkingState::update(Skeleton1 *skeleton1) {
    skeleton1->getSprite()->setActiveAnimation(Skeleton1Animation::WALKING);
}
