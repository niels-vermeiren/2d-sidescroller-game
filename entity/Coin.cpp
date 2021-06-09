//
// Created by niels on 5/25/21.
//

#include "Coin.h"
#include "../defs.h"

Coin::Coin(SDL_Rect * rect) : Entity({0,0}, rect) {
    this->sprite = new CoinSprite();
    this->rect = rect;
}

void Coin::draw(Renderer renderer) {
    if(!this->visible || !this->shouldDraw) return;
    this->sprite->draw(renderer, rect, nullptr, SDL_FLIP_NONE);
}

Coin::~Coin() {
    delete rect;
    delete sprite;
}

