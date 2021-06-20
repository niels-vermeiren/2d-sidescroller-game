//
// Created by niels on 5/14/21.
//

#include "SpikesSprite.h"

SpikesSprite::SpikesSprite() {

}

void SpikesSprite::draw(Renderer renderer, SDL_Rect *eRect, SDL_Rect * clipRect, SDL_RendererFlip flip) {
    SDL_Point p = {0,0};
    SDL_RenderCopyEx(renderer.sdlRenderer, texture, clipRect, eRect, 0.0, &p, flip);
}

SpikesSprite::~SpikesSprite() {
    SDL_DestroyTexture(texture);
}

void SpikesSprite::load() {
    this->surface = IMG_Load("../resources/spikes/spike.png");
}

void SpikesSprite::loadToTexture() {
    this->texture = SDL_CreateTextureFromSurface(Renderer::getInstance().sdlRenderer,this->surface);
}
