//
// Created by niels on 06.06.21.
//

#include "PlayerCollisionBox.h"

SDL_Rect *PlayerCollisionBox::getCollisionBox(SDL_Rect *boundingBox, bool isFacingLeft) {
    return new SDL_Rect {boundingBox->x+54, boundingBox->y+15, 44, 127};
}
