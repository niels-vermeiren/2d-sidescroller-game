//
// Created by niels on 5/25/21.
//

#include "CoinAnimation.h"

CoinAnimation::CoinAnimation() {
    animationData = new AnimationData("/home/niels/Projects/2dSideScroller/resources/coin/coin", 4, 10);
}

SDL_Texture *CoinAnimation::getNextAnimationImage(int animation) {
    return animationData->getNextFrame();
}

CoinAnimation::~CoinAnimation() {
    delete animationData;
}

void CoinAnimation::reset() {
    this->animationData->reset(0);
}
