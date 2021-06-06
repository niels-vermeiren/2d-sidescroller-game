//
// Created by niels on 5/23/21.
//

#include "PlayerSpikeCollisionHandler.h"

void PlayerSpikeCollisionHandler::handleCollision(Player *p, Entity *entity) {
    SDL_Rect * pCollisionBox = p->getCollisionBox();

    bool playerBetweenBoundsSpike = pCollisionBox->x + pCollisionBox->w > entity->minX() && pCollisionBox->x  < entity->maxX();
    bool playerFallsOnBottomSpike = pCollisionBox->y + pCollisionBox->h <= entity->minY() + entity->getRect()->h
                                    && pCollisionBox->y + pCollisionBox->h + p->getDirection().y > entity->minY() + entity->getRect()->h;

    //Player falls on spikes
    if(playerBetweenBoundsSpike && playerFallsOnBottomSpike) {
        if (p->getDirection().y > GRAVITY) {
            p->setState(new IsDeadState());
        }
        p->getDirection().y = 0;
    }
}
