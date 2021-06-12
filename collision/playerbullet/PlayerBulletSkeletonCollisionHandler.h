//
// Created by niels on 10.06.21.
//

#ifndef INC_2DSIDESCROLLER_PLAYERBULLETSKELETONCOLLISIONHANDLER_H
#define INC_2DSIDESCROLLER_PLAYERBULLETSKELETONCOLLISIONHANDLER_H


#include "../player/PlayerCollisionHandler.h"
#include "PlayerBulletCollisionHandler.h"

class PlayerBulletSkeletonCollisionHandler : public PlayerBulletCollisionHandler {
public:
    virtual void handleCollision(Skeleton * skeleton, PlayerBullet * bullet) override;

};


#endif //INC_2DSIDESCROLLER_PLAYERBULLETSKELETONCOLLISIONHANDLER_H
