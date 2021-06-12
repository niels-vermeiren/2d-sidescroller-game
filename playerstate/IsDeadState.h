
//
// Created by niels on 5/12/21.
//

#ifndef INC_2DSIDESCROLLER_ISDEADSTATE_H
#define INC_2DSIDESCROLLER_ISDEADSTATE_H


#include "../entity/Player.h"
#include "../command/player/StandStillCommand.h"
#include "PlayerState.h"

class IsDeadState : public PlayerState {
public:
    void update(Player * player) override;
    PState getState() override;

private:
    int tick = 0;
};


#endif //INC_2DSIDESCROLLER_ISDEADSTATE_H
