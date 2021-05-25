//
// Created by niels on 5/12/21.
//

#include "DoubleJumpAttackState.h"

void DoubleJumpAttackState::update(Player *player) {
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

    if(InputManager::keyUp(SDL_SCANCODE_SPACE)) {
        player->setState(new DoubleJumpState());
    }
}

PState DoubleJumpAttackState::getState() {
    return DOUBLE_JUMP_ATTACKING;
}
