//
// Created by niels on 06.06.21.
//

#include "MageMoveLeftCommand.h"

MageMoveLeftCommand::MageMoveLeftCommand(Mage *entity) {
    this->entity = entity;
}

void MageMoveLeftCommand::execute() {
    this->entity->getDirection() = Vector(-MAGE_SPEED, this->entity->getDirection().y);
    this->entity->setFacingLeft(true);
}
