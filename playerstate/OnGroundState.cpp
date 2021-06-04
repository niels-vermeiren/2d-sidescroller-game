//
// Created by niels on 4/29/21.
//

#include "OnGroundState.h"
#include "../command/skeleton/SkeletonStandStillCommand.h"

void OnGroundState::update(Player *player) {
    player->getSprite()->setActiveAnimation(PlayerAnimation::IDLE);

    if(InputManager::keyDown(SDL_SCANCODE_RIGHT)) {
        MoveRightCommand moveRight(player);
        moveRight.execute();
        player->getSprite()->setActiveAnimation(PlayerAnimation::WALKING);
    }

    if(InputManager::keyDown(SDL_SCANCODE_LEFT)) {
        MoveLeftCommand moveLeft(player);
        moveLeft.execute();
        player->getSprite()->setActiveAnimation(PlayerAnimation::WALKING);
    }

    if(InputManager::keyUp(SDL_SCANCODE_LEFT) && InputManager::keyUp(SDL_SCANCODE_RIGHT)) {
        StandStillCommand idle(player);
        idle.execute();
    }

    if(InputManager::keyDown(SDL_SCANCODE_DOWN)) {
        player->setState(new CrouchState());
    }

    if(InputManager::keyPressed(SDL_SCANCODE_UP)) {
        JumpCommand jump(player);
        jump.execute();
        player->setState(new JumpState());
    }

    if(InputManager::keyDown(SDL_SCANCODE_SPACE)) {
        Command * attackCommand = new AttackCommand(player);
        attackCommand->execute();
        player->setState(new AttackState());
    }
}

PState OnGroundState::getState() {
    return WALKING;
}
