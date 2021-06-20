//
// Created by niels on 06.06.21.
//

#ifndef INC_2DSIDESCROLLER_MAGESPRITE_H
#define INC_2DSIDESCROLLER_MAGESPRITE_H


#include "AnimatedSprite.h"
#include "../animation/MageAnimation.h"
class MageSprite : public AnimatedSprite {
public:
    MageSprite();
    void load() override;
    void loadToTexture() override;
    void draw(Renderer renderer, SDL_Rect * pRect, SDL_Rect * clipRect, SDL_RendererFlip flip) override;
    void resetAnimation() override;
    int getCurrentFrame() override;

};


#endif //INC_2DSIDESCROLLER_MAGESPRITE_H
