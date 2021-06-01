//
// Created by niels on 4/11/21.
//

#ifndef INC_2DSIDESCROLLER_COLLISIONDETECTION_H
#define INC_2DSIDESCROLLER_COLLISIONDETECTION_H

#include "SDL2/SDL.h"
#include <vector>
#include "../math/Rotated_Rect.h"
#include "../math/Vector.h"
class CollisionDetection {
public:
    static bool rectanglesIntersect(SDL_Rect * r1, SDL_Rect * r2);
    static bool rectangleCircleIntersect(SDL_Rect * r, SDL_Rect * c);
    static bool rotatedRectanglesIntersect(Rotated_Rect * r1, Rotated_Rect * r2);
};


#endif //INC_2DSIDESCROLLER_COLLISIONDETECTION_H
