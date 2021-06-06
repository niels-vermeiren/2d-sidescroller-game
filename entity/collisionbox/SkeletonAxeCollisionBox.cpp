//
// Created by niels on 06.06.21.
//

#include "SkeletonAxeCollisionBox.h"

SDL_Rect *SkeletonAxeCollisionBox::getCollisionBox(SDL_Rect *boundingBox, bool isFacingLeft) {
    if (isFacingLeft) {
        return new SDL_Rect {boundingBox->x+10,boundingBox->y+85,30,40};
    } else {
        return new SDL_Rect {boundingBox->x+113,boundingBox->y+85,30,40};
    }
}
