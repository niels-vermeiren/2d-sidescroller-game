//
// Created by niels on 6/1/21.
//

#ifndef INC_2DSIDESCROLLER_SKELETONWALLCOLLISIONHANDLER_H
#define INC_2DSIDESCROLLER_SKELETONWALLCOLLISIONHANDLER_H


#include "SkeletonCollisionHandler.h"

class SkeletonWallCollisionHandler : public SkeletonCollisionHandler {
public:
    void handleCollision(Skeleton * skeleton, Entity * entity) override;

};


#endif //INC_2DSIDESCROLLER_SKELETONWALLCOLLISIONHANDLER_H
