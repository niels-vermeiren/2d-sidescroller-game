//
// Created by niels on 4/10/21.
//
#include "Player.h"
#include "../playerstate/JumpState.h"

Player::Player(Vector direction, SDL_Rect * rect) : FallingEntity(direction, rect) {
    this->sprite = new PlayerSprite();
    this->state = new JumpState();
    this->rect = new SDL_Rect();
    this->rect->h = rect->h;
    this->rect->w = rect->w;
    this->isFacingLeft = false;
}

void Player::update() {
    this->state->update(this);
    this->rect->x += (int) direction.x;
    this->rect->y += (int) direction.y;
    this->applyGravity();
    notifyObservers();
}

void Player::draw(Renderer renderer) {
    this->sprite->draw(renderer, rect, NULL, isFacingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}


Player::~Player() {
    delete sprite;
    delete state;
    delete rect;
}

AnimatedSprite * Player::getSprite() {
    return sprite;
}

void Player::setFacingLeft(bool facingLeft) {
    this->isFacingLeft = facingLeft;
}

void Player::notifyObservers() {
    for (auto * observer : observers) {
        observer->updatePlayerPos(minX() + rect->w / 2, minY() + rect->h / 2);
    }
}

void Player::setState(PlayerState * state) {
    this->state = state;
}

void Player::reset() {
    this->rect->x = 10;
    this->rect->y = 10;
    this->getSprite()->resetAnimation();
    this->setState(new DoubleJumpState());
}

PlayerState *Player::getState() const {
    return this->state;
}

SDL_Rect *Player::getSwordRect() {
    if (isFacingLeft)return new SDL_Rect {rect->x-53, rect->y+78, 50, 12};
    else return new SDL_Rect {rect->x+45, rect->y+78, 50, 12};
}
