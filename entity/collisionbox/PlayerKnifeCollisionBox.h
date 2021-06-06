//
// Created by niels on 06.06.21.
//

#ifndef INC_2DSIDESCROLLER_PLAYERKNIFECOLLISIONBOX_H
#define INC_2DSIDESCROLLER_PLAYERKNIFECOLLISIONBOX_H


#include "CollisionBox.h"

class PlayerKnifeCollisionBox : public CollisionBox {
public:
    SDL_Rect * getCollisionBox(SDL_Rect * boundingBox, bool isFacingLeft = false) override;

};


#endif //INC_2DSIDESCROLLER_PLAYERKNIFECOLLISIONBOX_H
