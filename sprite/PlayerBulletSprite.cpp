//
// Created by niels on 09.06.21.
//

#include "PlayerBulletSprite.h"

PlayerBulletSprite::PlayerBulletSprite() {
}

void PlayerBulletSprite::draw(Renderer renderer, SDL_Rect *pRect, SDL_Rect *clipRect, SDL_RendererFlip flip) {
    IMG_Init(IMG_INIT_PNG);
    SDL_Point p = {0,0};
    SDL_RenderCopyEx(renderer.sdlRenderer, texture, clipRect, pRect, 0.0, &p, flip);
}

PlayerBulletSprite::~PlayerBulletSprite() {
}

void PlayerBulletSprite::load() {
    this->surface = IMG_Load("../resources/heroblue/gunbullet/bullet.png");
}

void PlayerBulletSprite::loadToTexture() {
    texture = SDL_CreateTextureFromSurface(Renderer::getInstance().sdlRenderer,surface);
}
