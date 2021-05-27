//
// Created by niels on 4/15/21.
//

#include "AnimationData.h"
#include "../game/Renderer.h"

AnimationData::AnimationData() = default;

AnimationData::AnimationData(std::string filePath, int totalFrames, int delay) {
    this->delay = delay;
    this->totalFrames = totalFrames;

    for(int i = 0; i != totalFrames ; i++) {
        std::string filePathFrame = filePath + std::to_string(i + 1) + ".png";
        SDL_Surface *pSurface = IMG_Load(filePathFrame.c_str());
        Renderer &renderer = Renderer::getInstance();
        SDL_Texture *pTexture = SDL_CreateTextureFromSurface(renderer.sdlRenderer, pSurface);
        images.push_back(pTexture);
    }
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
    for(SDL_Texture * texture : images) {
        SDL_DestroyTexture(texture);
        delete texture;
    }
}

void AnimationData::reset() {
    this->currentFrame = 0;
}

