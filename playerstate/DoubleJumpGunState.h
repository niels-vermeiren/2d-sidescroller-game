//
// Created by niels on 09.06.21.
//

#ifndef INC_2DSIDESCROLLER_DOUBLEJUMPGUNSTATE_H
#define INC_2DSIDESCROLLER_DOUBLEJUMPGUNSTATE_H


#include "PlayerState.h"
#include "../entity/Player.h"

class DoubleJumpGunState : public PlayerState {
public:
    void update(Player * player) override;
    PState getState() override;

};


#endif //INC_2DSIDESCROLLER_DOUBLEJUMPGUNSTATE_H
