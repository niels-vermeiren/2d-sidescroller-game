//
// Created by niels on 4/17/21.
//

#ifndef INC_2DSIDESCROLLER_ANIMATEDSPRITE_H
#define INC_2DSIDESCROLLER_ANIMATEDSPRITE_H
#include "Sprite.h"

class AnimatedSprite : public Sprite {
public:
    void setActiveAnimation(int animation);
    virtual int getCurrentFrame(){};
protected:
    int activeAnimation = 0;
    Animation * animation;
};


#endif //INC_2DSIDESCROLLER_ANIMATEDSPRITE_H
