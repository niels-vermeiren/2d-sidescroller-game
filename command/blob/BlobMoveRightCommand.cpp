//
// Created by niels on 6/1/21.
//

#include "BlobMoveRightCommand.h"

BlobMoveRightCommand::BlobMoveRightCommand(Skeleton1 *entity) {
    this->entity = entity;
}

void BlobMoveRightCommand::execute() {
    this->entity->getDirection() = Vector(BLOB_SPEED, this->entity->getDirection().y);
    this->entity->setFacingLeft(false);
}
