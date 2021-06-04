//
// Created by niels on 6/1/21.
//

#ifndef INC_2DSIDESCROLLER_SKELETONCOLLISIONHANDLER_H
#define INC_2DSIDESCROLLER_SKELETONCOLLISIONHANDLER_H


#include "../../entity/EntityManager.h"
#include "../../entity/Entity.h"
#include "../../entity/Skeleton.h"

class SkeletonCollisionHandler {
public:
    virtual void handleCollision(Skeleton * skeleton, Entity * entity) = 0;
    virtual void handleCollisions(Skeleton * skeleton, const EntityManager * entities);
};


#endif //INC_2DSIDESCROLLER_SKELETONCOLLISIONHANDLER_H
