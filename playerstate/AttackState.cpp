//
// Created by niels on 5/12/21.
//

#include "AttackState.h"

void AttackState::update(Player *player) {
    player->getSprite()->setActiveAnimation(PlayerAnimation::ATTACK);

    if(InputManager::keyPressed(SDL_SCANCODE_UP)) {
        JumpCommand jump(player);
        jump.execute();
        player->setState(new JumpState());
    }

    if(InputManager::keyUp(SDL_SCANCODE_SPACE)) {
        StandStillCommand standStillCmd(player);
        standStillCmd.execute();
        player->setState(new OnGroundState());
    }

    if(InputManager::keyDown(SDL_SCANCODE_DOWN)) {
        player->setState(new CrouchState());
    }
}

PState AttackState::getState() {
    return ATTACKING;
}
