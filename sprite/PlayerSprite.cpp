//
// Created by niels on 4/17/21.
//

#include "PlayerSprite.h"
#include "../entity/collisionbox/PlayerCollisionBox.h"

void PlayerSprite::draw(Renderer renderer, SDL_Rect *pRect,SDL_Rect *clipRect, SDL_RendererFlip flip) {
    //SDL_Rect rect = {10, 400, 44, 127};

    IMG_Init(IMG_INIT_PNG);
    SDL_Texture  * texture = animation->getNextAnimationImage(activeAnimation);
    SDL_Point p = {0,0};
    SDL_SetRenderDrawColor( renderer.sdlRenderer, 0, 0, 255, 255 );
    SDL_RenderCopyEx(renderer.sdlRenderer, texture, clipRect, pRect, 0.0, &p, flip);

    SDL_SetRenderDrawColor(renderer.sdlRenderer, 255, 0,0,255);
    SDL_RenderDrawRect(renderer.sdlRenderer, pRect);
    PlayerCollisionBox box;
    SDL_SetRenderDrawColor(renderer.sdlRenderer, 255, 0,0,255);
    SDL_RenderDrawRect(renderer.sdlRenderer, box.getCollisionBox(pRect));

}


PlayerSprite::PlayerSprite() {
    this->animation = new PlayerAnimation();
}

void PlayerSprite::resetAnimation() {
    this->animation->reset();
}
