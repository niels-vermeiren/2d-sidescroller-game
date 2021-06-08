//
// Created by niels on 08.06.21.
//

#include "MageBulletCollisionBox.h"

SDL_Rect *MageBulletCollisionBox::getCollisionBox(SDL_Rect *boundingBox, bool isFacingLeft) {
    return new SDL_Rect{boundingBox->x + 12, boundingBox->y + 12, boundingBox->w - 24, boundingBox->h - 24};
}
