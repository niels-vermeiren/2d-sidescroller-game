//
// Created by niels on 4/29/21.
//

#include "Saw.h"
#include "../defs.h"

Saw::Saw(SDL_Rect * rect) {
    this->rect = rect;
    this->sprite = new SawSprite();
}

void Saw::update() {
    this->sprite->update();
}

void Saw::draw(Renderer renderer) {
    if (shouldDraw) {
        sprite->draw(renderer, this->rect, NULL, SDL_FLIP_NONE);
    }
}
