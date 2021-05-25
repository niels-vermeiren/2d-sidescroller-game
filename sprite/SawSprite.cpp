//
// Created by niels on 5/12/21.
//

#include "SawSprite.h"

SawSprite::SawSprite() {
    this->angle = 0.0;
    this->surface = IMG_Load("/home/niels/Projects/2dSideScroller/resources/saw/saw.png");
}

void SawSprite::draw(Renderer renderer, SDL_Rect *eRect, SDL_Rect * clipRect, SDL_RendererFlip flip) {
    IMG_Init(IMG_INIT_PNG);
    texture = SDL_CreateTextureFromSurface(renderer.sdlRenderer,surface);
    SDL_Point p = {eRect->w/2, eRect->h/2};
    SDL_RenderCopyEx(renderer.sdlRenderer, texture, clipRect, eRect, angle, &p, flip);
    SDL_DestroyTexture(texture);
}

void SawSprite::update() {
    angle = angle + 2.0;
    if(angle == 360.0) angle = 0.0;
}
