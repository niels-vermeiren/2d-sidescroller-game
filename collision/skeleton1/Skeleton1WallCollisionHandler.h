//
// Created by niels on 6/1/21.
//

#ifndef INC_2DSIDESCROLLER_SKELETON1WALLCOLLISIONHANDLER_H
#define INC_2DSIDESCROLLER_SKELETON1WALLCOLLISIONHANDLER_H


#include "Skeleton1CollisionHandler.h"

class Skeleton1WallCollisionHandler : public Skeleton1CollisionHandler {
public:
    void handleCollision(Skeleton1 * blob, Entity * entity) override;

};


#endif //INC_2DSIDESCROLLER_SKELETON1WALLCOLLISIONHANDLER_H
