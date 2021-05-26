//
// Created by niels on 5/25/21.
//

#include "CoinSprite.h"
#include "../animation/CoinAnimation.h"

void CoinSprite::draw(Renderer renderer, SDL_Rect *cRect, SDL_Rect *clipRect, SDL_RendererFlip flip) {
    SDL_Surface * surface = animation->getNextAnimationImage(activeAnimation);
    IMG_Init(IMG_INIT_PNG);
    SDL_Texture  * texture = SDL_CreateTextureFromSurface(renderer.sdlRenderer,surface);
    SDL_Point p = {0,0};
    SDL_RenderCopyEx(renderer.sdlRenderer, texture, clipRect, cRect, 0.0, &p, flip);
    SDL_DestroyTexture(texture);
}

void CoinSprite::resetAnimation() {
    animation->reset();
}

CoinSprite::CoinSprite() {
    this->animation = new CoinAnimation();
}
