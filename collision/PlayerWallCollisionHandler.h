//
// Created by niels on 5/23/21.
//

#ifndef INC_2DSIDESCROLLER_PLAYERWALLCOLLISIONHANDLER_H
#define INC_2DSIDESCROLLER_PLAYERWALLCOLLISIONHANDLER_H

#include "CollisionHandler.h"
#include "../playerstate/OnGroundState.h"

class PlayerWallCollisionHandler : public CollisionHandler {
public:
    void handleCollision(Player * p, Entity * entity) override;
};


#endif //INC_2DSIDESCROLLER_PLAYERWALLCOLLISIONHANDLER_H
