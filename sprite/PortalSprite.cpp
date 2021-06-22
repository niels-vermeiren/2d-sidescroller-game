//
// Created by niels on 21.06.21.
//

#include "PortalSprite.h"
#include "../animation/PortalAnimation.h"

PortalSprite::PortalSprite() {
    this->animation = new PortalAnimation();
}

void PortalSprite::load() {
    this->animation->load();
}

void PortalSprite::loadToTexture() {
    this->animation->loadToTexture();
}

void PortalSprite::draw(Renderer renderer, SDL_Rect *cRect, SDL_Rect *clipRect, SDL_RendererFlip flip) {
    angle-=0.4;
    IMG_Init(IMG_INIT_PNG);
    SDL_Texture  * texture = animation->getNextAnimationImage(activeAnimation);
    SDL_Point p = {cRect->w/2,cRect->h/2};
    SDL_RenderCopyEx(renderer.sdlRenderer, texture, clipRect, cRect, angle, &p, flip);
}

void PortalSprite::resetAnimation() {
    Sprite::resetAnimation();
}
