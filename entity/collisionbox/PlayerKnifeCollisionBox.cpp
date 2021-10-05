//
// Created by niels on 06.06.21.
//

#include "PlayerKnifeCollisionBox.h"

SDL_Rect *PlayerKnifeCollisionBox::getCollisionBox(SDL_Rect *boundingBox, bool isFacingLeft, bool isDead) {
    if (isFacingLeft) return new SDL_Rect {boundingBox->x-53, boundingBox->y+78, 50, 12};
    else return new SDL_Rect {boundingBox->x+45, boundingBox->y+78, 50, 12};
}
