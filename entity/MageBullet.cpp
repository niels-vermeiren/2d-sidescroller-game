//
// Created by niels on 07.06.21.
//

#include "MageBullet.h"
#include "../defs.h"

void MageBullet::updatePlayerPos(int playerX, int playerY) {
    this->shouldDraw = (this->minX() > playerX - LEVEL_WIDTH / 2 && maxX() < playerX + LEVEL_WIDTH / 2) &&
                        (this->maxY() < LEVEL_HEIGHT && this->minY() > 0);
}
MageBullet::MageBullet(SDL_Rect *rect, Vector direction) : Entity(direction, rect){
    this->sprite = new MageBulletSprite();
    this->x = rect->x;
    this->y = rect->y;
    this->visible = true;
}

void MageBullet::update() {
    this->x += direction.x;
    this->y += direction.y;
}

void MageBullet::draw(Renderer renderer) {
    this->rect->x = this->x;
    this->rect->y = this->y;
    if(!this->shouldDraw  || !this->visible) return;;
    this->sprite->draw(renderer, this->rect, nullptr, SDL_FLIP_NONE);
}

SDL_Rect *MageBullet::getCollisionBox() {
    return collisionBox.getCollisionBox(this->rect);
}

MageBulletSprite *MageBullet::getSprite() const {
    return sprite;
}
