//
// Created by niels on 4/17/21.
//

#ifndef INC_2DSIDESCROLLER_TILESETTEXTUREHOLDER_H
#define INC_2DSIDESCROLLER_TILESETTEXTUREHOLDER_H

#include <string>
#include <vector>
#include <unordered_map>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "../../game/Renderer.h"

class TilesetTextureHolder {
public:
    explicit TilesetTextureHolder();
    static TilesetTextureHolder& getInstance();
    SDL_Texture * getTilesetTexture();
    void load();
    void loadToTexture();
private:
    SDL_Surface * tilesetSurface;
    SDL_Texture * tilesetTexture;
};


#endif //INC_2DSIDESCROLLER_TILESETTEXTUREHOLDER_H
