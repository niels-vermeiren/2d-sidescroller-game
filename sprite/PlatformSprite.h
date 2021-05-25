//
// Created by niels on 4/17/21.
//

#ifndef INC_2DSIDESCROLLER_PLATFORMSPRITE_H
#define INC_2DSIDESCROLLER_PLATFORMSPRITE_H

#include "StaticSprite.h"

class PlatformSprite : public StaticSprite {
public:
    PlatformSprite();
    void draw(Renderer renderer, SDL_Rect * pRect, SDL_Rect * clipRect, SDL_RendererFlip flip) override;
};


#endif //INC_2DSIDESCROLLER_PLATFORMSPRITE_H
