//
// Created by niels on 5/13/21.
//

#include "IsHurtState.h"
#include "../command/player/SlowDownCommand.h"

void IsHurtState::update(Player *player) {
    player->getSprite()->setActiveAnimation(PlayerAnimation::HURT);
    SlowDownCommand cmd(player);
    cmd.execute();
    tick++;
    if(tick % HURT_DURATION == 0) {
        player->setState(new IsDeadState());
    }
}

PState IsHurtState::getState() {
    return HURTING;
}
