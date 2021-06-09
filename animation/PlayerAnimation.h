//
// Created by niels on 4/14/21.
//

#ifndef INC_2DSIDESCROLLER_PLAYERANIMATION_H
#define INC_2DSIDESCROLLER_PLAYERANIMATION_H

#include "AnimationData.h"
#include "Animation.h"
#include <vector>

class PlayerAnimation : public Animation {
public:
    PlayerAnimation();
    SDL_Texture * getNextAnimationImage(int animation = 0) override;
    int getCurrentFrameNumber() override;
    void reset() override;
    static const int IDLE = 0;
    static const int WALKING = 1;
    static const int JUMPING = 2;
    static const int CROUCHING = 3;
    static const int SLIDING = 4;
    static const int ATTACK = 5;
    static const int JUMP_ATTACK = 6;
    static const int DEAD = 7;
    static const int HURT = 8;
    static const int RUN_GUN = 9;

    virtual ~PlayerAnimation();

private:
    std::vector<AnimationData *> animationData;
};


#endif //INC_2DSIDESCROLLER_PLAYERANIMATION_H
