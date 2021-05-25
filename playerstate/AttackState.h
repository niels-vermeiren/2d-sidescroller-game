//
// Created by niels on 5/12/21.
//

#ifndef INC_2DSIDESCROLLER_ATTACKSTATE_H
#define INC_2DSIDESCROLLER_ATTACKSTATE_H

#include "JumpState.h"
#include "OnGroundState.h"
#include "CrouchState.h"
#include "../command/JumpCommand.h"
#include "../command/StandStillCommand.h"
#include "../entity/Player.h"

class AttackState : public PlayerState {
public:
    void update(Player * player) override;
    PState getState() override;
};


#endif //INC_2DSIDESCROLLER_ATTACKSTATE_H
