//
// Created by niels on 07.06.21.
//

#ifndef INC_2DSIDESCROLLER_MAGESTAFFCOLLISIONBOX_H
#define INC_2DSIDESCROLLER_MAGESTAFFCOLLISIONBOX_H


#include "CollisionBox.h"

class MageStaffCollisionBox : public CollisionBox {
public:
    SDL_Rect * getCollisionBox(SDL_Rect * boundingBox, bool isFacingLeft = false) override;

};


#endif //INC_2DSIDESCROLLER_MAGESTAFFCOLLISIONBOX_H
