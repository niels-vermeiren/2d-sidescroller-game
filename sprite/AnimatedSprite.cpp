//
// Created by niels on 4/17/21.
//

#include "AnimatedSprite.h"

void AnimatedSprite::setActiveAnimation(int animation) {
    this->activeAnimation = animation;
}

int AnimatedSprite::getCurrentFrame() {
    return 0;
}

Animation *AnimatedSprite::getAnimation() const {
    return animation;
}
