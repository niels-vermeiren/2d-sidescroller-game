//
// Created by niels on 08.06.21.
//

#ifndef INC_2DSIDESCROLLER_PLAYERMAGEBULLETCOLLISIONHANDLER_H
#define INC_2DSIDESCROLLER_PLAYERMAGEBULLETCOLLISIONHANDLER_H


#include "PlayerCollisionHandler.h"
#include "../../entity/MageBullet.h"

class PlayerMageBulletCollisionHandler  : public PlayerCollisionHandler {
public:
    void handleCollision(Player * p, Entity * entity) override;

};


#endif //INC_2DSIDESCROLLER_PLAYERMAGEBULLETCOLLISIONHANDLER_H
