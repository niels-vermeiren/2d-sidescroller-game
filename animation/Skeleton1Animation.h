//
// Created by niels on 6/1/21.
//

#ifndef INC_2DSIDESCROLLER_SKELETON1ANIMATION_H
#define INC_2DSIDESCROLLER_SKELETON1ANIMATION_H
#include "SDL2/SDL_image.h"
#include "AnimationData.h"
#include "Animation.h"

class Skeleton1Animation : public Animation{
public:
    Skeleton1Animation();
    virtual ~Skeleton1Animation();
    SDL_Texture * getNextAnimationImage(int animation = 0) override;
    void reset() override;

    static const int IDLE = 0;
    static const int WALKING = 1;
    static const int DEAD = 2;
    static const int ATTACK = 3;
private:
    std::vector<AnimationData *> animationData;
};


#endif //INC_2DSIDESCROLLER_SKELETON1ANIMATION_H
