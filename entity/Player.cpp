//
// Created by niels on 4/10/21.
//
#include "Player.h"
#include "../playerstate/JumpState.h"
#include "../playerstate/OnGroundState.h"
#include "../command/player/ShootBulletCommand.h"
#include "../game/Game.h"
#include "../sound/JukeBox.h"

Player::Player(Vector direction, SDL_Rect * rect) : FallingEntity(direction, rect) {
    this->x = (float) rect->x, this->y = (float) rect->y;
    this->sprite = new PlayerSprite();
    this->state = new JumpState();
    this->previousState = new OnGroundState();
    this->facingLeft = false;
    this->rect = rect;
    this->shouldDraw = true;
    bullets = new ParticlePool<PlayerBullet*>();
    addObserver(bullets);
}

void Player::update() {
    tick++;
    if(tick % MIN_TIME_BETWEEN_PLAYER_BULLETS == 0) canShoot = true;
    for(PlayerBullet * entity: getBulletPool()->getParticles()) entity->update();
    getBulletPool()->clear();
    if(rect->y > LEVEL_HEIGHT) this->shouldDraw = false;
    if(!shouldDraw && rect->x>0) {
        if(rewind.x == 0) {
            x=rect->x;y=rect->y;
            rewind.x = x / (60 * PLAYER_DEAD_REWIND_SPEED);
            rewind.y =  (y-LEVEL_HEIGHT) /   (60 * PLAYER_DEAD_REWIND_SPEED);
        }
        direction.x = 0;
        x -= rewind.x;
        rect->x =x;
        if (rect->y < LEVEL_HEIGHT) {
            direction.y=0;
            y -= rewind.y;
            rect->y = y;
        }
    }
    if(rewind.x==0){
        this->state->update(this);
        this->x += direction.x, this->y += direction.y;
        rect->x += (int)direction.x, rect->y += (int)direction.y;
        this->applyGravity();
    }

    if(rect->x<=0 && !shouldDraw) Game::reset();

    notifyObservers();
}

void Player::draw(Renderer renderer) {
    if(shouldDraw) this->sprite->draw(renderer, rect, nullptr, facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
    for(PlayerBullet * bullet : getBulletPool()->getParticles()) bullet->draw(renderer);

}

PlayerState *Player::getState() const {
    return this->state;
}

void Player::setState(PlayerState * playerState) {
    this->state = playerState;
}

PlayerState * Player::getPreviousState() const {
    return previousState;
}

void Player::setPreviousState(PlayerState * lastState) {
    this->previousState = lastState;
}

SDL_Rect *Player::getKnifeCollisionBox() {
    return knifeCollisionBox.getCollisionBox(getCollisionBox(), facingLeft);
}

SDL_Rect *Player::getCollisionBox() {
    return playerCollisionBox.getCollisionBox(getRect());
}

AnimatedSprite * Player::getSprite() {
    return sprite;
}

void Player::shootBullet() {
    if(!canShoot) return;
    JukeBox::getInstance()->playSound(JukeBox::LASER, true);
    ShootBulletCommand cmd(this);
    cmd.execute();
    canShoot = false;
    tick = 0;
}

void Player::notifyObservers() {
    getCollisionBox()->x = (int) x;
    getCollisionBox()->y = (int) y;
    for (auto * observer : observers) {
        observer->updatePlayerPos( getCollisionBox()->x + getCollisionBox()->w / 2, getCollisionBox()->y + getCollisionBox()->h/ 2);
    }
}

void Player::reset(){
    *this->rect = *initialPosition;
    this->shouldDraw = true;
    this->visible = true;
    this->getSprite()->resetAnimation();
    this->setState(new DoubleJumpState());
    rewind = {0,0};
    PlayerStats::getInstance().setHealth(100);
    PlayerStats::getInstance().setCoins(0);
}

ParticlePool<PlayerBullet *> * Player::getBulletPool() const {
    return dynamic_cast<ParticlePool<PlayerBullet *>*>(bullets);
}

Player::~Player() {
    delete sprite;
    delete rect;
}

void Player::load() {
    for (auto * bullet: getBulletPool()->getParticles()) {
        bullet->getSprite()->load();
    }
}

void Player::loadToTexture() {
    for (auto * bullet: getBulletPool()->getParticles()) {
        bullet->getSprite()->loadToTexture();
    }
}

