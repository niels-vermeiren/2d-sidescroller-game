//
// Created by niels on 4/17/21.
//

#include "StaticSprite.h"

StaticSprite::StaticSprite(SDL_Surface * surface) {
    this->surface = surface;
}

StaticSprite::StaticSprite() {

}


StaticSprite::~StaticSprite() {
    delete surface;
}
