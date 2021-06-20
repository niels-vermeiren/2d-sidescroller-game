//
// Created by niels on 4/17/21.
//

#include "TilesetTextureHolder.h"

TilesetTextureHolder::TilesetTextureHolder() {
}

SDL_Texture * TilesetTextureHolder::getTilesetTexture() {
    return tilesetTexture;
}

TilesetTextureHolder &TilesetTextureHolder::getInstance() {
    static TilesetTextureHolder INSTANCE;
    return INSTANCE;
}

void TilesetTextureHolder::load() {
    tilesetSurface = IMG_Load("../resources/tiles/tileset.png");
}

void TilesetTextureHolder::loadToTexture() {
    tilesetTexture = SDL_CreateTextureFromSurface(Renderer::getInstance().sdlRenderer, tilesetSurface);
}
