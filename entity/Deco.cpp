//
// Created by niels on 11.06.21.
//

#include "Deco.h"
#include "../map/tilemap/DecoMapTextureHolder.h"
#include "../defs.h"

Deco::Deco(SDL_Rect *rect, int index) : Entity({0,0}, rect) {
    SDL_Texture * texture = DecoMapTextureHolder::getInstance().getTextureWithIndex(index);
    this->sprite = new DecoSprite(texture);
}

void Deco::draw(Renderer renderer) {
    if(shouldDraw)this->sprite->draw(renderer, this->rect, nullptr, SDL_FLIP_NONE);
}

void Deco::updatePlayerPos(int playerX, int playerY) {
    this->shouldDraw= ((this->minX() > playerX - SCREEN_WIDTH/2 - 225 && minX()  < playerX + SCREEN_WIDTH/2 + 225
                        || playerX < SCREEN_WIDTH/2 && minX() < playerX + SCREEN_WIDTH) &&
                       (this->minY() > playerY - SCREEN_HEIGHT/2 - 50 && minY()  < playerY + SCREEN_HEIGHT/2 + 50
                        || playerY > LEVEL_HEIGHT - SCREEN_WIDTH/2 && minY() > playerY -  SCREEN_HEIGHT)) ||
                      (playerY > LEVEL_HEIGHT && ((this->minX() > playerX - SCREEN_WIDTH/2 - 100 && minX()  < playerX + SCREEN_WIDTH/2 + 100
                                                   || playerX < SCREEN_WIDTH/2 && minX() < playerX + SCREEN_WIDTH)));
}

