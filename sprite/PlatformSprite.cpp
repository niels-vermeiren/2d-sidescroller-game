//
// Created by niels on 4/17/21.
//

#include "PlatformSprite.h"
#include "../map/tilemap/TilesetTextureHolder.h"

PlatformSprite::PlatformSprite() {
    this->holder = &TilesetTextureHolder::getInstance();
}

void PlatformSprite::draw(Renderer renderer, SDL_Rect *pRect, SDL_Rect *clipRect, SDL_RendererFlip flip) {
    IMG_Init(IMG_INIT_PNG);
    SDL_Point p = {0,0};
    SDL_Texture *pTexture = holder->getTilesetTexture();
    SDL_RenderCopyEx(renderer.sdlRenderer, pTexture, clipRect, pRect, 0.0, &p, flip);
}

void PlatformSprite::load() {
    this->holder->load();
}

void PlatformSprite::loadToTexture() {
    this->holder->loadToTexture();
}
