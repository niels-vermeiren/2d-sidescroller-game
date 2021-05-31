//
// Created by niels on 4/11/21.
//

#include <iostream>
#include "Platform.h"

Platform::Platform(Vector direction, SDL_Rect * rect, SDL_Rect * clipRect) : Entity(direction, rect) {
    this->rect = rect;
    this->clipRect = clipRect;
    this->direction = direction;
    this->shouldDraw = true;
    this->sprite = new PlatformSprite();
}

void Platform::draw(Renderer renderer) {
    if(!shouldDraw) return;
    this->sprite->draw(renderer, this->rect, this->clipRect, SDL_FLIP_NONE);
}


Platform::~Platform() {
    delete sprite;
}

void Platform::update() {

}

void Platform::updatePlayerPos(int playerX, int playerY) {
    //If this platform lies between the visible screen
    this->shouldDraw= (this->minX() > playerX - SCREEN_WIDTH/2 - this->rect->w && minX()  < playerX + SCREEN_WIDTH/2 + this->rect->w
        || playerX < SCREEN_WIDTH/2 && minX() < playerX + SCREEN_WIDTH) &&
        (this->minY() > playerY - SCREEN_HEIGHT/2 - this->rect->h && minY()  < playerY + SCREEN_HEIGHT/2 + this->rect->h
        || playerY > LEVEL_HEIGHT - SCREEN_WIDTH/2 && minY() > playerY -  SCREEN_HEIGHT);
}
