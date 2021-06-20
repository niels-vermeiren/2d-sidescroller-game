//
// Created by niels on 08.06.21.
//

#include "MageBulletAnimation.h"

MageBulletAnimation::MageBulletAnimation() {
    animationData = new AnimationData("../resources/mage/bullet/flame", 50, 1);
}

SDL_Texture *MageBulletAnimation::getNextAnimationImage(int animation) {
    currentAnimation = animation;
    return animationData->getNextFrame();
}

void MageBulletAnimation::reset() {
    this->animationData->reset(0);
}

int MageBulletAnimation::getCurrentFrameNumber() {
    return this->animationData[currentAnimation].getCurrentFrame();
}

MageBulletAnimation::~MageBulletAnimation() {
    delete animationData;
}

void MageBulletAnimation::load() {
    this->animationData->load();
}

void MageBulletAnimation::loadToTexture() {
    this->animationData->loadTextures();
}
