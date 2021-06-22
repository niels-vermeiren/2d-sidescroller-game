//
// Created by niels on 21.06.21.
//

#include "PortalAnimation.h"

PortalAnimation::PortalAnimation() {
    //Idle
    animationData = new AnimationData("../resources/portal/portal", 1, 2);
}

PortalAnimation::~PortalAnimation() {
    delete animationData;
}

SDL_Texture *PortalAnimation::getNextAnimationImage(int animation) {
    this->currentAnimation = animation;
    return this->animationData[animation].getNextFrame();
}

void PortalAnimation::reset() {
    animationData->reset(0);
}

int PortalAnimation::getCurrentFrameNumber() {
    return this->animationData[currentAnimation].getCurrentFrame();
}

void PortalAnimation::load() {
    animationData->load();
}

void PortalAnimation::loadToTexture() {
   animationData->loadTextures();
}