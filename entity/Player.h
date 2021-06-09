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

class Player: public FallingEntity {
public:
    Player(Vector direction, SDL_Rect * rect);
    void draw(Renderer renderer) override;
    void update() override;
    void setState(PlayerState * state);
    void setFacingLeft(bool facingLeft);
    PlayerState * getState() const;
    AnimatedSprite * getSprite();
    SDL_Rect * getCollisionBox();
    SDL_Rect * getKnifeCollisionBox();
    void notifyObservers() override;
    void reset() override;
    ~Player() override;

private:
    AnimatedSprite * sprite;
    PlayerState * state;
    bool isFacingLeft;
    PlayerCollisionBox playerCollisionBox;
    PlayerKnifeCollisionBox knifeCollisionBox;
};

#endif //INC_2DSIDESCROLLER_PLAYER_H
