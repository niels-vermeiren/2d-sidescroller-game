//
// Created by niels on 4/17/21.
//

#include "TilesetTextureHolder.h"

TilesetTextureHolder::TilesetTextureHolder(Renderer * renderer) {
    this->tilesetTexture =  SDL_CreateTextureFromSurface(renderer->sdlRenderer,
                     IMG_Load("../resources/tiles/tileset.png"));
}

SDL_Texture * TilesetTextureHolder::getTilesetTexture() {
    return tilesetTexture;
}

TilesetTextureHolder &TilesetTextureHolder::getInstance(Renderer *renderer) {
    static TilesetTextureHolder INSTANCE(renderer);
    return INSTANCE;
}
