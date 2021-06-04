//
// Created by niels on 6/1/21.
//

#include "SkeletonSprite.h"
#include "../animation/SkeletonAnimation.h"

SkeletonSprite::SkeletonSprite() {
    this->animation = new SkeletonAnimation();
}

void SkeletonSprite::draw(Renderer renderer, SDL_Rect *pRect, SDL_Rect *clipRect, SDL_RendererFlip flip) {
    IMG_Init(IMG_INIT_PNG);
    SDL_Texture  * texture = animation->getNextAnimationImage(activeAnimation);
    SDL_Point p = {0,0};
    SDL_RenderCopyEx(renderer.sdlRenderer, texture, NULL, pRect, 0.0, &p, flip);
}

void SkeletonSprite::resetAnimation() {
    this->animation->reset();
}
