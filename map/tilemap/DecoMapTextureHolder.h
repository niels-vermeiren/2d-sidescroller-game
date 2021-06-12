//
// Created by niels on 11.06.21.
//

#ifndef INC_2DSIDESCROLLER_DECOMAPTEXTUREHOLDER_H
#define INC_2DSIDESCROLLER_DECOMAPTEXTUREHOLDER_H


#include <SDL2/SDL_render.h>
#include <vector>
#include "../../game/Renderer.h"

class DecoMapTextureHolder {
public:
    DecoMapTextureHolder();

    SDL_Texture * getTextureWithIndex(int index);
    static DecoMapTextureHolder & getInstance();
private:
    std::vector<SDL_Texture *> decoSet;
};


#endif //INC_2DSIDESCROLLER_DECOMAPTEXTUREHOLDER_H
