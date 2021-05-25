//
// Created by niels on 5/12/21.
//

#ifndef INC_2DSIDESCROLLER_DOUBLEJUMPATTACKSTATE_H
#define INC_2DSIDESCROLLER_DOUBLEJUMPATTACKSTATE_H

#include "PlayerState.h"
#include "DoubleJumpState.h"
#include "../entity/Player.h"
#include "../command/MoveLeftCommand.h"
#include "../command/MoveRightCommand.h"
#include "../command/StandStillCommand.h"

class DoubleJumpAttackState : public PlayerState {
public:
    void update(Player * player) override;
    PState getState() override;
};


#endif //INC_2DSIDESCROLLER_DOUBLEJUMPATTACKSTATE_H
