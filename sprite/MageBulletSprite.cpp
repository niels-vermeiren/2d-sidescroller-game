//
// Created by niels on 07.06.21.
//

#include "MageBulletSprite.h"
#include "../animation/MageBulletAnimation.h"

MageBulletSprite::MageBulletSprite() {
    this->animation = new MageBulletAnimation();
}

void MageBulletSprite::draw(Renderer renderer, SDL_Rect *eRect, SDL_Rect * clipRect, SDL_RendererFlip flip) {
    IMG_Init(IMG_INIT_PNG);
    SDL_Point p = {0,0};
    SDL_Texture * frame = animation->getNextAnimationImage();
    SDL_RenderCopyEx(renderer.sdlRenderer, frame, clipRect, eRect, 0.0, &p, flip);
}
MageBulletSprite::~MageBulletSprite() {

}

void MageBulletSprite::load() {
    this->animation->load();
}

void MageBulletSprite::loadToTexture() {
    this->animation->loadToTexture();
}
