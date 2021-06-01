//
// Created by niels on 4/28/21.
//

#include "DoubleJumpCommand.h"

DoubleJumpCommand::DoubleJumpCommand(Player *player) {
    this->player = player;
}

void DoubleJumpCommand::execute() {
    player->getDirection() = Vector(player->getDirection().x, -DOUBLE_JUMP_SPEED);
}
