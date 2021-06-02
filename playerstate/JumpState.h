//
// Created by niels on 4/29/21.
//

#ifndef INC_2DSIDESCROLLER_JUMPSTATE_H
#define INC_2DSIDESCROLLER_JUMPSTATE_H

#include "PlayerState.h"
#include "DoubleJumpState.h"
#include "../command/player/DoubleJumpCommand.h"
#include "../command/player/MoveLeftCommand.h"
#include "../command/player/MoveRightCommand.h"
#include "../command/player/StandStillCommand.h"

class JumpState : public PlayerState {
public:
    void update(Player * player) override;
    PState getState() override;
};


#endif //INC_2DSIDESCROLLER_JUMPSTATE_H
