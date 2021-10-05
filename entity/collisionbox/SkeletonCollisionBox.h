//
// Created by niels on 06.06.21.
//

#ifndef INC_2DSIDESCROLLER_SKELETONCOLLISIONBOX_H
#define INC_2DSIDESCROLLER_SKELETONCOLLISIONBOX_H


#include <SDL2/SDL_rect.h>
#include "CollisionBox.h"

class SkeletonCollisionBox : public CollisionBox {
public:
    SDL_Rect * getCollisionBox(SDL_Rect * boundingBox, bool isFacingLeft = false, bool isDead = false) override;

};


#endif //INC_2DSIDESCROLLER_SKELETONCOLLISIONBOX_H
