//
// Created by niels on 4/11/21.
//

#include "StandStillCommand.h"
#include "../skeleton/SkeletonStandStillCommand.h"


StandStillCommand::StandStillCommand(Player *entity) {
    this->entity = entity;
}

void StandStillCommand::execute() {
    this->entity->getDirection().x = 0;
}
