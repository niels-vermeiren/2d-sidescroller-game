//
// Created by niels on 4/20/21.
//

#include "Background.h"

void Background::draw(Renderer renderer) {
    int vpX = 0, vpY = 0;

    if(playerPos->x > SCREEN_WIDTH/2-playerPos->w/2) vpX = -playerPos->x + SCREEN_WIDTH/2 - playerPos->w/2;
    if(playerPos->y < LEVEL_HEIGHT-SCREEN_HEIGHT/2-playerPos->h/2) vpY = -playerPos->y + SCREEN_HEIGHT/2 - playerPos->h/2;
    else vpY = -LEVEL_HEIGHT/2 ;

    SDL_Rect vp = {vpX, vpY, LEVEL_WIDTH, LEVEL_HEIGHT};
    SDL_RenderSetViewport(renderer.sdlRenderer, &vp);

    if(this->bgTexture == nullptr) this->bgTexture = SDL_CreateTextureFromSurface(renderer.sdlRenderer, this->surface);

    SDL_Rect bgRect = {-vpX,LEVEL_HEIGHT - SCREEN_HEIGHT, 1008, SCREEN_HEIGHT};
    SDL_RenderCopy(renderer.sdlRenderer, this->bgTexture, NULL, &bgRect);
}

Background::Background() {
    this->surface = IMG_Load("/home/niels/Projects/2dSideScroller/resources/BG1.jpg");
    this->bgTexture = nullptr;
    this->playerPos = new SDL_Rect();
}

Background::~Background() {
    delete this->playerPos;
    SDL_DestroyTexture(this->bgTexture);
    SDL_FreeSurface(surface);
}

void Background::updatePlayerPos(int playerX, int playerY) {
    this->playerPos->x = playerX;
    this->playerPos->y = playerY;
}
