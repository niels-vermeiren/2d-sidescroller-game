//
// Created by niels on 4/11/21.
//

#include "MoveLeftCommand.h"

MoveLeftCommand::MoveLeftCommand(Player * entity) {
    this->entity = entity;
}

void MoveLeftCommand::execute() {
    this->entity->getDirection() = Vector(-PLAYER_SPEED, this->entity->getDirection().y);
    this->entity->setFacingLeft(true);
}

