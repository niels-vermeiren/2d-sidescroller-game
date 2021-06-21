//
// Created by niels on 11.06.21.
//

#ifndef INC_2DSIDESCROLLER_DECOMAPTEXTUREHOLDER_H
#define INC_2DSIDESCROLLER_DECOMAPTEXTUREHOLDER_H


#include <SDL2/SDL_render.h>
#include <vector>
#include <memory>
#include "../../game/Renderer.h"

class DecoMapTextureHolder {
public:

    DecoMapTextureHolder();
    virtual ~DecoMapTextureHolder();
    void load();
    void loadToTexture();
    SDL_Texture * getTextureWithIndex(int index);
private:
     std::vector<SDL_Texture *> decoSet;
     std::vector<SDL_Surface *> decoSurfaces;
};


#endif //INC_2DSIDESCROLLER_DECOMAPTEXTUREHOLDER_H
