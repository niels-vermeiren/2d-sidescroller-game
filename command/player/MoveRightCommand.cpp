//
// Created by niels on 4/11/21.
//

#include "MoveRightCommand.h"

MoveRightCommand::MoveRightCommand(Player * entity) {
    this->entity = entity;
}

void MoveRightCommand::execute() {
    this->entity->getDirection() = Vector(PLAYER_SPEED, this->entity->getDirection().y);
    this->entity->setFacingLeft(false);
}
