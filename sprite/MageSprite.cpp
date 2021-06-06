//
// Created by niels on 06.06.21.
//

#include "MageSprite.h"


MageSprite::MageSprite() {
    this->animation = new MageAnimation();
}

void MageSprite::draw(Renderer renderer, SDL_Rect *pRect, SDL_Rect *clipRect, SDL_RendererFlip flip) {
    IMG_Init(IMG_INIT_PNG);
    SDL_Texture  * texture = animation->getNextAnimationImage(activeAnimation);
    SDL_Point p = {0,0};
    SDL_RenderCopyEx(renderer.sdlRenderer, texture, NULL, pRect, 0.0, &p, flip);
}

void MageSprite::resetAnimation() {
    this->animation->reset();
}

int MageSprite::getCurrentFrame() {
    return animation->getCurrentFrameNumber();
}