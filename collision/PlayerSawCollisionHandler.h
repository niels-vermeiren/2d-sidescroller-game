//
// Created by niels on 5/23/21.
//

#ifndef INC_2DSIDESCROLLER_PLAYERSAWCOLLISIONHANDLER_H
#define INC_2DSIDESCROLLER_PLAYERSAWCOLLISIONHANDLER_H


#include "CollisionHandler.h"
#include "CollisionDetection.h"
#include "../playerstate/IsHurtState.h"

class PlayerSawCollisionHandler : public CollisionHandler {
public:
    void handleCollision(Player * p, Entity * entity) override;
};


#endif //INC_2DSIDESCROLLER_PLAYERSAWCOLLISIONHANDLER_H
