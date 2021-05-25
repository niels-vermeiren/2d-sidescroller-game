//
// Created by niels on 4/10/21.
//

#ifndef INC_2DSIDESCROLLER_PLAYER_H
#define INC_2DSIDESCROLLER_PLAYER_H


#include <SDL2/SDL.h>
#include "../math/Vector.h"
#include "../game/renderer.h"
#include "../defs.h"
#include "FallingEntity.h"
#include "../sprite/Sprite.h"
#include "../input/InputManager.h"
#include "../sprite/PlayerSprite.h"
#include "../playerstate/PlayerState.h"

class Player: public FallingEntity {
public:
    Player(Vector direction, SDL_Rect * rect);
    void draw(Renderer renderer) override;
    void update() override;
    AnimatedSprite * getSprite();
    void setFacingLeft(bool facingLeft);
    void setState(PlayerState * state);
    PlayerState * getState() const;
    void notifyObservers() override;
    void reset();
    ~Player() override;

private:
    PlayerState * state;
    bool isFacingLeft;
    AnimatedSprite * sprite;
};

#endif //INC_2DSIDESCROLLER_PLAYER_H
