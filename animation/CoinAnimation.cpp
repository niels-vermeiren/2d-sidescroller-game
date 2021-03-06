//
// Created by niels on 5/25/21.
//

#include "CoinAnimation.h"

CoinAnimation::CoinAnimation() {
    animationData = new AnimationData("../resources/coin/coin", 4, 10);
}

SDL_Texture *CoinAnimation::getNextAnimationImage(int animation) {
    currentAnimation = animation;
    return animationData->getNextFrame();
}

CoinAnimation::~CoinAnimation() {
    delete animationData;
}

void CoinAnimation::reset() {
    this->animationData->reset(0);
}

int CoinAnimation::getCurrentFrameNumber() {
    return this->animationData[currentAnimation].getCurrentFrame();
}

void CoinAnimation::load() {
    this->animationData->load();
}

void CoinAnimation::loadToTexture() {
    this->animationData->loadTextures();
}
