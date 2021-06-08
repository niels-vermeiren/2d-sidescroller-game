//
// Created by niels on 07.06.21.
//

#include "MageBullet.h"
#include "../defs.h"

void MageBullet::updatePlayerPos(int playerX, int playerY) {
    this->shouldDraw= (this->minX() > playerX - SCREEN_WIDTH/2 - this->rect->w && minX()  < playerX + SCREEN_WIDTH/2 + this->rect->w
                       || playerX < SCREEN_WIDTH/2 && minX() < playerX + SCREEN_WIDTH) &&
                      (this->minY() > playerY - SCREEN_HEIGHT/2 - this->rect->h && minY()  < playerY + SCREEN_HEIGHT/2 + this->rect->h
                       || playerY > LEVEL_HEIGHT - SCREEN_WIDTH/2 && minY() > playerY -  SCREEN_HEIGHT);
}

MageBullet::MageBullet(SDL_Rect *rect, Vector direction) {
    this->rect = rect;
    this->direction = direction;
    this->sprite = new MageBulletSprite();
    this->x = rect->x;
    this->y = rect->y;
}

void MageBullet::update() {
    this->x += direction.x;
    this->y += direction.y;
}

void MageBullet::draw(Renderer renderer) {
    this->rect->x = this->x;
    this->rect->y = this->y;
    this->sprite->draw(renderer, this->rect, nullptr, SDL_FLIP_NONE);
}
