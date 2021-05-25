//
// Created by niels on 5/11/21.
//

#include "CrouchState.h"

void CrouchState::update(Player *player) {
    player->getSprite()->setActiveAnimation(PlayerAnimation::CROUCHING);

    if(InputManager::keyUp(SDL_SCANCODE_DOWN)) {
        player->setState(new OnGroundState());
    }

    if(InputManager::keyDown(SDL_SCANCODE_LEFT)) {
        CrouchMoveLeftCommand command(player);
        command.execute();
        player->getSprite()->setActiveAnimation(PlayerAnimation::CROUCH_WALKING);
    }

    if(InputManager::keyDown(SDL_SCANCODE_RIGHT)) {
        CrouchMoveRightCommand command(player);
        command.execute();
        player->getSprite()->setActiveAnimation(PlayerAnimation::CROUCH_WALKING);
    }

    if(InputManager::keyUp(SDL_SCANCODE_RIGHT) && InputManager::keyUp(SDL_SCANCODE_LEFT)) {
        StandStillCommand command(player);
        command.execute();
    }
}

PState CrouchState::getState() {
    return CROUCHING;
}
