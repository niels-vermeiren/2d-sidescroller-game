//
// Created by niels on 4/14/21.
//

#include <iostream>
#include "PlayerAnimation.h"
#include "AnimationData.h"

PlayerAnimation::PlayerAnimation() : Animation() {
    //Idle
    auto * idleData = new AnimationData("../resources/heroblue/idle/idle", 12, 6);
    this->animationData.push_back(idleData);
    //Walking
    auto * walkingData = new AnimationData("../resources/heroblue/run/run", 10, 4);
    this->animationData.push_back(walkingData);
    //Jump
    auto * jumpData = new AnimationData("../resources/heroblue/jump/jump", 5, 8, false);
    this->animationData.push_back(jumpData);
    //Crouch
    auto * crouchData = new AnimationData("../resources/heroblue/slide/slide", 1, 1);
    this->animationData.push_back(crouchData);
    //Crouch-walking
    auto * crouchWalkingData = new AnimationData("../resources/heroblue/slide/slide", 4, 8);
    this->animationData.push_back(crouchWalkingData);
    //Ground-attack
    auto * groundAttackData = new AnimationData("../resources/heroblue/attack/attack", 6, 4);
    this->animationData.push_back(groundAttackData);
    //Air-attack
    auto * airAttackData = new AnimationData("../resources/heroblue/jump-attack/jump_attack", 6, 3);
    this->animationData.push_back(airAttackData);
    //Dead
    auto * deadData = new AnimationData("../resources/heroblue/dead/dead", 7, 8, false);
    this->animationData.push_back(deadData);
    //Air-attack
    auto * hurtData = new AnimationData("../resources/heroblue/hurt/hurt", 4, 8);
    this->animationData.push_back(hurtData);
    //Run with gun
    auto * gunData = new AnimationData("../resources/heroblue/runwithgun/rungun", 10, 4);
    this->animationData.push_back(gunData);
    //Idle with gun
    auto * idleGunData = new AnimationData("../resources/heroblue/idlegun/idlegun", 1, 1);
    this->animationData.push_back(idleGunData);
    //Jump
    auto * jumpGunData = new AnimationData("../resources/heroblue/jump_gun/jump", 4, 8, false);
    this->animationData.push_back(jumpGunData);
}

SDL_Texture * PlayerAnimation::getNextAnimationImage(int animation) {
    currentAnimation = animation;
    return this->animationData[animation]->getNextFrame();
}

PlayerAnimation::~PlayerAnimation() {
    for(AnimationData * data: animationData) {
        delete data;
    }
}

void PlayerAnimation::reset() {
    this->animationData[DEAD]->reset(0);
    this->animationData[JUMPING]->reset(1);
    this->animationData[JUMP_GUN]->reset(0);
    this->animationData[ATTACK]->reset(0);
}

int PlayerAnimation::getCurrentFrameNumber() {
    return this->animationData[currentAnimation]->getCurrentFrame();
}

void PlayerAnimation::load() {
    for(AnimationData * data: animationData) {
        data->load();
    }
}

void PlayerAnimation::loadToTexture() {
    for(AnimationData * data: animationData) {
        data->loadTextures();
    }
}
