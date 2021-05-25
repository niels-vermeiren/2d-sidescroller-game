//
// Created by niels on 4/11/21.
//

#include "JumpCommand.h"

JumpCommand::JumpCommand(Player * player) {
    this->player = player;
}

void JumpCommand::execute() {
    player->getSprite()->setActiveAnimation(PlayerAnimation::JUMPING);
    this->player->getDirection() = Vector(player->getDirection().x, -JUMP_SPEED);
}
