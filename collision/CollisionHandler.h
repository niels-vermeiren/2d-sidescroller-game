//
// Created by niels on 5/23/21.
//

#include "../entity/Player.h"
#include "../entity/Entity.h"
#include "../entity/EntityManager.h"

#ifndef INC_2DSIDESCROLLER_COLLISIONHANDLER_H
#define INC_2DSIDESCROLLER_COLLISIONHANDLER_H

class CollisionHandler {
public:
    virtual void handleCollision(Player * p, Entity * entity) = 0;
    virtual ~CollisionHandler();
    void handleCollisions(Player * p, const EntityManager * entities);
};


#endif //INC_2DSIDESCROLLER_COLLISIONHANDLER_H