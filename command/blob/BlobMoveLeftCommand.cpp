//
// Created by niels on 6/1/21.
//

#include "BlobMoveLeftCommand.h"

BlobMoveLeftCommand::BlobMoveLeftCommand(Skeleton1 *entity) {
    this->entity = entity;
}

void BlobMoveLeftCommand::execute() {
    this->entity->getDirection() = Vector(-BLOB_SPEED, this->entity->getDirection().y);
    this->entity->setFacingLeft(true);
}
