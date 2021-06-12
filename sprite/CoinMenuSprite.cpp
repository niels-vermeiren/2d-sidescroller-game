//
// Created by niels on 12.06.21.
//

#include "CoinMenuSprite.h"

CoinMenuSprite::~CoinMenuSprite() {
    SDL_DestroyTexture(holder);
}
CoinMenuSprite::CoinMenuSprite() {
    this->surface = IMG_Load("../resources/stats/coins/coin_menu.png");
    this->holder = SDL_CreateTextureFromSurface(Renderer::getInstance().sdlRenderer,surface);
    SDL_FreeSurface(surface);
}

void CoinMenuSprite::draw(Renderer renderer, SDL_Rect *pRect, SDL_Rect *clipRect, SDL_RendererFlip flip) {
    SDL_Point p = {0,0};
    SDL_RenderCopyEx(renderer.sdlRenderer, holder, clipRect, pRect, 0.0, &p, flip);
}