//
// Created by niels on 6/1/21.
//

#include "Skeleton1Sprite.h"
#include "../animation/Skeleton1Animation.h"

Skeleton1Sprite::Skeleton1Sprite() {
    this->animation = new Skeleton1Animation();
}

void Skeleton1Sprite::draw(Renderer renderer, SDL_Rect *pRect, SDL_Rect *clipRect, SDL_RendererFlip flip) {
    IMG_Init(IMG_INIT_PNG);

    SDL_Texture  * texture = animation->getNextAnimationImage(activeAnimation);
    SDL_Point p = {0,0};

    SDL_RenderCopyEx(renderer.sdlRenderer, texture, NULL, pRect, 0.0, &p, flip);
}

void Skeleton1Sprite::resetAnimation() {
    this->animation->reset();
}
