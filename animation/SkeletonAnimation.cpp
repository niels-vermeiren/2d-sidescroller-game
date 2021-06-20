//
// Created by niels on 6/1/21.
//

#include "SkeletonAnimation.h"

SkeletonAnimation::SkeletonAnimation() {
    //Idle
    auto * idleData = new AnimationData("../resources/skeleton/idle/idle", 1, 1);
    this->animationData.push_back(idleData);
    //Walk
    auto * walkingData = new AnimationData("../resources/skeleton/walking/walk", 12, 4);
    this->animationData.push_back(walkingData);
    //Die
    auto * dyingData = new AnimationData("../resources/skeleton/dying/dead", 4, 8, false);
    this->animationData.push_back(dyingData);
    //Attack
    auto * attackData = new AnimationData("../resources/skeleton/attack/attack", 8, 4);
    this->animationData.push_back(attackData);
}

SkeletonAnimation::~SkeletonAnimation() {
    for(AnimationData * data: animationData) {
        delete data;
    }
}

SDL_Texture *SkeletonAnimation::getNextAnimationImage(int animation) {
    this->currentAnimation = animation;
    return this->animationData[animation]->getNextFrame();
}

void SkeletonAnimation::reset() {
    this->animationData[DEAD]->reset(0);
    this->animationData[ATTACK]->reset(0);
}

int SkeletonAnimation::getCurrentFrameNumber() {
    return this->animationData[currentAnimation]->getCurrentFrame();
}

void SkeletonAnimation::load() {
    for(AnimationData * data: animationData) {
        data->load();
    }
}

void SkeletonAnimation::loadToTexture() {
    for(AnimationData * data: animationData) {
        data->loadTextures();
    }
}
