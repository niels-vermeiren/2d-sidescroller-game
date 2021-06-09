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
    this->sprite->draw(renderer, this->rect, this->clipRect, SDL_FLIP_NONE);
}


Platform::~Platform() {
    delete sprite;
}

void Platform::update() {

}

