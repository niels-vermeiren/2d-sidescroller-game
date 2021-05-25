//
// Created by niels on 5/6/21.
//

#include "CrouchMoveRightCommand.h"

CrouchMoveRightCommand::CrouchMoveRightCommand(Player *entity) {
    this->entity = entity;
}

void CrouchMoveRightCommand::execute() {
    this->entity->getDirection() = Vector(CROUCH_SPEED, this->entity->getDirection().y);
    this->entity->setFacingLeft(false);
}
