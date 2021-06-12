//
// Created by niels on 09.06.21.
//

#include "RunGunState.h"
#include "../command/player/MoveRightCommand.h"
#include "../command/player/MoveLeftCommand.h"
#include "../command/player/StandStillCommand.h"
#include "CrouchState.h"
#include "JumpGunState.h"

void RunGunState::update(Player *player) {


    if(InputManager::keyDown(SDL_SCANCODE_RIGHT)) {
        MoveRightCommand moveRight(player);
        moveRight.execute();
        player->getSprite()->setActiveAnimation(PlayerAnimation::RUN_GUN);
    }

    if(InputManager::keyDown(SDL_SCANCODE_LEFT)) {
        MoveLeftCommand moveLeft(player);
        moveLeft.execute();
        player->getSprite()->setActiveAnimation(PlayerAnimation::RUN_GUN);
    }

    if(InputManager::keyUp(SDL_SCANCODE_LEFT) && InputManager::keyUp(SDL_SCANCODE_RIGHT)) {
        player->getSprite()->setActiveAnimation(PlayerAnimation::IDLE_GUN);
        StandStillCommand idle(player);
        idle.execute();
    }

    if(InputManager::keyDown(SDL_SCANCODE_DOWN)) {
        player->setPreviousState(this);
        player->setState(new CrouchState());
    }

    if(InputManager::keyPressed(SDL_SCANCODE_UP)) {
        player->setPreviousState(this);
        JumpCommand jump(player);
        jump.execute();
        player->setState(new JumpGunState());
    }

    if(InputManager::keyPressed(SDL_SCANCODE_TAB)) {
        player->setState(new OnGroundState());
    }

    if(InputManager::keyPressed(SDL_SCANCODE_SPACE)) {
        player->shootBullet();
    }
}

PState RunGunState::getState() {
    return GUN;
}
