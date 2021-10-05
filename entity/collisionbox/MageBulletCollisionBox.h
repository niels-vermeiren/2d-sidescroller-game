//
// Created by niels on 08.06.21.
//

#ifndef INC_2DSIDESCROLLER_MAGEBULLETCOLLISIONBOX_H
#define INC_2DSIDESCROLLER_MAGEBULLETCOLLISIONBOX_H


#include <SDL2/SDL_rect.h>
#include "CollisionBox.h"

class MageBulletCollisionBox : public CollisionBox {
public:
    SDL_Rect * getCollisionBox(SDL_Rect * boundingBox, bool isFacingLeft = false, bool isDead = false) override;

};


#endif //INC_2DSIDESCROLLER_MAGEBULLETCOLLISIONBOX_H
