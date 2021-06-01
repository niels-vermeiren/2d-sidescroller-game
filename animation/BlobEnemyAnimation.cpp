//
// Created by niels on 6/1/21.
//

#include "BlobEnemyAnimation.h"

BlobEnemyAnimation::BlobEnemyAnimation() {
    //Idle
    auto * idleData = new AnimationData("/home/niels/Projects/2dSideScroller/resources/blob_enemy/idle/green_slime_idle", 1, 1);
    this->animationData.push_back(idleData);
    //Walking
    auto * walkingData = new AnimationData("/home/niels/Projects/2dSideScroller/resources/blob_enemy/walking/green_slime_walk", 4, 8);
    this->animationData.push_back(walkingData);
    //Jump
    auto * dyingData = new AnimationData("/home/niels/Projects/2dSideScroller/resources/blob_enemy/dying/green_slime_dead", 3, 8);
    this->animationData.push_back(dyingData);
}

BlobEnemyAnimation::~BlobEnemyAnimation() {
    for(AnimationData * data: animationData) {
        delete data;
    }
}

SDL_Texture *BlobEnemyAnimation::getNextAnimationImage(int animation) {
    return this->animationData[animation]->getNextFrame();
}

void BlobEnemyAnimation::reset() {
    this->animationData[DEAD]->reset();
}
