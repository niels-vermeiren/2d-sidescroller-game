//
// Created by niels on 6/1/21.
//

#ifndef INC_2DSIDESCROLLER_SKELETON1COLLISIONHANDLER_H
#define INC_2DSIDESCROLLER_SKELETON1COLLISIONHANDLER_H


#include "../../entity/EntityManager.h"
#include "../../entity/Entity.h"
#include "../../entity/Skeleton1.h"

class Skeleton1CollisionHandler {
public:
    virtual void handleCollision(Skeleton1 * blob, Entity * entity) = 0;
    virtual void handleCollisions(Skeleton1 * blob, const EntityManager * entities);
};


#endif //INC_2DSIDESCROLLER_SKELETON1COLLISIONHANDLER_H
