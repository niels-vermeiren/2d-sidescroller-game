//
// Created by niels on 06.06.21.
//

#ifndef INC_2DSIDESCROLLER_MAGEWALLCOLLISIONHANDLER_H
#define INC_2DSIDESCROLLER_MAGEWALLCOLLISIONHANDLER_H


#include "MageCollisionHandler.h"

class MageWallCollisionHandler : public MageCollisionHandler {
public:
    void handleCollision(Mage * mage, Entity * entity) override;

};


#endif //INC_2DSIDESCROLLER_MAGEWALLCOLLISIONHANDLER_H
