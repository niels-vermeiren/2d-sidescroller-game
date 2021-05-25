//
// Created by niels on 4/15/21.
//

#include "AnimationData.h"

AnimationData::AnimationData() = default;

AnimationData::AnimationData(std::string filePath, int totalFrames, int delay) {
    this->delay = delay;
    this->totalFrames = totalFrames;

    for(int i = 0; i != totalFrames ; i++) {
        std::string filePathFrame = filePath + std::to_string(i + 1) + ".png";
        images.push_back(IMG_Load(filePathFrame.c_str()));
    }
}

AnimationData::AnimationData(std::string filePath, int totalFrames, int delay, bool repeat) : AnimationData(filePath, totalFrames, delay) {
    this->repeat = repeat;
}

SDL_Surface * AnimationData::getNextFrame() {
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
    for(SDL_Surface * surface : images) {
        SDL_FreeSurface(surface);
        delete surface;
    }
}

void AnimationData::reset() {
    this->currentFrame = 0;
}

