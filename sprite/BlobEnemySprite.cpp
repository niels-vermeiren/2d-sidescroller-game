//
// Created by niels on 6/1/21.
//

#include "BlobEnemySprite.h"
#include "../animation/BlobEnemyAnimation.h"

BlobEnemySprite::BlobEnemySprite() {
    this->animation = new BlobEnemyAnimation();
}

void BlobEnemySprite::draw(Renderer renderer, SDL_Rect *pRect, SDL_Rect *clipRect, SDL_RendererFlip flip) {
    IMG_Init(IMG_INIT_PNG);
    SDL_Texture  * texture = animation->getNextAnimationImage(activeAnimation);
    SDL_Point p = {0,0};
    SDL_RenderCopyEx(renderer.sdlRenderer, texture, clipRect, pRect, 0.0, &p, flip);
}

void BlobEnemySprite::resetAnimation() {
    this->animation->reset();
}
