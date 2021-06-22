//
// Created by niels on 22.06.21.
//

#ifndef INC_2DSIDESCROLLER_PLAYERPORTALCOLLISIONHANDLER_H
#define INC_2DSIDESCROLLER_PLAYERPORTALCOLLISIONHANDLER_H


#include "../../entity/Player.h"
#include "PortalCollisionHandler.h"

class PlayerPortalCollisionHandler : public PortalCollisionHandler {
public:
    void handleCollision(Player * player, Entity * entity) override;

};


#endif //INC_2DSIDESCROLLER_PLAYERPORTALCOLLISIONHANDLER_H
