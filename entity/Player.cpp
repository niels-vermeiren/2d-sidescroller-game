//
// Created by niels on 4/10/21.
//
#include "Player.h"
#include "../playerstate/JumpState.h"

Player::Player(Vector direction, SDL_Rect * rect) : FallingEntity(direction, rect) {
    this->sprite = new PlayerSprite();
    this->state = new JumpState();
    this->rect = rect;
    this->x = rect->x;
    this->y = rect->y;
    this->isFacingLeft = false;
}

void Player::update() {
    this->state->update(this);
    this->x += direction.x;
    this->y += direction.y;
    rect->x += direction.x;
    rect->y += direction.y;
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
    getCollisionBox()->x  =x;
    getCollisionBox()->y  =y;

    for (auto * observer : observers) {
        observer->updatePlayerPos(getCollisionBox()->x + getCollisionBox()->w / 2, getCollisionBox()->y + getCollisionBox()->h/ 2);
    }
}

void Player::setState(PlayerState * state) {
    this->state = state;
}

void Player::reset() {
    this->rect->x = 10;
    this->rect->y = 10;
    x = 10;
    y = 10;
    this->getSprite()->resetAnimation();
    this->setState(new DoubleJumpState());
}

PlayerState *Player::getState() const {
    return this->state;
}

SDL_Rect *Player::getKnifeCollisionBox() {
    knifeCollisionBox.getCollisionBox(getCollisionBox(), isFacingLeft);
}

SDL_Rect *Player::getCollisionBox() {
    return playerCollisionBox.getCollisionBox(getRect());
}
