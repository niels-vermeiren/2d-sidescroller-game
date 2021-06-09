//
// Created by niels on 5/14/21.
//

#include "SpikesSprite.h"

SpikesSprite::SpikesSprite() {
    this->surface = IMG_Load("../resources/spikes/spike.png");
    texture = SDL_CreateTextureFromSurface(Renderer::getInstance().sdlRenderer,surface);
}

void SpikesSprite::draw(Renderer renderer, SDL_Rect *eRect, SDL_Rect * clipRect, SDL_RendererFlip flip) {
    IMG_Init(IMG_INIT_PNG);
    SDL_Point p = {0,0};
    SDL_RenderCopyEx(renderer.sdlRenderer, texture, clipRect, eRect, 0.0, &p, flip);
}

SpikesSprite::~SpikesSprite() {
delete texture;
}
