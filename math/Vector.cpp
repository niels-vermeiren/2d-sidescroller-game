//
// Created by niels on 4/10/21.
//

#include <cmath>
#include "Vector.h"
#include <SDL2/SDL.h>
Vector::Vector(float x, float y) {
    this->x = x;
    this->y = y;
}

Vector Vector::operator+(const Vector &v) const {
    return {this->x + v.x, this->y + v.y};
}

Vector Vector::operator-(const Vector &v) const {
    return {this->x - v.x, this->y - v.y};
}

float Vector::length() const {
    return std::sqrt(x * x + y * y);
}

Vector Vector::normalize() const {
    return Vector(x/length(), y/length());
}

float Vector::dot(Vector &v) const {
    return x * v.x + y * v.y;
}

float Vector::dot(const SDL_Point &p) const {
    return x * p.x + y * p.y;
}


