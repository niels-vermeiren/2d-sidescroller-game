//
// Created by niels on 4/15/21.
//

#ifndef INC_2DSIDESCROLLER_ANIMATION_H
#define INC_2DSIDESCROLLER_ANIMATION_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Animation {
public:
    virtual SDL_Surface * getNextAnimationImage(int animation = 0) = 0;
    virtual void reset() = 0;
};

#endif //INC_2DSIDESCROLLER_ANIMATION_H
