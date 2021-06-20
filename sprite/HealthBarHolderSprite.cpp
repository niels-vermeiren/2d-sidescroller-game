//
// Created by niels on 12.06.21.
//

#include "HealthBarHolderSprite.h"

HealthBarHolderSprite::HealthBarHolderSprite(bool background) {
    this->background = background;
}

void HealthBarHolderSprite::draw(Renderer renderer, SDL_Rect *pRect, SDL_Rect *clipRect, SDL_RendererFlip flip) {
    SDL_Point p = {0,0};
    SDL_RenderCopyEx(renderer.sdlRenderer, holder, clipRect, pRect, 0.0, &p, flip);
}

HealthBarHolderSprite::~HealthBarHolderSprite() {
    SDL_DestroyTexture(holder);
}

void HealthBarHolderSprite::loadToTexture() {
    this->holder = SDL_CreateTextureFromSurface(Renderer::getInstance().sdlRenderer,surface);
}

void HealthBarHolderSprite::load() {
    if(!background) {
        this->surface = IMG_Load("../resources/stats/health/health_bar_empty.png");
    } else {
        this->surface = IMG_Load("../resources/stats/health/health_bar_holder.png");
    }
}
