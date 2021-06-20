//
// Created by niels on 06.06.21.
//

#include "MageAnimation.h"

MageAnimation::MageAnimation() {
    //IDLE
    auto * idleData = new AnimationData("../resources/mage/idle/idle", 12, 4);
    this->animationData.push_back(idleData);
    //WALK
    auto * walkData = new AnimationData("../resources/mage/walk/walk", 8, 4);
    this->animationData.push_back(walkData);
    //DIE
    auto * dieData = new AnimationData("../resources/mage/die/die", 12, 4, false);
    this->animationData.push_back(dieData);
    //DIE
    auto * attackData = new AnimationData("../resources/mage/attack/attack", 7, 8, false);
    this->animationData.push_back(attackData);
}

SDL_Texture *MageAnimation::getNextAnimationImage(int animation) {
    this->currentAnimation = animation;
    return this->animationData[animation]->getNextFrame();
}

int MageAnimation::getCurrentFrameNumber() {
    return this->animationData[currentAnimation]->getCurrentFrame();
}

void MageAnimation::reset() {
    this->animationData[ATTACK]->reset(0);
    this->animationData[DIE]->reset(0);
}

MageAnimation::~MageAnimation() {
    for(AnimationData * data: animationData) {
        delete data;
    }
}

void MageAnimation::load() {
    for(AnimationData * data: animationData) {
        data->load();
    }
}

void MageAnimation::loadToTexture() {
    for(AnimationData * data: animationData) {
        data->loadTextures();
    }
}
