//
// Created by niels on 12.06.21.
//

#ifndef INC_2DSIDESCROLLER_PLAYERBULLETTILESETCOLLISIONHANDLER_H
#define INC_2DSIDESCROLLER_PLAYERBULLETTILESETCOLLISIONHANDLER_H


#include "PlayerBulletCollisionHandler.h"
#include "../../entity/Player.h"

class PlayerBulletTilesetCollisionHandler : PlayerBulletCollisionHandler {
public:
    void handleCollisions(EntityManager * tileset, Player * player) override;;
};


#endif //INC_2DSIDESCROLLER_PLAYERBULLETTILESETCOLLISIONHANDLER_H
