//
// Created by niels on 08.06.21.
//

#ifndef INC_2DSIDESCROLLER_MAGEBULLETANIMATION_H
#define INC_2DSIDESCROLLER_MAGEBULLETANIMATION_H


#include "Animation.h"
#include "AnimationData.h"

class MageBulletAnimation : public Animation {
public:
    MageBulletAnimation();
    virtual ~MageBulletAnimation();
    SDL_Texture * getNextAnimationImage(int animation = 0) override;
    int getCurrentFrameNumber() override;
    void reset() override;
    void load() override;
    void loadToTexture() override;
private:
    AnimationData * animationData;
};


#endif //INC_2DSIDESCROLLER_MAGEBULLETANIMATION_H
