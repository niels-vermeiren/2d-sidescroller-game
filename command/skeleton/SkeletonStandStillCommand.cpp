//
// Created by niels on 6/3/21.
//

#include "SkeletonStandStillCommand.h"
SkeletonStandStillCommand::SkeletonStandStillCommand(Skeleton *skeleton) {
    this->skeleton = skeleton;
}

void SkeletonStandStillCommand::execute() {
    this->skeleton->getDirection().x = 0;
}
