//
// Created by niels on 11.06.21.
//

#include "DecoSprite.h"

DecoSprite::DecoSprite(SDL_Texture *texture) {
   this->texture = texture;
}

SDL_Point DecoSprite::getsize(SDL_Texture * sdlTexture) {
    SDL_Point size;
    SDL_QueryTexture(sdlTexture, nullptr, nullptr, &size.x, &size.y);
    return size;
}

DecoSprite::~DecoSprite() {
    SDL_DestroyTexture(texture);
}

void DecoSprite::draw(Renderer renderer, SDL_Rect *pRect, SDL_Rect *clipRect, SDL_RendererFlip flip) {
    IMG_Init(IMG_INIT_PNG);
    SDL_Point p = {0,0};
    SDL_Point dimensions = getsize(texture);
    auto * position = new SDL_Rect {pRect->x, pRect->y + 64 - dimensions.y, dimensions.x, dimensions.y};
    SDL_RenderCopyEx(renderer.sdlRenderer, texture, clipRect, position, 0.0, &p, flip);
}
