//
// Created by niels on 5/12/21.
//

#include "IsDeadState.h"

void IsDeadState::update(Player *player) {
    tick++;
    if(tick % (60 * SECONDS_DEAD_BEFORE_REWINDING) == 0) {
        player->setShouldDraw(false);
    }
    StandStillCommand standStillCmd(player);
    standStillCmd.execute();
    player->getSprite()->setActiveAnimation(PlayerAnimation::DEAD);
}

PState IsDeadState::getState() {
    return DYING;
}
