//
// Created by niels on 4/29/21.
//

#include "DoubleJumpState.h"
#include "../command/player/MoveLeftCommand.h"
#include "../command/player/StandStillCommand.h"
#include "../command/player/MoveRightCommand.h"
#include "DoubleJumpGunState.h"
#include "RunGunState.h"

void DoubleJumpState::update(Player *player) {
    player->getSprite()->setActiveAnimation(PlayerAnimation::JUMPING);

    if(InputManager::keyDown(SDL_SCANCODE_LEFT)) {
        MoveLeftCommand moveLeft(player);
        moveLeft.execute();
    }

    if(InputManager::keyDown(SDL_SCANCODE_RIGHT)) {
        MoveRightCommand moveRight(player);
        moveRight.execute();
    }

    if(InputManager::keyUp(SDL_SCANCODE_LEFT) && InputManager::keyUp(SDL_SCANCODE_RIGHT)) {
        StandStillCommand idle(player);
        idle.execute();
    }

    if(InputManager::keyPressed(SDL_SCANCODE_TAB)) {
        player->setPreviousState(new RunGunState());
        player->setState(new DoubleJumpGunState());
    }
}

PState DoubleJumpState::getState() {
    return DOUBLE_JUMPING;
}
