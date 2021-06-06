//
// Created by niels on 06.06.21.
//

#ifndef INC_2DSIDESCROLLER_MAGEANIMATION_H
#define INC_2DSIDESCROLLER_MAGEANIMATION_H


#include "Animation.h"
#include "AnimationData.h"

class MageAnimation : public Animation{
public:
    MageAnimation();
    virtual ~MageAnimation();
    SDL_Texture * getNextAnimationImage(int animation = 0) override;
    int getCurrentFrameNumber() override;
    void reset() override;

    static const int IDLE = 0;
    static const int WALK = 1;
    static const int DIE = 2;

private:
    std::vector<AnimationData *> animationData;

};


#endif //INC_2DSIDESCROLLER_MAGEANIMATION_H
