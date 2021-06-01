//
// Created by niels on 5/31/21.
//

#include "Rotated_Rect.h"

Rotated_Rect::Rotated_Rect(SDL_Point p1, SDL_Point p2, SDL_Point p3, SDL_Point p4) {
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
    this->p4 = p4;
}

const SDL_Point &Rotated_Rect::getP1() const {
    return p1;
}

void Rotated_Rect::setP1(const SDL_Point &p1) {
    Rotated_Rect::p1 = p1;
}

const SDL_Point &Rotated_Rect::getP2() const {
    return p2;
}

void Rotated_Rect::setP2(const SDL_Point &p2) {
    Rotated_Rect::p2 = p2;
}

const SDL_Point &Rotated_Rect::getP3() const {
    return p3;
}

void Rotated_Rect::setP3(const SDL_Point &p3) {
    Rotated_Rect::p3 = p3;
}

const SDL_Point &Rotated_Rect::getP4() const {
    return p4;
}

void Rotated_Rect::setP4(const SDL_Point &p4) {
    Rotated_Rect::p4 = p4;
}
