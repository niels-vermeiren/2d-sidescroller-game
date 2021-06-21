//
// Created by niels on 11.06.21.
//

#include "DecoSprite.h"
#include "../map/tilemap/DecoMapTextureHolder.h"

DecoSprite::DecoSprite(int index) {
    this->index = index;
}

SDL_Point DecoSprite::getsize(SDL_Texture * sdlTexture) {
    SDL_Point size;
    SDL_QueryTexture(sdlTexture, nullptr, nullptr, &size.x, &size.y);
    return size;
}

DecoSprite::~DecoSprite() {
}

void DecoSprite::draw(Renderer renderer, SDL_Rect *pRect, SDL_Rect *clipRect, SDL_RendererFlip flip) {
    IMG_Init(IMG_INIT_PNG);
    SDL_Point p = {0,0};
    SDL_Point dimensions = getsize(texture);
    int xVal = pRect->x;
    if(dimensions.x <= 64) {
        xVal = pRect->x-dimensions.x/2 +32;
    } else {
        xVal = pRect->x;
    }
    auto * position = new SDL_Rect {xVal, pRect->y + 64 - dimensions.y, dimensions.x, dimensions.y};
    SDL_RenderCopyEx(renderer.sdlRenderer, texture, clipRect, position, 0.0, &p, flip);
}

void DecoSprite::loadToTexture() {
    this->holder.loadToTexture();
    this->texture = holder.getTextureWithIndex(index);
}

void DecoSprite::load() {
   this->holder.load();
}
