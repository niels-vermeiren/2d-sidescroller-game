//
// Created by niels on 06.06.21.
//

#include "MageMoveRightCommand.h"

MageMoveRightCommand::MageMoveRightCommand(Mage *entity) {
    this->entity = entity;
}

void MageMoveRightCommand::execute() {
    this->entity->getDirection() = Vector(MAGE_SPEED, this->entity->getDirection().y);
    this->entity->setFacingLeft(false);
}
