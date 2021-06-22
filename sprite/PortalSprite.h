//
// Created by niels on 21.06.21.
//

#ifndef INC_2DSIDESCROLLER_PORTALSPRITE_H
#define INC_2DSIDESCROLLER_PORTALSPRITE_H


#include "AnimatedSprite.h"

class PortalSprite : AnimatedSprite {
public:
    PortalSprite();
    void load() override;
    void loadToTexture() override;
    void draw(Renderer renderer, SDL_Rect * cRect, SDL_Rect * clipRect, SDL_RendererFlip flip) override;
    void resetAnimation() override;
private:
    double angle = 0;
};


#endif //INC_2DSIDESCROLLER_PORTALSPRITE_H
