//
// Created by niels on 07.06.21.
//

#include "MageAttackState.h"
#include "../command/mage/MageStandStillCommand.h"
#include "MageStandStillState.h"

MState MageAttackState::getState() {
    return STAFF_ATTACK;
}

void MageAttackState::update(Mage *mage) {
    auto * cmd = new MageStandStillCommand(mage);
    cmd->execute();
    tick++;
    if (tick % SKELETON_ATTACK_DURATION == 0) {
        mage->setState(new MageStandStillState());
    }
    mage->getSprite()->setActiveAnimation(MageAnimation::ATTACK);
}
