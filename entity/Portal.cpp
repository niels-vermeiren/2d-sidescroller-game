//
// Created by niels on 21.06.21.
//

#include "Portal.h"

Portal::Portal(SDL_Rect *rect) {
    this->rect = rect;
    this->sprite = new PortalSprite();
}

void Portal::draw(Renderer renderer) {
    this->sprite->draw(renderer, this->rect, nullptr, SDL_FLIP_NONE);
}

PortalSprite *Portal::getSprite() const {
    return sprite;
}

Portal::~Portal() {
    delete this->sprite;
}
