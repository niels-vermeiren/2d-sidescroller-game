//
// Created by niels on 4/17/21.
//

#include "PlatformSprite.h"
#include "../map/tilemap/TilesetTextureHolder.h"

PlatformSprite::PlatformSprite() {

}

void PlatformSprite::draw(Renderer renderer, SDL_Rect *pRect, SDL_Rect *clipRect, SDL_RendererFlip flip) {
    IMG_Init(IMG_INIT_PNG);
    SDL_Point p = {0,0};
    TilesetTextureHolder textureHolder = TilesetTextureHolder::getInstance(&renderer);
    SDL_Texture *pTexture = textureHolder.getTilesetTexture();
    SDL_RenderCopyEx(renderer.sdlRenderer, pTexture, clipRect, pRect, 0.0, &p, flip);
}
