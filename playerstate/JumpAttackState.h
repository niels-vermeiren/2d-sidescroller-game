//
// Created by niels on 5/12/21.
//

#ifndef INC_2DSIDESCROLLER_JUMPATTACKSTATE_H
#define INC_2DSIDESCROLLER_JUMPATTACKSTATE_H

#include "DoubleJumpState.h"
#include "JumpState.h"
#include "../entity/Player.h"
#include "../command/DoubleJumpCommand.h"

class JumpAttackState : public PlayerState {
public:
    void update(Player * player) override;
    PState getState() override;
};


#endif //INC_2DSIDESCROLLER_JUMPATTACKSTATE_H
