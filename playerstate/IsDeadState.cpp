//
// Created by niels on 5/12/21.
//

#include "IsDeadState.h"

void IsDeadState::update(Player *player) {
    StandStillCommand standStillCmd(player);
    standStillCmd.execute();
    player->getSprite()->setActiveAnimation(PlayerAnimation::DEAD);
}

PState IsDeadState::getState() {
    return DYING;
}
