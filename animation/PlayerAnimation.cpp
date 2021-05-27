//
// Created by niels on 4/14/21.
//

#include "PlayerAnimation.h"
#include "AnimationData.h"

PlayerAnimation::PlayerAnimation() : Animation() {
    //Idle
    auto * idleData = new AnimationData("/home/niels/Projects/2dSideScroller/resources/idle/idle", 1, 16);
    this->animationData.push_back(idleData);
    //Walking
    auto * walkingData = new AnimationData("/home/niels/Projects/2dSideScroller/resources/run/run", 14, 3);
    this->animationData.push_back(walkingData);
    //Jump
    auto * jumpData = new AnimationData("/home/niels/Projects/2dSideScroller/resources/jump/jump", 5, 8);
    this->animationData.push_back(jumpData);
    //Crouch
    auto * crouchData = new AnimationData("/home/niels/Projects/2dSideScroller/resources/crouch/crouch", 1, 1);
    this->animationData.push_back(crouchData);
    //Crouch-walking
    auto * crouchWalkingData = new AnimationData("/home/niels/Projects/2dSideScroller/resources/crouch/crouch_walk", 6, 8);
    this->animationData.push_back(crouchWalkingData);
    //Ground-attack
    auto * groundAttackData = new AnimationData("/home/niels/Projects/2dSideScroller/resources/attack/attack", 9, 2);
    this->animationData.push_back(groundAttackData);
    //Air-attack
    auto * airAttackData = new AnimationData("/home/niels/Projects/2dSideScroller/resources/jump-attack/jump_attack", 6, 3);
    this->animationData.push_back(airAttackData);
    //Dead
    auto * deadData = new AnimationData("/home/niels/Projects/2dSideScroller/resources/dead/dead", 5, 8, false);
    this->animationData.push_back(deadData);
    //Air-attack
    auto * hurtData = new AnimationData("/home/niels/Projects/2dSideScroller/resources/hurt/hurt", 1, 1);
    this->animationData.push_back(hurtData);
}

SDL_Texture * PlayerAnimation::getNextAnimationImage(int animation) {
    return this->animationData[animation]->getNextFrame();
}

PlayerAnimation::~PlayerAnimation() {
    for(AnimationData * data: animationData) {
        delete data;
    }
}

void PlayerAnimation::reset() {
    this->animationData[DEAD]->reset();
}
