//
// Created by niels on 10.06.21.
//

#ifndef INC_2DSIDESCROLLER_PLAYERBULLETCOLLISIONHANDLER_H
#define INC_2DSIDESCROLLER_PLAYERBULLETCOLLISIONHANDLER_H


#include "../../entity/PlayerBullet.h"
#include "../../entity/Entity.h"
#include "../../entity/EntityManager.h"
#include "../../entity/Skeleton.h"
#include "../../entity/Mage.h"
#include "../../entity/Player.h"

class PlayerBulletCollisionHandler  {
public:
    virtual void handleCollision(Skeleton * skeleton, PlayerBullet * bullet) { };
    virtual void handleCollisions(Skeleton * skeleton, const EntityManager * entities);
    virtual void handleCollision(Mage * mage, PlayerBullet * bullet) {};
    virtual void handleCollisions(Mage * mage, const EntityManager * entities);
    virtual void handleCollisions(EntityManager * tileset, Player * p) {};
};


#endif //INC_2DSIDESCROLLER_PLAYERBULLETCOLLISIONHANDLER_H
