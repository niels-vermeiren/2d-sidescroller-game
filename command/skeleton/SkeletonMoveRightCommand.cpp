//
// Created by niels on 6/1/21.
//

#include "SkeletonMoveRightCommand.h"

SkeletonMoveRightCommand::SkeletonMoveRightCommand(Skeleton *entity) {
    this->entity = entity;
}

void SkeletonMoveRightCommand::execute() {
    this->entity->getDirection() = Vector(SKELETON_SPEED, this->entity->getDirection().y);
    this->entity->setFacingLeft(false);
}
