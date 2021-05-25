//
// Created by niels on 5/12/21.
//

#ifndef INC_2DSIDESCROLLER_SAWSPRITE_H
#define INC_2DSIDESCROLLER_SAWSPRITE_H

#include "StaticSprite.h"

class SawSprite : public StaticSprite {
public:
    SawSprite();
    void update();
    void draw(Renderer renderer, SDL_Rect * pRect, SDL_Rect * clipRect, SDL_RendererFlip flip) override;

private:
    double angle;
    SDL_Texture * texture;
};


#endif //INC_2DSIDESCROLLER_SAWSPRITE_H
