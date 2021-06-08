//
// Created by niels on 07.06.21.
//

#include "MageBullet.h"
#include "../defs.h"

void MageBullet::updatePlayerPos(int playerX, int playerY) {
    this->shouldDraw= (this->minX() > playerX - SCREEN_WIDTH/2 - this->rect->w && minX()  < playerX + SCREEN_WIDTH/2 + this->rect->w
                       || playerX < SCREEN_WIDTH/2 && minX() < playerX + SCREEN_WIDTH) &&
                      (this->minY() > playerY - SCREEN_HEIGHT/2 - this->rect->h && minY()  < playerY + SCREEN_HEIGHT/2 + this->rect->h
                       || playerY > LEVEL_HEIGHT - SCREEN_WIDTH/2 && minY() > playerY -  SCREEN_HEIGHT);
}

MageBullet::MageBullet(SDL_Rect *rect, Vector direction) : Entity(direction, rect){
    this->sprite = new MageBulletSprite();
    this->x = rect->x;
    this->y = rect->y;
}

void MageBullet::update() {
    this->x += direction.x;
    this->y += direction.y;
}

void MageBullet::draw(Renderer renderer) {
    this->rect->x = this->x;
    this->rect->y = this->y;
    //SDL_Rect * collisionBox = getCollisionBox();
    if(!this->shouldDraw  || !this->visible) return;;
    this->sprite->draw(renderer, this->rect, nullptr, SDL_FLIP_NONE);
    //drawCircle(renderer.sdlRenderer, collisionBox->x + collisionBox->w/2, collisionBox->y + collisionBox->h/2, collisionBox->w/2);
}

void MageBullet::drawCircle(SDL_Renderer *renderer, int32_t centreX, int32_t centreY, int32_t radius) {
    const int32_t diameter = (radius * 2);

    int32_t x = (radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);

    while (x >= y) {
        //  Each of the following renders an octant of the circle
        SDL_SetRenderDrawColor(renderer, 0, 255 ,0,255);
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

SDL_Rect *MageBullet::getCollisionBox() {
    return collisionBox.getCollisionBox(this->rect);
}
