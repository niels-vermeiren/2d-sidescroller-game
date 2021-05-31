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

void Spike::updatePlayerPos(int playerX, int playerY) {
    this->shouldDraw= (this->minX() > playerX - SCREEN_WIDTH/2 - this->rect->w && minX()  < playerX + SCREEN_WIDTH/2 + this->rect->w
                       || playerX < SCREEN_WIDTH/2 && minX() < playerX + SCREEN_WIDTH) &&
                      (this->minY() > playerY - SCREEN_HEIGHT/2 - this->rect->h && minY()  < playerY + SCREEN_HEIGHT/2 + this->rect->h
                       || playerY > LEVEL_HEIGHT - SCREEN_WIDTH/2 && minY() > playerY -  SCREEN_HEIGHT);
}
