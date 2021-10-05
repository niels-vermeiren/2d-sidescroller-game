//
// Created by niels on 06.06.21.
//

#ifndef INC_2DSIDESCROLLER_PLAYERCOLLISIONBOX_H
#define INC_2DSIDESCROLLER_PLAYERCOLLISIONBOX_H


#include "CollisionBox.h"

class PlayerCollisionBox : public CollisionBox {
public:
    SDL_Rect * getCollisionBox(SDL_Rect * boundingBox, bool isFacingLeft = false, bool isDead = false) override;
};


#endif //INC_2DSIDESCROLLER_PLAYERCOLLISIONBOX_H
