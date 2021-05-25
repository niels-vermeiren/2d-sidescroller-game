//
// Created by niels on 5/14/21.
//

#include "SpikesSprite.h"

SpikesSprite::SpikesSprite() {
    this->surface = IMG_Load("/home/niels/Projects/2dSideScroller/resources/spikes/spike.png");
}

void SpikesSprite::draw(Renderer renderer, SDL_Rect *eRect, SDL_Rect * clipRect, SDL_RendererFlip flip) {
    IMG_Init(IMG_INIT_PNG);

        texture = SDL_CreateTextureFromSurface(renderer.sdlRenderer,surface);

    SDL_Point p = {0,0};
    SDL_RenderCopyEx(renderer.sdlRenderer, texture, clipRect, eRect, 0.0, &p, flip);
    SDL_DestroyTexture(texture);
}

SpikesSprite::~SpikesSprite() {
delete texture;
}
