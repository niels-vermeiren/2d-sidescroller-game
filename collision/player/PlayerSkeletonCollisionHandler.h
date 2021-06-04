//
// Created by niels on 6/2/21.
//

#ifndef INC_2DSIDESCROLLER_PLAYERSKELETONCOLLISIONHANDLER_H
#define INC_2DSIDESCROLLER_PLAYERSKELETONCOLLISIONHANDLER_H


#include "PlayerCollisionHandler.h"

class PlayerSkeletonCollisionHandler : public PlayerCollisionHandler {
public:
    void handleCollision(Player * p, Skeleton * skeleton);

};


#endif //INC_2DSIDESCROLLER_PLAYERSKELETONCOLLISIONHANDLER_H
