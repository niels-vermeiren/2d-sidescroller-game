//
// Created by niels on 5/11/21.
//

#include "CrouchState.h"
#include "../command/player/SlowDownCommand.h"

void CrouchState::update(Player *player) {
    player->getSprite()->setActiveAnimation(PlayerAnimation::CROUCHING);
    SlowDownCommand command(player);
    command.execute();
    if(InputManager::keyUp(SDL_SCANCODE_DOWN)) {
        player->setState(player->getPreviousState());
    }
}

PState CrouchState::getState() {
    return CROUCHING;
}
