//
// Created by niels on 19.06.21.
//

#include "SawMoveLeftCommand.h"
#include "../../physics/PhysicsManager.h"

SawMoveLeftCommand::SawMoveLeftCommand(Saw *saw) {
    this->entity = saw;
}

void SawMoveLeftCommand::execute() {
    this->entity->getDirection() = Vector(-MOVING_SAW_SPEED, this->entity->getDirection().y);
}
