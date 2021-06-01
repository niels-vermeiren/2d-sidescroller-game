//
// Created by niels on 5/31/21.
//

#ifndef INC_2DSIDESCROLLER_ROTATED_RECT_H
#define INC_2DSIDESCROLLER_ROTATED_RECT_H


#include <SDL2/SDL.h>
#include "../math/Vector.h"

class Rotated_Rect {
public:
    Rotated_Rect(SDL_Point p1, SDL_Point p2, SDL_Point p3, SDL_Point p4);
    SDL_Point p1;
    SDL_Point p2;
    SDL_Point p3;
    SDL_Point p4;

    const Vector getAxis1() const {
        return {(float)p2.x - p1.x, (float)p2.y - p1.y};
    };

    const Vector getAxis2 () const{
        return {(float)p3.x - p2.x, (float)p3.y - p2.y};
    };

    const SDL_Point &getP1() const;

    void setP1(const SDL_Point &p1);

    const SDL_Point &getP2() const;

    void setP2(const SDL_Point &p2);

    const SDL_Point &getP3() const;

    void setP3(const SDL_Point &p3);

    const SDL_Point &getP4() const;

    void setP4(const SDL_Point &p4);
};


#endif //INC_2DSIDESCROLLER_ROTATED_RECT_H
