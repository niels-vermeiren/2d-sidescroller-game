//
// Created by niels on 09.06.21.
//

#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(SDL_Rect *rect, Vector direction) : Entity(direction, rect) {
    this->rect = rect;
    this->sprite = new PlayerBulletSprite();
    this->visible = true;
}

void PlayerBullet::draw(Renderer renderer) {
    if(!shouldDraw) return;
    this->sprite->draw(renderer, rect, NULL, facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

bool PlayerBullet::isFacingLeft() const {
    return facingLeft;
}

void PlayerBullet::setFacingLeft(bool facingLeft) {
   this->facingLeft = facingLeft;
}

void PlayerBullet::update() {
    this->rect->x += direction.x;
}
