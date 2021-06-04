//
// Created by niels on 6/1/21.
//

#include "SkeletonAnimation.h"

SkeletonAnimation::SkeletonAnimation() {
    //Idle
    auto * idleData = new AnimationData("/home/niels/Projects/2dSideScroller/resources/skeleton/idle/idle", 1, 1);
    this->animationData.push_back(idleData);
    //Walk
    auto * walkingData = new AnimationData("/home/niels/Projects/2dSideScroller/resources/skeleton/walking/walk", 12, 4);
    this->animationData.push_back(walkingData);
    //Die
    auto * dyingData = new AnimationData("/home/niels/Projects/2dSideScroller/resources/skeleton/dying/dead", 4, 8, false);
    this->animationData.push_back(dyingData);
    //Attack
    auto * attackData = new AnimationData("/home/niels/Projects/2dSideScroller/resources/skeleton/attack/attack", 8, 4);
    this->animationData.push_back(attackData);
}

SkeletonAnimation::~SkeletonAnimation() {
    for(AnimationData * data: animationData) {
        delete data;
    }
}

SDL_Texture *SkeletonAnimation::getNextAnimationImage(int animation) {
    return this->animationData[animation]->getNextFrame();
}

void SkeletonAnimation::reset() {
    this->animationData[DEAD]->reset(0);
    this->animationData[ATTACK]->reset(0);
}
