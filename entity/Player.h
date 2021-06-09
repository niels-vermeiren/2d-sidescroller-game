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
    void update() override;
    void setState(PlayerState * state);
    void setFacingLeft(bool facingLeft);
    PlayerState * getState() const;
    AnimatedSprite * getSprite();

    PlayerState *getPreviousState() const;

    void setPreviousState(PlayerState *previousState);

    SDL_Rect * getCollisionBox();
    SDL_Rect * getKnifeCollisionBox();
    SDL_Rect * getGunCollisionBox();
    void addBullet();
    void notifyObservers() override;
    void reset() override;
    ~Player() override;

private:
    AnimatedSprite * sprite;
    Sprite * bulletSprite;
    PlayerState * previousState;
    PlayerState * state;
    ParticlePool * shots;
    bool isFacingLeft;
    PlayerCollisionBox playerCollisionBox;
    PlayerKnifeCollisionBox knifeCollisionBox;
    PlayerGunCollisionBox gunCollisionBox;
};

#endif //INC_2DSIDESCROLLER_PLAYER_H
