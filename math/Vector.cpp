//
// Created by niels on 4/10/21.
//

#include <cmath>
#include "Vector.h"
#include <SDL2/SDL.h>

Vector::Vector() {}

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
    return std::sqrt((x * x) + (y * y));
}

void Vector::normalize()  {
    float l = length();
    this->x = x/l;
    this->y = y/l;
}

float Vector::dot(Vector &v) const {
    return x * v.x + y * v.y;
}

float Vector::dot(const SDL_Point &p) const {
    return x * p.x + y * p.y;
}

void Vector::scalarMultiplication(float factor) {
    this->x *= factor;
    this->y *= factor;
}

void Vector::multiply(float factorX, float factorY) {
    this->x *= factorX;
    this->y *= factorY;
}


