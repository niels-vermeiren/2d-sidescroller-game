//
// Created by niels on 4/29/21.
//

#include "JumpState.h"

void JumpState::update(Player *player) {
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

    if(InputManager::keyPressed(SDL_SCANCODE_UP)) {
        player->setState(new DoubleJumpState());
        DoubleJumpCommand doubleJumpCmd(player);
        doubleJumpCmd.execute();
    }

    if(InputManager::keyDown(SDL_SCANCODE_SPACE)) {
        player->setState(new JumpAttackState());
    }
}

PState JumpState::getState() {
    return JUMPING;
}
