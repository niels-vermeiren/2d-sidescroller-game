//
// Created by niels on 19.06.21.
//

#include "SawMoveRightCommand.h"
#include "../../physics/PhysicsManager.h"

SawMoveRightCommand::SawMoveRightCommand(Saw *saw) {
    this->entity = saw;
}

void SawMoveRightCommand::execute() {
    this->entity->getDirection() = Vector(MOVING_SAW_SPEED, this->entity->getDirection().y);
}
