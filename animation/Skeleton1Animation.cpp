//
// Created by niels on 6/1/21.
//

#include "Skeleton1Animation.h"

Skeleton1Animation::Skeleton1Animation() {
    //Idle
    auto * idleData = new AnimationData("/home/niels/Projects/2dSideScroller/resources/skeleton_1/idle/idle", 1, 1);
    this->animationData.push_back(idleData);
    //Walk
    auto * walkingData = new AnimationData("/home/niels/Projects/2dSideScroller/resources/skeleton_1/walking/walk", 12, 4);
    this->animationData.push_back(walkingData);
    //Die
    auto * dyingData = new AnimationData("/home/niels/Projects/2dSideScroller/resources/skeleton_1/dying/dead", 4, 8, false);
    this->animationData.push_back(dyingData);
    //Attack
    auto * attackData = new AnimationData("/home/niels/Projects/2dSideScroller/resources/skeleton_1/attack/attack", 8, 4);
    this->animationData.push_back(attackData);
}

Skeleton1Animation::~Skeleton1Animation() {
    for(AnimationData * data: animationData) {
        delete data;
    }
}

SDL_Texture *Skeleton1Animation::getNextAnimationImage(int animation) {
    return this->animationData[animation]->getNextFrame();
}

void Skeleton1Animation::reset() {
    this->animationData[DEAD]->reset(0);
}
