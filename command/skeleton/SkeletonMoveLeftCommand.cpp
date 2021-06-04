//
// Created by niels on 6/1/21.
//

#include "SkeletonMoveLeftCommand.h"

SkeletonMoveLeftCommand::SkeletonMoveLeftCommand(Skeleton *entity) {
    this->entity = entity;
}

void SkeletonMoveLeftCommand::execute() {
    this->entity->getDirection() = Vector(-SKELETON_SPEED, this->entity->getDirection().y);
    this->entity->setFacingLeft(true);
}
