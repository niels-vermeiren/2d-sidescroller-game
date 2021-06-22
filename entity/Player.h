//
// Created by niels on 4/10/21.
//

#ifndef INC_2DSIDESCROLLER_PLAYER_H
#define INC_2DSIDESCROLLER_PLAYER_H


#include <SDL2/SDL.h>
#include "../math/Vector.h"
#include "../game/Renderer.h"
#include "../defs.h"
#include "FallingEntity.h"
#include "../sprite/Sprite.h"
#include "../input/InputManager.h"
#include "../sprite/PlayerSprite.h"
#include "../playerstate/PlayerState.h"
#include "collisionbox/PlayerCollisionBox.h"
#include "collisionbox/PlayerKnifeCollisionBox.h"
#include "collisionbox/PlayerGunCollisionBox.h"
#include "../particles/ParticlePool.h"
#include "PlayerBullet.h"

class Player: public FallingEntity {
public:
    Player(Vector direction, SDL_Rect * rect);

    void draw(Renderer renderer) override;
    void update();
    void setState(PlayerState * playerState);
    PlayerState * getState() const;
    AnimatedSprite * getSprite();
    PlayerState *getPreviousState() const;
    void setPreviousState(PlayerState *lastState);
    ParticlePool<PlayerBullet*> * getBulletPool() const;
    SDL_Rect * getCollisionBox();
    SDL_Rect * getKnifeCollisionBox();
    void shootBullet();
    void notifyObservers() override;
    void reset() override;
    void load();
    void loadToTexture();

    ~Player() override;
private:
    bool canShoot = true;
    int tick = 0;
    Vector rewind;
    AnimatedSprite * sprite;
    PlayerState * previousState;
    PlayerState * state;
    EntityObserver * bullets;
    PlayerCollisionBox playerCollisionBox;
    PlayerKnifeCollisionBox knifeCollisionBox;
};

#endif //INC_2DSIDESCROLLER_PLAYER_H
