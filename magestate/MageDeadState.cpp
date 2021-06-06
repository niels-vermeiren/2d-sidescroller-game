//
// Created by niels on 06.06.21.
//

#include "MageDeadState.h"
#include "../command/mage/MageSlowDownCommand.h"

MState MageDeadState::getState() {
    return DOOD;
}

void MageDeadState::update(Mage *mage) {
    mage->getSprite()->setActiveAnimation(MageAnimation::DIE);
    MageSlowDownCommand cmd(mage);
    cmd.execute();
}
