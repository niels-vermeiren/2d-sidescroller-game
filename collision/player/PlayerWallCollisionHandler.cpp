//
// Created by niels on 5/23/21.
//

#include "PlayerWallCollisionHandler.h"

void PlayerWallCollisionHandler::handleCollision(Player *p, Entity *entity) {
    SDL_Rect * pBounds = p->getRect();
    SDL_Rect * pCollisionBox = p->getCollisionBox();
    Vector * pDirection = &p->getDirection();
    PState pState = p->getState()->getState();

    bool playerBetweenBoundsWall = pCollisionBox->x + pCollisionBox->w > entity->minX() && pCollisionBox->x  < entity->maxX();

    //Player falls down on the wall
    if( playerBetweenBoundsWall && pCollisionBox->y + pCollisionBox->h < entity->minY() && pCollisionBox->y + pCollisionBox->h + pDirection->y >= entity->minY()) {
        pCollisionBox->y = entity->minY() - pCollisionBox->h;
        if (pDirection->y > GRAVITY && pState != HURTING && pState != DYING) p->setState(new OnGroundState());
        pDirection->y = 0;
    }

    bool playerOnSameHeightEntity = pCollisionBox->y < entity->maxY() && pCollisionBox->y + pCollisionBox->h > entity->minY();

    //Player collides with wall on the right
    if( playerOnSameHeightEntity && pCollisionBox->x + pCollisionBox->w - pDirection->x <= entity->minX() && pCollisionBox->x + pCollisionBox->w  > entity->minX()) {
        pBounds->x = entity->minX() - pBounds->w + ((pBounds->w - pCollisionBox->w)/2) - 1;
    }

    //Player collides with wall on the left
    if(playerOnSameHeightEntity && pCollisionBox->x - pDirection->x >= entity->maxX() && pCollisionBox->x < entity->maxX()) {
        pBounds->x = entity->maxX() - ((pBounds->w - pCollisionBox->w)/2);
    }
}
