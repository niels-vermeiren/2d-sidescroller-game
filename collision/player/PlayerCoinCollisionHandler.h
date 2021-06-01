//
// Created by niels on 5/27/21.
//

#ifndef INC_2DSIDESCROLLER_PLAYERCOINCOLLISIONHANDLER_H
#define INC_2DSIDESCROLLER_PLAYERCOINCOLLISIONHANDLER_H


#include "PlayerCollisionHandler.h"
#include "../../entity/Player.h"
#include "../../entity/Entity.h"

class PlayerCoinCollisionHandler : public PlayerCollisionHandler {
public:
    void handleCollision(Player * p, Entity * entity) override;

};


#endif //INC_2DSIDESCROLLER_PLAYERCOINCOLLISIONHANDLER_H
