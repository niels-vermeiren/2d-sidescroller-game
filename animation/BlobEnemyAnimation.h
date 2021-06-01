//
// Created by niels on 6/1/21.
//

#ifndef INC_2DSIDESCROLLER_BLOBENEMYANIMATION_H
#define INC_2DSIDESCROLLER_BLOBENEMYANIMATION_H
#include "SDL2/SDL_image.h"
#include "AnimationData.h"
#include "Animation.h"

class BlobEnemyAnimation : public Animation{
public:
    BlobEnemyAnimation();
    virtual ~BlobEnemyAnimation();
    SDL_Texture * getNextAnimationImage(int animation = 0) override;
    void reset() override;

    static const int IDLE = 0;
    static const int WALKING = 1;
    static const int DEAD = 2;
private:
    std::vector<AnimationData *> animationData;
};


#endif //INC_2DSIDESCROLLER_BLOBENEMYANIMATION_H
