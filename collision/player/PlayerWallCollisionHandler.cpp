//
// Created by niels on 5/23/21.
//

#include "PlayerWallCollisionHandler.h"

void PlayerWallCollisionHandler::handleCollision(Player *p, Entity *entity) {
    //If player is located on top of wall and is falling in it
    if(p->maxX() > entity->minX() && p->minX()  < entity->maxX()
       && p->maxY() <= entity->minY()
       && p->maxY() + p->getDirection().y > entity->minY()) {
        p->getRect()->y = entity->minY() - p->getRect()->h;
        if (p->getDirection().y > GRAVITY && p->getState()->getState() != HURTING
            && p->getState()->getState() != DYING) p->setState(new OnGroundState());
        p->getDirection().y = 0;
    }
    //If p is located on the left of the entity, and moving against it
    if(p->minY() < entity->maxY() && p->maxY() > entity->minY() &&
       p->maxX() - p->getDirection().x <= entity->minX() && p->maxX()  > entity->minX()) {
        p->getRect()->x = entity->minX() - p->getRect()->w;
    }
    //If p is located on the right of the entity, and moving against it
    if(p->minY() < entity->maxY() && p->maxY() > entity->minY() &&
       p->minX() - p->getDirection().x >= entity->maxX() && p->minX() < entity->maxX()) {
        p->getRect()->x = entity->maxX();
    }
}
