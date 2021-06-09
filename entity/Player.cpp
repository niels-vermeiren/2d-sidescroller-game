//
// Created by niels on 4/10/21.
//
#include "Player.h"
#include "../playerstate/JumpState.h"
#include "../playerstate/OnGroundState.h"

Player::Player(Vector direction, SDL_Rect * rect) : FallingEntity(direction, rect) {
    this->sprite = new PlayerSprite();
    this->bulletSprite = new PlayerBulletSprite();
    this->state = new JumpState();
    this->previousState = new OnGroundState();
    this->rect = rect;
    this->x = rect->x;
    this->y = rect->y;
    this->isFacingLeft = false;
    this->shots = new ParticlePool();
}

void Player::update() {
    this->state->update(this);
    for(Entity * entity: shots->getParticles()) {
        entity->update();
    }
    this->x += direction.x;
    this->y += direction.y;
    rect->x += direction.x;
    rect->y += direction.y;
    this->applyGravity();
    notifyObservers();
    shots->clear();

    std::cout << shots->getParticles().size() << " => particle size" << std::endl;
}

void Player::draw(Renderer renderer) {
    for(Entity * bullet : this->shots->getParticles()) {
        bullet->draw(renderer);
    }
    this->sprite->draw(renderer, rect, NULL, isFacingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);

}


AnimatedSprite * Player::getSprite() {
    return sprite;
}

PlayerState *Player::getState() const {
    return this->state;
}

void Player::setState(PlayerState * state) {
    this->state = state;
}

SDL_Rect *Player::getKnifeCollisionBox() {
    return knifeCollisionBox.getCollisionBox(getCollisionBox(), isFacingLeft);
}

SDL_Rect *Player::getCollisionBox() {
    return playerCollisionBox.getCollisionBox(getRect());
}

SDL_Rect *Player::getGunCollisionBox() {
    return gunCollisionBox.getCollisionBox(getRect(), isFacingLeft);
}

void Player::setFacingLeft(bool facingLeft) {
    this->isFacingLeft = facingLeft;
}

void Player::addBullet() {
    SDL_Rect * bulletRect = new SDL_Rect {getCollisionBox()->x + (isFacingLeft? -40:40), getCollisionBox()->y + 60, 47, 19};
    Vector direction(isFacingLeft ? -6: 6, 0);
    PlayerBullet *pBullet = new PlayerBullet(bulletRect, direction);
    //this->addObserver(pBullet);
    pBullet->setFacingLeft(isFacingLeft);
    shots->addParticle(pBullet);
}

void Player::notifyObservers() {
    getCollisionBox()->x  =x;
    getCollisionBox()->y  =y;
    for (auto * observer : observers) {
        observer->updatePlayerPos(getCollisionBox()->x + getCollisionBox()->w / 2, getCollisionBox()->y + getCollisionBox()->h/ 2);
    }
}

void Player::reset() {
    this->rect->x = 10, this->rect->y = 10;
    x = 10, y = 10;
    this->getSprite()->resetAnimation();
    this->setState(new DoubleJumpState());
}

Player::~Player() {
    delete sprite;
    delete rect;
}

PlayerState *Player::getPreviousState() const {
    return previousState;
}

void Player::setPreviousState(PlayerState *previousState) {
    Player::previousState = previousState;
}
