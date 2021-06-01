//
// Created by niels on 5/23/21.
//

#ifndef INC_2DSIDESCROLLER_PLAYERSPIKECOLLISIONHANDLER_H
#define INC_2DSIDESCROLLER_PLAYERSPIKECOLLISIONHANDLER_H


#include "PlayerCollisionHandler.h"
#include "../../playerstate/IsDeadState.h"

class PlayerSpikeCollisionHandler : public PlayerCollisionHandler {
public:
    void handleCollision(Player * p, Entity * entity) override;
};


#endif //INC_2DSIDESCROLLER_PLAYERSPIKECOLLISIONHANDLER_H
