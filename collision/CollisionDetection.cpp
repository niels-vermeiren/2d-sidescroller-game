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

    return (cornerDistance_sq <= pow(radius, 2));
}

bool CollisionDetection::rotatedRectanglesIntersect(Rotated_Rect *r1, Rotated_Rect *r2) {
    /*//Separating Axis Theorem
    std::vector<Vector> axis;
    //Calculate axis' parallel to edges, 2 per rectangle, because 2 sides are parallel
    //Normalize to unit vector
    axis.push_back(r1->getAxis1().normalize());
    axis.push_back(r1->getAxis2().normalize());
    axis.push_back(r2->getAxis1().normalize());
    axis.push_back(r2->getAxis2().normalize());

    for(Vector &v : axis) {
        //Project all points of rectangle onto vector v using dot product, get min and max for each rectangle
        float minR1 = std::min(std::min(v.dot(r1->getP1())
                , v.dot(r1->getP2())),std::min(v.dot(r1->getP3())
                , v.dot(r1->getP4())));

        float maxR1 = std::max(std::max(v.dot(r1->getP1())
                , v.dot(r1->getP2())),std::max(v.dot(r1->getP3())
                , v.dot(r1->getP4())));

        float minR2 = std::min(std::min(v.dot(r2->getP1())
                , v.dot(r2->getP2())),std::min(v.dot(r2->getP3())
                , v.dot(r2->getP4())));

        float maxR2 = std::max(std::max(v.dot(r2->getP1())
                , v.dot(r2->getP2())),std::max(v.dot(r2->getP3())
                , v.dot(r2->getP4())));

        //If there is space on one of the axis' between the projected rectangles' min/max points,
        //then no collision is happening
        if((maxR1 < minR2) || (maxR2 < minR1)) return false;
    }
    //All projected points overlap on all axis', so there must be a collision
    return true;*/
}
