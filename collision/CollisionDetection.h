//
// Created by niels on 4/11/21.
//

#ifndef INC_2DSIDESCROLLER_COLLISIONDETECTION_H
#define INC_2DSIDESCROLLER_COLLISIONDETECTION_H

#include "SDL2/SDL.h"

class CollisionDetection {
public:
    static bool rectanglesIntersect(SDL_Rect * r1, SDL_Rect * r2);
    static bool rectangleCircleIntersect(SDL_Rect * r, SDL_Rect * c);
};


#endif //INC_2DSIDESCROLLER_COLLISIONDETECTION_H
