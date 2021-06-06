//
// Created by niels on 06.06.21.
//

#include "MageSlowDownCommand.h"

MageSlowDownCommand::MageSlowDownCommand(Mage *entity) {
    this->entity = entity;
}

void MageSlowDownCommand::execute() {
    this->entity->getDirection().x *= SKELETON_HURT_SLOW_DOWN_X_PRODUCT;
}
