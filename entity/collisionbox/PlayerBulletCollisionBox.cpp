//
// Created by niels on 10.06.21.
//

#include "PlayerBulletCollisionBox.h"

SDL_Rect *PlayerBulletCollisionBox::getCollisionBox(SDL_Rect *boundingBox, bool isFacingLeft, bool isDead) {
    return isFacingLeft ? new SDL_Rect {boundingBox->x+6, boundingBox->y + 4, 10, 10}
    :new SDL_Rect {boundingBox->x + 30, boundingBox->y + 4, 10, 10} ;
}
