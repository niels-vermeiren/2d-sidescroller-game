//
// Created by niels on 4/17/21.
//

#ifndef INC_2DSIDESCROLLER_STATICSPRITE_H
#define INC_2DSIDESCROLLER_STATICSPRITE_H


#include <string>
#include "Sprite.h"

class StaticSprite : public Sprite{
public:
    StaticSprite();
    explicit StaticSprite(SDL_Surface * surface);
    virtual ~StaticSprite();
protected:
    SDL_Surface * surface;
};


#endif //INC_2DSIDESCROLLER_STATICSPRITE_H
