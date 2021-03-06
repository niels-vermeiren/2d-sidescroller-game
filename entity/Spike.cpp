//
// Created by niels on 5/14/21.
//

#include "Spike.h"
#include "../defs.h"

Spike::Spike(SDL_Rect * rect) {
    this->sprite = new SpikesSprite();
    this->rect = rect;
}

void Spike::draw(Renderer renderer) {
    if(!shouldDraw) return;
    sprite->draw(renderer, rect, NULL, SDL_FLIP_NONE);
}

void Spike::update() {

}

SpikesSprite *Spike::getSprite() const {
    return sprite;
}
