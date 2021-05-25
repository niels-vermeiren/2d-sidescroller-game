//
// Created by niels on 4/10/21.
//

#include "Vector.h"

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


