//
// Created by niels on 4/17/21.
//

#include "PlayerSprite.h"

void PlayerSprite::draw(Renderer renderer, SDL_Rect *pRect,SDL_Rect *clipRect, SDL_RendererFlip flip) {
    SDL_Rect rect = {pRect->x-54, pRect->y-15, 150, 150};
    IMG_Init(IMG_INIT_PNG);
    SDL_Texture  * texture = animation->getNextAnimationImage(activeAnimation);
    SDL_Point p = {0,0};
    SDL_RenderCopyEx(renderer.sdlRenderer, texture, clipRect, &rect, 0.0, &p, flip);
}


PlayerSprite::PlayerSprite() {
    this->animation = new PlayerAnimation();
}

void PlayerSprite::resetAnimation() {
    this->animation->reset();
}
