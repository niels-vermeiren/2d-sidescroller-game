//
// Created by niels on 12.06.21.
//

#include "HealthBarStrokeSprite.h"

HealthBarStrokeSprite::HealthBarStrokeSprite() {
    SDL_FreeSurface(surface);
}

void HealthBarStrokeSprite::draw(Renderer renderer, SDL_Rect *pRect, SDL_Rect *clipRect, SDL_RendererFlip flip) {
    SDL_Point p = {0,0};
    SDL_RenderCopyEx(renderer.sdlRenderer, stroke, clipRect, pRect, 0.0, &p, flip);
}

HealthBarStrokeSprite::~HealthBarStrokeSprite() {
    SDL_DestroyTexture(stroke);
}

void HealthBarStrokeSprite::load() {
    this->surface = IMG_Load("../resources/stats/health/health_bar_stroke.png");
}

void HealthBarStrokeSprite::loadToTexture() {
    this->stroke = SDL_CreateTextureFromSurface(Renderer::getInstance().sdlRenderer, surface);
}
