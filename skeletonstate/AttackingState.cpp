//
// Created by niels on 6/2/21.
//

#include "AttackingState.h"
#include "../entity/Skeleton1.h"
#include "../animation/Skeleton1Animation.h"
SState AttackingState::getState() {
    return ATTACK;
}

void AttackingState::update(Skeleton1 *skeleton1) {
    skeleton1->getSprite()->setActiveAnimation(Skeleton1Animation::ATTACK);
}
