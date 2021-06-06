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
}

SDL_Texture *MageAnimation::getNextAnimationImage(int animation) {
    return this->animationData[animation]->getNextFrame();
}

int MageAnimation::getCurrentFrameNumber() {
    return this->animationData[currentAnimation]->getCurrentFrame();
}

void MageAnimation::reset() {

}

MageAnimation::~MageAnimation() {
    for(AnimationData * data: animationData) {
        delete data;
    }
}
