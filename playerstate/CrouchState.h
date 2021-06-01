//
// Created by niels on 5/11/21.
//

#ifndef INC_2DSIDESCROLLER_CROUCHSTATE_H
#define INC_2DSIDESCROLLER_CROUCHSTATE_H

#include "PlayerState.h"
#include "OnGroundState.h"
#include "../entity/Player.h"
#include "../command/player/CrouchMoveLeftCommand.h"
#include "../command/player/CrouchMoveRightCommand.h"
#include "../command/player/StandStillCommand.h"

class CrouchState : public PlayerState{
public:
    void update(Player * player) override;
    PState getState() override;
};


#endif //INC_2DSIDESCROLLER_CROUCHSTATE_H
