//
// Created by niels on 6/1/21.
//

#include "SkeletonSlowDownCommand.h"

SkeletonSlowDownCommand::SkeletonSlowDownCommand(Skeleton *entity) {
    this->entity = entity;
}

void SkeletonSlowDownCommand::execute() {
    this->entity->getDirection().x *= SKELETON_HURT_SLOW_DOWN_X_PRODUCT;
}
