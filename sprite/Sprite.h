//
// Created by niels on 4/12/21.
//

#ifndef INC_2DSIDESCROLLER_SPRITE_H
#define INC_2DSIDESCROLLER_SPRITE_H
#include <SDL2/SDL.h>
#include "../game/Renderer.h"
#include "../animation/AnimationData.h"
#include "../animation/PlayerAnimation.h"

class Sprite {
public:
    Sprite();
    virtual ~Sprite();
    virtual void load() = 0;
    virtual void loadToTexture() = 0;
    virtual void draw(Renderer renderer, SDL_Rect * srcRect, SDL_Rect * clipRect, SDL_RendererFlip flip) = 0;
    virtual void resetAnimation() {};
};


#endif //INC_2DSIDESCROLLER_SPRITE_H
