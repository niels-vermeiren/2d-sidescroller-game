//
// Created by niels on 5/25/21.
//

#include "CoinSprite.h"
#include "../animation/CoinAnimation.h"

void CoinSprite::draw(Renderer renderer, SDL_Rect *cRect, SDL_Rect *clipRect, SDL_RendererFlip flip) {
    IMG_Init(IMG_INIT_PNG);
    SDL_Texture  * texture = animation->getNextAnimationImage(activeAnimation);
    SDL_Point p = {0,0};
    SDL_RenderCopyEx(renderer.sdlRenderer, texture, clipRect, cRect, 0.0, &p, flip);
}

void CoinSprite::resetAnimation() {
    animation->reset();
}

CoinSprite::CoinSprite() {
    this->animation = new CoinAnimation();
}

void CoinSprite::load() {
    this->animation->load();
}

void CoinSprite::loadToTexture() {
    this->animation->loadToTexture();
}
