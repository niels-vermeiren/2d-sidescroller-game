//
// Created by niels on 4/29/21.
//

#ifndef INC_2DSIDESCROLLER_JUMPSTATE_H
#define INC_2DSIDESCROLLER_JUMPSTATE_H

#include "PlayerState.h"
#include "DoubleJumpState.h"
#include "JumpAttackState.h"
#include "../command/DoubleJumpCommand.h"
#include "../command/MoveLeftCommand.h"
#include "../command/MoveRightCommand.h"
#include "../command/StandStillCommand.h"

class JumpState : public PlayerState {
public:
    void update(Player * player) override;
    PState getState() override;
};


#endif //INC_2DSIDESCROLLER_JUMPSTATE_H
