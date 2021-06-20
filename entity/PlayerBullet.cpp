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

void PlayerBullet::drawCircle(SDL_Renderer *renderer, int32_t centreX, int32_t centreY, int32_t radius) {
    const int32_t diameter = (radius * 2);

    int32_t x = (radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);

    while (x >= y) {
        //  Each of the following renders an octant of the circle
        SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
        SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
        SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
        SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
        SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

        if (error <= 0) {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0) {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}

PlayerBulletSprite *PlayerBullet::getSprite() const {
    return sprite;
}


