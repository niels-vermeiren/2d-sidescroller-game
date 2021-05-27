//
// Created by niels on 5/25/21.
//

#ifndef INC_2DSIDESCROLLER_COINANIMATION_H
#define INC_2DSIDESCROLLER_COINANIMATION_H


#include "Animation.h"
#include "AnimationData.h"

class CoinAnimation : public Animation {
public:
    CoinAnimation();
    virtual ~CoinAnimation();
    SDL_Texture * getNextAnimationImage(int animation = 0) override;
    void reset() override;
private:
    AnimationData * animationData;
};


#endif //INC_2DSIDESCROLLER_COINANIMATION_H
