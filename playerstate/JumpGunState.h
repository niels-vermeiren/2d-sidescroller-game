//
// Created by niels on 09.06.21.
//

#ifndef INC_2DSIDESCROLLER_JUMPGUNSTATE_H
#define INC_2DSIDESCROLLER_JUMPGUNSTATE_H


#include "PlayerState.h"
#include "../entity/Player.h"

class JumpGunState : public PlayerState {
public:
    void update(Player * player) override;
    PState getState() override;

};


#endif //INC_2DSIDESCROLLER_JUMPGUNSTATE_H
