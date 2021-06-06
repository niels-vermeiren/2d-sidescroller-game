//
// Created by niels on 06.06.21.
//

#ifndef INC_2DSIDESCROLLER_PLAYERMAGECOLLISIONHANDLER_H
#define INC_2DSIDESCROLLER_PLAYERMAGECOLLISIONHANDLER_H


#include "PlayerCollisionHandler.h"
#include "../../entity/Mage.h"

class PlayerMageCollisionHandler : public PlayerCollisionHandler {
public:
    void handleCollision(Player * p, Mage * mage);
};


#endif //INC_2DSIDESCROLLER_PLAYERMAGECOLLISIONHANDLER_H
