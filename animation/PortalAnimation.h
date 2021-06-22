//
// Created by niels on 21.06.21.
//

#ifndef INC_2DSIDESCROLLER_PORTALANIMATION_H
#define INC_2DSIDESCROLLER_PORTALANIMATION_H


#include <SDL2/SDL_render.h>
#include "../entity/Entity.h"
#include "AnimationData.h"
#include "Animation.h"

class PortalAnimation : public Animation {
public:
    PortalAnimation();
    virtual ~PortalAnimation();
    SDL_Texture * getNextAnimationImage(int animation = 0) override;
    void load() override;
    void loadToTexture() override;
    int getCurrentFrameNumber() override;
    void reset() override;
private:
    AnimationData * animationData;
};


#endif //INC_2DSIDESCROLLER_PORTALANIMATION_H
