//
// Created by niels on 06.06.21.
//

#include "MageCollisionBox.h"

SDL_Rect *MageCollisionBox::getCollisionBox(SDL_Rect *boundingBox, bool isFacingLeft, bool isDead) {
    return new SDL_Rect {boundingBox->x+56, boundingBox->y+52, 52, 108};
}
