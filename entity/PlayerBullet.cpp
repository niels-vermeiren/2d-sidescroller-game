//
// Created by niels on 09.06.21.
//

#include "PlayerBullet.h"
#include "../defs.h"

PlayerBullet::PlayerBullet(SDL_Rect *rect, Vector direction, bool isFacingLeft) : Entity(direction, rect, isFacingLeft) {
    this->sprite = new PlayerBulletSprite();
}

void PlayerBullet::draw(Renderer renderer) {
    if(!shouldDraw || !this->visible) return;
    this->sprite->draw(renderer, rect, NULL, facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

void PlayerBullet::update() {
    this->rect->x += direction.x;
}

void PlayerBullet::updatePlayerPos(int playerX, int playerY) {
    this->shouldDraw = (this->minX() > playerX - SCREEN_WIDTH*2 && maxX() < playerX + SCREEN_WIDTH*2);
}

SDL_Rect *PlayerBullet::getCollisionBox() {
    return collisionBox.getCollisionBox(rect,facingLeft);
}

PlayerBulletSprite *PlayerBullet::getSprite() const {
    return sprite;
}


