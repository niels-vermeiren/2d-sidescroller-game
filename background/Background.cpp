//
// Created by niels on 4/20/21.
//

#include "Background.h"

void Background::draw(Renderer renderer) {
    SDL_RenderSetViewport(renderer.sdlRenderer, vp);
    if(this->bgTexture == nullptr) this->bgTexture = SDL_CreateTextureFromSurface(renderer.sdlRenderer, this->surface);
    SDL_RenderCopy(renderer.sdlRenderer, this->bgTexture, NULL, bgRect);
}

Background::Background() {
    this->surface = IMG_Load("../resources/BG2-small.jpg");
    this->bgTexture = nullptr;
    this->playerPos = new SDL_Rect();
    this->bgRect = new SDL_Rect();
    this->vp = new SDL_Rect ();
}

Background::~Background() {
    delete this->playerPos;
    SDL_DestroyTexture(this->bgTexture);
    SDL_FreeSurface(surface);
}

void Background::updatePlayerPos(int playerX, int playerY) {
    this->playerPos->x = playerX;
    this->playerPos->y = playerY;
    int vpX = 0, vpY = 0;

    if(playerPos->x > SCREEN_WIDTH/2-playerPos->w/2) vpX = -playerPos->x + SCREEN_WIDTH/2 - playerPos->w/2;
    if(playerPos->y < LEVEL_HEIGHT-SCREEN_HEIGHT/2-playerPos->h/2) vpY = -playerPos->y + SCREEN_HEIGHT/2 - playerPos->h/2;
    else vpY = -LEVEL_HEIGHT + SCREEN_HEIGHT ;
    vp = new SDL_Rect {vpX, vpY, WORDL_WIDTH, LEVEL_HEIGHT};
    bgRect = new SDL_Rect{-vpX,LEVEL_HEIGHT - SCREEN_HEIGHT, BACKGROUND_WIDTH, SCREEN_HEIGHT};
}

SDL_Rect *Background::getVpRect() const {
    return vp;
}

Background &Background::getInstance() {
    static Background INSTANCE;
    return INSTANCE;
}
