//
// Created by niels on 5/25/21.
//

#ifndef INC_2DSIDESCROLLER_COINSPRITE_H
#define INC_2DSIDESCROLLER_COINSPRITE_H


#include "AnimatedSprite.h"

class CoinSprite : AnimatedSprite {
public:
    CoinSprite();
    void load() override;
    void loadToTexture() override;
    void draw(Renderer renderer, SDL_Rect * cRect, SDL_Rect * clipRect, SDL_RendererFlip flip) override;
    void resetAnimation() override;
};


#endif //INC_2DSIDESCROLLER_COINSPRITE_H
