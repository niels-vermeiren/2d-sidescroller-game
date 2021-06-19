//
// Created by niels on 12.06.21.
//

#ifndef INC_2DSIDESCROLLER_COINMENUSPRITE_H
#define INC_2DSIDESCROLLER_COINMENUSPRITE_H


#include "StaticSprite.h"
#include "../game/LTexture.h"

class CoinMenuSprite : public StaticSprite {
public:
    CoinMenuSprite();
    ~CoinMenuSprite() override;
    void draw(Renderer renderer, SDL_Rect * pRect, SDL_Rect * clipRect, SDL_RendererFlip flip) override;

private:
    SDL_Texture * holder;
    LTexture * lTexture;
};


#endif //INC_2DSIDESCROLLER_COINMENUSPRITE_H
