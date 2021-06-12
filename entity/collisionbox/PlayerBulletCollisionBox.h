//
// Created by niels on 10.06.21.
//

#ifndef INC_2DSIDESCROLLER_PLAYERBULLETCOLLISIONBOX_H
#define INC_2DSIDESCROLLER_PLAYERBULLETCOLLISIONBOX_H


#include <SDL2/SDL_rect.h>
#include "CollisionBox.h"

class PlayerBulletCollisionBox : public CollisionBox {
public:
    SDL_Rect * getCollisionBox(SDL_Rect * boundingBox, bool isFacingLeft = false) override;

};


#endif //INC_2DSIDESCROLLER_PLAYERBULLETCOLLISIONBOX_H
