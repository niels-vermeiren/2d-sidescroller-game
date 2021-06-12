//
// Created by niels on 5/13/21.
//

#ifndef INC_2DSIDESCROLLER_ISHURTSTATE_H
#define INC_2DSIDESCROLLER_ISHURTSTATE_H


#include "PlayerState.h"
#include "IsDeadState.h"
#include "../entity/Player.h"

class IsHurtState : public PlayerState {
public:
    void update(Player * player) override;
    PState getState() override;
private:
    int tick = 0;
    bool hasTakenDamage = false;
};


#endif //INC_2DSIDESCROLLER_ISHURTSTATE_H
