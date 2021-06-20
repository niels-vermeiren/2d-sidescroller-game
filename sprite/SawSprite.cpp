//
// Created by niels on 5/12/21.
//

#include "SawSprite.h"

SawSprite::SawSprite() {
    this->angle = 0.0;
}

void SawSprite::draw(Renderer renderer, SDL_Rect *eRect, SDL_Rect * clipRect, SDL_RendererFlip flip) {
    IMG_Init(IMG_INIT_PNG);
    SDL_Point p = {eRect->w/2, eRect->h/2};
    SDL_RenderCopyEx(renderer.sdlRenderer, this->texture, clipRect, eRect, angle, &p, flip);
}

void SawSprite::update() {
    angle = angle + 2.0;
    if(angle == 360.0) angle = 0.0;
}

void SawSprite::load() {
    this->surface = IMG_Load("../resources/saw/saw.png");
}

void SawSprite::loadToTexture() {
    this->texture = SDL_CreateTextureFromSurface(Renderer::getInstance().sdlRenderer,surface);
}
