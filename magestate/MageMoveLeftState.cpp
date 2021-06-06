//
// Created by niels on 06.06.21.
//

#include "MageMoveLeftState.h"

void MageMoveLeftState::update(Mage *mage) {
    mage->getSprite()->setActiveAnimation(MageAnimation::WALK);
    mage->setFacingLeft(true);
    MageMoveLeftCommand cmd(mage);
    cmd.execute();
}

MState MageMoveLeftState::getState() {
    return LEFT;
}
