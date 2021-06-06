//
// Created by niels on 06.06.21.
//

#include "MageMoveRightState.h"
#include "../command/mage/MageMoveRightCommand.h"

MState MageMoveRightState::getState() {
    return RIGHT;
}

void MageMoveRightState::update(Mage *mage) {
    mage->setFacingLeft(false);
    mage->getSprite()->setActiveAnimation(MageAnimation::WALK);
    MageMoveRightCommand cmd(mage);
    cmd.execute();
}
