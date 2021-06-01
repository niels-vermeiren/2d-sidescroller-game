//
// Created by niels on 6/1/21.
//

#ifndef INC_2DSIDESCROLLER_BLOBWALLCOLLISIONHANDLER_H
#define INC_2DSIDESCROLLER_BLOBWALLCOLLISIONHANDLER_H


#include "BlobCollisionHandler.h"

class BlobWallCollisionHandler : public BlobCollisionHandler {
public:
    void handleCollision(BlobEnemy * blob, Entity * entity) override;

};


#endif //INC_2DSIDESCROLLER_BLOBWALLCOLLISIONHANDLER_H
