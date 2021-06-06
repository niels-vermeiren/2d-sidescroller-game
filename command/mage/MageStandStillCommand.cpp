//
// Created by niels on 06.06.21.
//

#include "MageStandStillCommand.h"

MageStandStillCommand::MageStandStillCommand(Mage *entity) {
    this->entity = entity;
}

void MageStandStillCommand::execute() {
    this->entity->getDirection().x = 0;
}
