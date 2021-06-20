//
// Created by niels on 4/17/21.
//

#ifndef INC_2DSIDESCROLLER_PLATFORMSPRITE_H
#define INC_2DSIDESCROLLER_PLATFORMSPRITE_H

#include "StaticSprite.h"
#include "../map/tilemap/TilesetTextureHolder.h"

class PlatformSprite : public StaticSprite {
public:
    PlatformSprite();
    void load() override;
    void loadToTexture() override;
    void draw(Renderer renderer, SDL_Rect * pRect, SDL_Rect * clipRect, SDL_RendererFlip flip) override;

private:
    TilesetTextureHolder * holder;
};


#endif //INC_2DSIDESCROLLER_PLATFORMSPRITE_H
