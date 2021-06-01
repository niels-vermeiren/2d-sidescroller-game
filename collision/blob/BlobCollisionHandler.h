//
// Created by niels on 6/1/21.
//

#ifndef INC_2DSIDESCROLLER_BLOBCOLLISIONHANDLER_H
#define INC_2DSIDESCROLLER_BLOBCOLLISIONHANDLER_H


#include "../../entity/EntityManager.h"
#include "../../entity/Entity.h"
#include "../../entity/BlobEnemy.h"

class BlobCollisionHandler {
public:
    virtual void handleCollision(BlobEnemy * blob, Entity * entity) = 0;
    virtual void handleCollisions(BlobEnemy * blob, const EntityManager * entities);
};


#endif //INC_2DSIDESCROLLER_BLOBCOLLISIONHANDLER_H
