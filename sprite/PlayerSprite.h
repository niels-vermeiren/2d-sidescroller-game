//
// Created by niels on 4/17/21.
//

#ifndef INC_2DSIDESCROLLER_PLAYERSPRITE_H
#define INC_2DSIDESCROLLER_PLAYERSPRITE_H

#include "AnimatedSprite.h"

class PlayerSprite : public AnimatedSprite {
public:
    PlayerSprite();
    void draw(Renderer renderer, SDL_Rect * pRect, SDL_Rect * clipRect, SDL_RendererFlip flip) override;
    void resetAnimation() override;
};


#endif //INC_2DSIDESCROLLER_PLAYERSPRITE_H
