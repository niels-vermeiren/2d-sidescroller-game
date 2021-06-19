//
// Created by niels on 10.06.21.
//

#ifndef INC_2DSIDESCROLLER_PLAYERBULLETMAGECOLLISIONHANDLER_H
#define INC_2DSIDESCROLLER_PLAYERBULLETMAGECOLLISIONHANDLER_H


#include "../../entity/Mage.h"
#include "PlayerBulletCollisionHandler.h"

class PlayerBulletMageCollisionHandler : public PlayerBulletCollisionHandler {
public:
    void handleCollision(Mage * mage, PlayerBullet * bullet) override;

};


#endif //INC_2DSIDESCROLLER_PLAYERBULLETMAGECOLLISIONHANDLER_H
