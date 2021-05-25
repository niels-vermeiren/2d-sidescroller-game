//
// Created by niels on 4/15/21.
//

#ifndef INC_2DSIDESCROLLER_ANIMATION_H
#define INC_2DSIDESCROLLER_ANIMATION_H

class Animation {
public:
    virtual SDL_Surface * getNextAnimationImage(int animation) = 0;
    virtual void reset() = 0;
};

#endif //INC_2DSIDESCROLLER_ANIMATION_H
