//
// Created by niels on 22.06.21.
//

#ifndef INC_2DSIDESCROLLER_PORTALCOLLISIONHANDLER_H
#define INC_2DSIDESCROLLER_PORTALCOLLISIONHANDLER_H


#include "../../entity/Player.h"

class PortalCollisionHandler {
public:
    virtual void handleCollision(Player* player, Entity * portal) = 0;
    virtual void handleCollisions(Player * skeleton, const EntityManager * entities);
};


#endif //INC_2DSIDESCROLLER_PORTALCOLLISIONHANDLER_H
