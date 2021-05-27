//
// Created by niels on 5/25/21.
//

#include "Coin.h"

Coin::Coin(SDL_Rect * rect) {
    this->sprite = new CoinSprite();
    this->rect = rect;
}

void Coin::update() {

}

void Coin::draw(Renderer renderer) {
    if(!this->visible) return;
    this->sprite->draw(renderer, rect, NULL, SDL_FLIP_NONE);
}

Coin::~Coin() {
    delete rect;
    delete sprite;
}
