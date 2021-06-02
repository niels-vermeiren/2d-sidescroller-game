//
// Created by niels on 6/1/21.
//

#include "BlobSlowDownCommand.h"

BlobSlowDownCommand::BlobSlowDownCommand(Skeleton1 *entity) {
    this->entity = entity;
}

void BlobSlowDownCommand::execute() {
    this->entity->getDirection().x *= BLOB_HURT_SLOW_DOWN_X_PRODUCT;
}
