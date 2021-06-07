//
// Created by niels on 07.06.21.
//

#include "MageStandStillState.h"
#include "../command/mage/MageStandStillCommand.h"

MState MageStandStillState::getState() {
    return STILL;
}

void MageStandStillState::update(Mage *mage) {
    mage->getSprite()->setActiveAnimation(MageAnimation::IDLE);
    auto * standStillCmd = new MageStandStillCommand(mage);
    standStillCmd->execute();
}
