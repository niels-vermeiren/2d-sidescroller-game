//
// Created by niels on 6/1/21.
//

#ifndef INC_2DSIDESCROLLER_SKELETONSPRITE_H
#define INC_2DSIDESCROLLER_SKELETONSPRITE_H


#include "AnimatedSprite.h"
#include "../game/Renderer.h"

class SkeletonSprite : public AnimatedSprite {
public:
    SkeletonSprite();
    void load() override;
    void loadToTexture() override;
    void draw(Renderer renderer, SDL_Rect * pRect, SDL_Rect * clipRect, SDL_RendererFlip flip) override;
    void resetAnimation() override;
    int getCurrentFrame() override;
};


#endif //INC_2DSIDESCROLLER_SKELETONSPRITE_H
