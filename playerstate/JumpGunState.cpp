//
// Created by niels on 09.06.21.
//

#include "JumpGunState.h"
#include "../command/player/MoveLeftCommand.h"
#include "../command/player/MoveRightCommand.h"
#include "../command/player/StandStillCommand.h"
#include "../command/player/DoubleJumpCommand.h"
#include "DoubleJumpGunState.h"

void JumpGunState::update(Player *player) {
    player->getSprite()->setActiveAnimation(PlayerAnimation::JUMP_GUN);

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

    if(InputManager::keyPressed(SDL_SCANCODE_UP)) {
        player->getSprite()->resetAnimation();
        player->setState(new DoubleJumpGunState());
        DoubleJumpCommand doubleJumpCmd(player);
        doubleJumpCmd.execute();
    }
}

PState JumpGunState::getState() {
    return GUN_JUMPING;
}
