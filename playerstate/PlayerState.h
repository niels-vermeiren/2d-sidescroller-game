//
// Created by niels on 4/29/21.
//

#ifndef INC_2DSIDESCROLLER_PLAYERSTATE_H
#define INC_2DSIDESCROLLER_PLAYERSTATE_H
#include "../input/InputManager.h"


class Player;

enum PState {
    ATTACKING,
    CROUCHING,
    DOUBLE_JUMP_ATTACKING,
    DOUBLE_JUMPING,
    DYING,
    HURTING,
    JUMPING,
    JUMP_ATTACKING,
    WALKING
};

class PlayerState {
public:
    virtual void update(Player * player) = 0;
    virtual PState getState() = 0;
};


#endif //INC_2DSIDESCROLLER_PLAYERSTATE_H
