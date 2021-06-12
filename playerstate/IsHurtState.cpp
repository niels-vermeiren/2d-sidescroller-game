//
// Created by niels on 5/13/21.
//

#include "IsHurtState.h"
#include "../command/player/SlowDownCommand.h"
#include "../stats/PlayerStats.h"

void IsHurtState::update(Player *player) {
    player->getSprite()->setActiveAnimation(PlayerAnimation::HURT);
    SlowDownCommand cmd(player);
    cmd.execute();
    tick++;
    if(tick % HURT_DURATION == 0) {
        if(PlayerStats::getInstance().getHealth() < 0) {
            player->setState(new IsDeadState());
            return;
        }
        player->setState(player->getPreviousState());
    }
}

PState IsHurtState::getState() {
    return HURTING;
}
