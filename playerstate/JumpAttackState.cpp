//
// Created by niels on 5/12/21.
//

#include "JumpAttackState.h"

void JumpAttackState::update(Player *player) {
    player->getSprite()->setActiveAnimation(PlayerAnimation::JUMP_ATTACK);

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

    if(InputManager::keyUp(SDL_SCANCODE_SPACE)) {
        player->setState(new JumpState());
    }
}

PState JumpAttackState::getState() {
    return JUMP_ATTACKING;
}
