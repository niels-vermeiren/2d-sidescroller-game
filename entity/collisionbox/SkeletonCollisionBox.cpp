//
// Created by niels on 06.06.21.
//

#include "SkeletonCollisionBox.h"

SDL_Rect *SkeletonCollisionBox::getCollisionBox(SDL_Rect *boundingBox, bool isFacingLeft) {
    return new SDL_Rect {boundingBox->x+53, boundingBox->y+43, 47, 106};
}
