//
// Created by niels on 09.06.21.
//

#include "PlayerGunCollisionBox.h"

SDL_Rect *PlayerGunCollisionBox::getCollisionBox(SDL_Rect *boundingBox, bool isFacingLeft, bool isDead) {
    if(isFacingLeft)return new SDL_Rect {boundingBox->x+10, boundingBox->y + 79, 15, 12};
    else return new SDL_Rect {boundingBox->x + 125, boundingBox->y + 79, 15, 12};
}
