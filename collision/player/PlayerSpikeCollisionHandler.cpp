//
// Created by niels on 5/23/21.
//

#include "PlayerSpikeCollisionHandler.h"

void PlayerSpikeCollisionHandler::handleCollision(Player *p, Entity *entity) {
    //If player is located on top of wall and is falling down
    if(p->maxX() > entity->minX() && p->minX()  < entity->maxX()
       && p->maxY() <= entity->minY() + entity->getRect()->h
       && p->maxY() + p->getDirection().y > entity->minY() + entity->getRect()->h) {
        p->getRect()->y = entity->minY() + entity->getRect()->h - p->getRect()->h;
        if (p->getDirection().y > GRAVITY) {
            p->setState(new IsDeadState());
        }
        p->getDirection().y = 0;
    }
}
