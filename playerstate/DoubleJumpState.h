//
// Created by niels on 4/29/21.
//

#ifndef INC_2DSIDESCROLLER_DOUBLEJUMPSTATE_H
#define INC_2DSIDESCROLLER_DOUBLEJUMPSTATE_H

#include "PlayerState.h"
#include "DoubleJumpAttackState.h"
#include "../animation/PlayerAnimation.h"
#include "../entity/Player.h"

class DoubleJumpState : public PlayerState {
public:
    void update(Player * player) override;
    PState getState() override;
};


#endif //INC_2DSIDESCROLLER_DOUBLEJUMPSTATE_H
