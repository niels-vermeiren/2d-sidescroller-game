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
    tick++;
    MageStandStillCommand cmd(mage);
    cmd.execute();
    int attackFrameNum = mage->getSprite()->getCurrentFrame();
    if(!canAttack) canAttack = tick % countdownAttackReset == 0 || tick == -1;
    if(canAttack) {
        mage->getSprite()->setActiveAnimation(MageAnimation::ATTACK);

    } else {
        mage->getSprite()->setActiveAnimation(MageAnimation::IDLE);
    }

    if(mage->getState()->getState() == DOOD) return;
    if(canAttack && attackFrameNum == 6
    ) {
        mage->setShouldAttack(true);
        canAttack = false;
        tick = 0;

    } else {

    }
    if (attackFrameNum > 6) {

        mage->getSprite()->resetAnimation();
        mage->setShouldAttack(false);
    }
}
