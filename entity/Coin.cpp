//
// Created by niels on 5/25/21.
//

#include "Coin.h"
#include "../defs.h"

Coin::Coin(SDL_Rect * rect) {
    this->sprite = new CoinSprite();
    this->rect = rect;
}

void Coin::update() {

}

void Coin::draw(Renderer renderer) {
    if(!this->visible || !this->shouldDraw) return;
    this->sprite->draw(renderer, rect, NULL, SDL_FLIP_NONE);
}

Coin::~Coin() {
    delete rect;
    delete sprite;
}

void Coin::updatePlayerPos(int playerX, int playerY) {
    this->shouldDraw= (this->minX() > playerX - SCREEN_WIDTH/2 - this->rect->w && minX()  < playerX + SCREEN_WIDTH/2 + this->rect->w
                       || playerX < SCREEN_WIDTH/2 && minX() < playerX + SCREEN_WIDTH) &&
                      (this->minY() > playerY - SCREEN_HEIGHT/2 - this->rect->h && minY()  < playerY + SCREEN_HEIGHT/2 + this->rect->h
                       || playerY > LEVEL_HEIGHT - SCREEN_WIDTH/2 && minY() > playerY -  SCREEN_HEIGHT);
}
