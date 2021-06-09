//
// Created by niels on 09.06.21.
//

#ifndef INC_2DSIDESCROLLER_PLAYERGUNCOLLISIONBOX_H
#define INC_2DSIDESCROLLER_PLAYERGUNCOLLISIONBOX_H


#include <SDL2/SDL_rect.h>
#include "CollisionBox.h"

class PlayerGunCollisionBox : public CollisionBox {
public:
    SDL_Rect * getCollisionBox(SDL_Rect * boundingBox, bool isFacingLeft = false) override;

};


#endif //INC_2DSIDESCROLLER_PLAYERGUNCOLLISIONBOX_H
