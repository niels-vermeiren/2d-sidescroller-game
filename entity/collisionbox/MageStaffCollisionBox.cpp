//
// Created by niels on 07.06.21.
//

#include "MageStaffCollisionBox.h"

SDL_Rect *MageStaffCollisionBox::getCollisionBox(SDL_Rect *boundingBox, bool isFacingLeft) {
    return  isFacingLeft ? new SDL_Rect{boundingBox->x + 11,boundingBox->y + 135,22,22} :
    new SDL_Rect{boundingBox->x + 133,boundingBox->y + 135,22,22};
}
