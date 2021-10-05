//
// Created by niels on 06.06.21.
//

#ifndef INC_2DSIDESCROLLER_COLLISIONBOX_H
#define INC_2DSIDESCROLLER_COLLISIONBOX_H


#include <SDL2/SDL_rect.h>

class CollisionBox {
public:
    virtual SDL_Rect * getCollisionBox(SDL_Rect * boundingBox, bool isFacingLeft = false, bool isDead = false) = 0;
};


#endif //INC_2DSIDESCROLLER_COLLISIONBOX_H
