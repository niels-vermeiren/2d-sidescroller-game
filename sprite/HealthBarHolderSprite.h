//
// Created by niels on 12.06.21.
//

#ifndef INC_2DSIDESCROLLER_HEALTHBARHOLDERSPRITE_H
#define INC_2DSIDESCROLLER_HEALTHBARHOLDERSPRITE_H


#include "StaticSprite.h"

class HealthBarHolderSprite : public StaticSprite {
public:
    HealthBarHolderSprite();
    ~HealthBarHolderSprite() override;
    void draw(Renderer renderer, SDL_Rect * pRect, SDL_Rect * clipRect, SDL_RendererFlip flip) override;

private:
    SDL_Texture * holder;
};


#endif //INC_2DSIDESCROLLER_HEALTHBARHOLDERSPRITE_H
