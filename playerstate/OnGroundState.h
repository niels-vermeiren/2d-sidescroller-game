//
// Created by niels on 4/29/21.
//

#ifndef INC_2DSIDESCROLLER_ONGROUNDSTATE_H
#define INC_2DSIDESCROLLER_ONGROUNDSTATE_H

#include "PlayerState.h"
#include "JumpState.h"
#include "CrouchState.h"
#include "AttackState.h"
#include "../command/player/JumpCommand.h"
#include "../command/player/AttackCommand.h"
#include "../command/player/MoveRightCommand.h"
#include "../command/player/MoveLeftCommand.h"

class OnGroundState : public PlayerState {
public:
    void update(Player * player) override;
    PState getState() override;
};


#endif //INC_2DSIDESCROLLER_ONGROUNDSTATE_H
