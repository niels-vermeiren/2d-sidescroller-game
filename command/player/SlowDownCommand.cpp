//
// Created by niels on 5/14/21.
//

#include "SlowDownCommand.h"

SlowDownCommand::SlowDownCommand(Player *entity) {
    this->entity = entity;
}

void SlowDownCommand::execute() {
    this->entity->getDirection().x *= SAW_FLYAWAY_SLOWDOWN_X_PRODUCT;
}
