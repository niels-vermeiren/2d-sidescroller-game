//
// Created by niels on 06.06.21.
//

#ifndef INC_2DSIDESCROLLER_MAGECOLLISIONHANDLER_H
#define INC_2DSIDESCROLLER_MAGECOLLISIONHANDLER_H


#include "../../entity/Mage.h"
#include "../../entity/Entity.h"
#include "../../entity/EntityManager.h"

class MageCollisionHandler {
public:
    virtual void handleCollision(Mage * mage, Entity * entity) = 0;
    virtual void handleCollisions(Mage * mage, const EntityManager * entities);
};


#endif //INC_2DSIDESCROLLER_MAGECOLLISIONHANDLER_H
