//
// Created by niels on 5/6/21.
//

#include "CrouchMoveLeftCommand.h"

CrouchMoveLeftCommand::CrouchMoveLeftCommand(Player * entity) {
    this->entity = entity;
}

void CrouchMoveLeftCommand::execute() {
    this->entity->getDirection() = Vector(-CROUCH_SPEED, this->entity->getDirection().y);
    this->entity->setFacingLeft(true);
}

