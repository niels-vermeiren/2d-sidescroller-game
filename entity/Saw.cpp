//
// Created by niels on 4/29/21.
//

#include "Saw.h"
#include "../command/Command.h"
#include "../command/saw/SawMoveLeftCommand.h"
#include "../command/saw/SawMoveRightCommand.h"

Saw::Saw(SDL_Rect *rect, bool movingSaw) {
    this->rect = rect;
    this->sprite = new SawSprite();
    this->isMovingSaw =  movingSaw;
    this->movingLeft = true;
}

void Saw::update() {
    if(isMovingSaw) {
        Command * cmd;
        if(movingLeft) cmd = new SawMoveLeftCommand(this);
        else cmd = new SawMoveRightCommand(this);
        cmd->execute();
        this->rect->x += direction.x;
    }
    this->sprite->update();
}

void Saw::draw(Renderer renderer) {
    if (shouldDraw) {
        sprite->draw(renderer, this->rect, NULL, SDL_FLIP_NONE);
    }
}

bool Saw::isMovingLeft() const {
    return movingLeft;
}

void Saw::setMovingLeft(bool movingLeft) {
    Saw::movingLeft = movingLeft;
}

bool Saw::movingSaw() const {
    return isMovingSaw;
}
