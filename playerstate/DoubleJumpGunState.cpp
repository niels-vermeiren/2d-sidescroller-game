//
// Created by niels on 09.06.21.
//

#include "DoubleJumpGunState.h"
#include "../command/player/MoveLeftCommand.h"
#include "../command/player/MoveRightCommand.h"
#include "../command/player/StandStillCommand.h"
#include "DoubleJumpState.h"
#include "OnGroundState.h"

void DoubleJumpGunState::update(Player *player) {
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

    if(InputManager::keyPressed(SDL_SCANCODE_SPACE)) {
        player->shootBullet();
    }

    if(InputManager::keyPressed(SDL_SCANCODE_TAB)) {
        player->setPreviousState(new OnGroundState());
        player->setState(new DoubleJumpState());
    }
}

PState DoubleJumpGunState::getState() {
    return GUN_DOUBLE_JUMPING;
}
