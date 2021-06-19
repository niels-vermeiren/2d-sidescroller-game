//
// Created by niels on 19.06.21.
//

#include "MovingSawAI.h"

MovingSawAI::MovingSawAI(Saw *saw, EntityManager *walls) {
    this->saw = saw;

    //Get wall under mage
    for(Entity * entity : walls->getEntities()) {
        SDL_Point * sawCentre = new SDL_Point {saw->getRect()->x + saw->getRect()->w/2, saw->getRect()->y + saw->getRect()->h/2};
        bool wallIsSurroundingSaw = sawCentre->y <= entity->maxY() &&sawCentre->y >= entity->minY()
                            && sawCentre->x >= entity->minX() && sawCentre->x <= entity->maxX();

        if(wallIsSurroundingSaw) {
            this->wall = entity;
            break;
        }
    }
}

void MovingSawAI::update() {
    //Don't fall off of platform, turn around
    SDL_Point * sawCentre = new SDL_Point {saw->minX() + saw->getRect()->w/2, saw->minY() + saw->getRect()->h/2};
    if(sawCentre->x + saw->getDirection().x <= wall->minX()) {
        saw->setMovingLeft(false);
    }
    if(sawCentre->x + saw->getDirection().x >= wall->maxX()) {
        saw->setMovingLeft(true);
    }
}
