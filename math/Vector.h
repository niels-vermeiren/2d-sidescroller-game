//
// Created by niels on 4/10/21.
//

#ifndef INC_2DSIDESCROLLER_VECTOR_H
#define INC_2DSIDESCROLLER_VECTOR_H

#include <SDL2/SDL.h>
class Vector {

public:
    float x;
    float y;
    Vector() {}
    Vector(float x, float y);
    float length() const;
    void normalize();
    void scalarMultiplication(float factor);
    void multiply(float factorX, float factorY);
    float dot(Vector &v) const;
    float dot(const SDL_Point &p) const;
    Vector operator+ (const Vector &v) const;
    Vector operator- (const Vector &v) const;

};


#endif //INC_2DSIDESCROLLER_VECTOR_H
