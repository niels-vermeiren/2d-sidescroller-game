//
// Created by niels on 4/15/21.
//

#include <iostream>
#include "AnimationData.h"
#include "../game/Renderer.h"

AnimationData::AnimationData() = default;

AnimationData::AnimationData(std::string filePath, int totalFrames, int delay) {
    this->delay = delay;
    this->totalFrames = totalFrames;
    this->filePath = filePath;
}


AnimationData::AnimationData(std::string filePath, int totalFrames, int delay, bool repeat) : AnimationData(filePath, totalFrames, delay) {
    this->repeat = repeat;
}

SDL_Texture * AnimationData::getNextFrame() {
    tick++;
    if (tick % this->delay == 0) {
        this->currentFrame += 1;
        if (this->currentFrame == this->totalFrames) {
            if (repeat) this->currentFrame = 0;
            else this->currentFrame = totalFrames - 1;
        }
    }
    return images[currentFrame];
}

AnimationData::~AnimationData() {
    for(SDL_Surface* surface:surfaces) {
        SDL_FreeSurface(surface);
    }
    for(SDL_Texture * texture : images) {
        SDL_DestroyTexture(texture);
    }
}

void AnimationData::reset(int startFrame) {
    this->currentFrame = startFrame;
}

int AnimationData::getCurrentFrame() {
    return currentFrame;
}

void AnimationData::load() {
    for(int i = 0; i != totalFrames ; i++) {
        std::string filePathFrame = filePath + std::to_string(i + 1) + ".png";
        SDL_Surface *pSurface = IMG_Load(filePathFrame.c_str());
        this->surfaces.push_back(pSurface);
    }
}

void AnimationData::loadTextures() {
    for(int i = 0; i != totalFrames ; i++) {
        SDL_Texture *pTexture = SDL_CreateTextureFromSurface(Renderer::getInstance().sdlRenderer, this->surfaces[i]);
        images.push_back(pTexture);
    }

}

