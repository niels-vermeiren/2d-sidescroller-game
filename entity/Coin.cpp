//
// Created by niels on 5/25/21.
//

#include "Coin.h"

Coin::Coin() {
    this->sprite = new CoinSprite();
    this->rect = new SDL_Rect {400, 600, 16, 16};
}

void Coin::update() {

}

void Coin::draw(Renderer renderer) {
    this->sprite->draw(renderer, rect, NULL, SDL_FLIP_NONE);
}

Coin::~Coin() {
    delete rect;
    delete sprite;
}
