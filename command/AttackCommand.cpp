//
// Created by niels on 5/11/21.
//

#include "AttackCommand.h"

AttackCommand::AttackCommand(Player *entity) {
    this->entity = entity;
}

void AttackCommand::execute() {
    this->entity->getDirection().x = 0;
}
