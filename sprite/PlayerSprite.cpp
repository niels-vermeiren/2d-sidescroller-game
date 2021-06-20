//
// Created by niels on 4/17/21.
//

#include "PlayerSprite.h"
#include "../entity/collisionbox/PlayerCollisionBox.h"

void PlayerSprite::draw(Renderer renderer, SDL_Rect *pRect,SDL_Rect *clipRect, SDL_RendererFlip flip) {

    IMG_Init(IMG_INIT_PNG);
    SDL_Texture  * texture = animation->getNextAnimationImage(activeAnimation);
    SDL_Point p = {0,0};
    SDL_SetRenderDrawColor( renderer.sdlRenderer, 0, 0, 255, 255 );
    SDL_RenderCopyEx(renderer.sdlRenderer, texture, clipRect, pRect, 0.0, &p, flip);
}


PlayerSprite::PlayerSprite() {
    this->animation = new PlayerAnimation();
}

void PlayerSprite::resetAnimation() {
    this->animation->reset();
}

void PlayerSprite::load() {
    this->animation->load();
}

void PlayerSprite::loadToTexture() {
    this->animation->loadToTexture();
}
