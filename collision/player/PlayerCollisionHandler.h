//
// Created by niels on 5/23/21.
//

#include "../../entity/Player.h"
#include "../../entity/Entity.h"
#include "../../entity/EntityManager.h"
#include "../../entity/Skeleton.h"

#ifndef INC_2DSIDESCROLLER_COLLISIONHANDLER_H
#define INC_2DSIDESCROLLER_COLLISIONHANDLER_H

class PlayerCollisionHandler {
public:
    virtual void handleCollision(Player * p, Entity * entity) {};
    virtual void handleCollisions(Player * p, const EntityManager * entities);
};


#endif //INC_2DSIDESCROLLER_COLLISIONHANDLER_H