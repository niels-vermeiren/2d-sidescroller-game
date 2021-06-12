//
// Created by niels on 4/11/21.
//

#include "CollisionDetection.h"

bool CollisionDetection::rectanglesIntersect(SDL_Rect * r1, SDL_Rect * r2) {
    return !(r1->x + r1->w < r2->x || r1->y + r1->h < r2->y || r1->x > r2->x + r2->w || r1->y > r2->y + r2->h);
}

bool CollisionDetection::rectangleCircleIntersect(SDL_Rect * r, SDL_Rect * c) {
    double circleDistanceX = abs((c->x + c->w/2) - (r->x+r->w/2));
    double circleDistanceY = abs((c->y + c->h/2) - (r->y+r->h/2));
    double radius = c->w / 2;

    if (circleDistanceX > (r->w/2 + radius)) { return false; }
    if (circleDistanceY > (r->h/2 + radius)) { return false; }

    if (circleDistanceX <= (r->w/2)) { return true; }
    if (circleDistanceY <= (r->h/2)) { return true; }

    double cornerDistance_sq = pow((circleDistanceX - r->w/2), 2) +
                               pow((circleDistanceY - r->h/2),2);

    return cornerDistance_sq <= pow(radius, 2);
}
