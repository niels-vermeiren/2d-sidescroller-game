//
// Created by niels on 4/10/21.
//

#include "FallingEntity.h"

FallingEntity::FallingEntity(Vector direction, SDL_Rect * rect) : Entity(direction, rect) {
    this->gravity = {0, GRAVITY};
}

void FallingEntity::applyGravity() {
    this->direction = this->direction + this->gravity;
    if (this->direction.y > MAX_FALLING_SPEED) this->direction.y = MAX_FALLING_SPEED;
}
