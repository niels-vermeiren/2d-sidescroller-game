//
// Created by niels on 5/14/21.
//

#ifndef INC_2DSIDESCROLLER_SPIKESSPRITE_H
#define INC_2DSIDESCROLLER_SPIKESSPRITE_H


#include "StaticSprite.h"

class SpikesSprite : public StaticSprite {
public:
    SpikesSprite();
    ~SpikesSprite() override;
    void draw(Renderer renderer, SDL_Rect * pRect, SDL_Rect * clipRect, SDL_RendererFlip flip) override;

private:
    SDL_Texture * texture;

};


#endif //INC_2DSIDESCROLLER_SPIKESSPRITE_H
