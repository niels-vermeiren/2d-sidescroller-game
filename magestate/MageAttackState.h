//
// Created by niels on 07.06.21.
//

#ifndef INC_2DSIDESCROLLER_MAGEATTACKSTATE_H
#define INC_2DSIDESCROLLER_MAGEATTACKSTATE_H


#include "MageState.h"
#include "../physics/PhysicsManager.h"

class MageAttackState : public MageState {
public:
    void update(Mage * mage) override;
    MState getState() override;

private:
    int tick = -1;
    int countdownAttackReset = 60 * MAGE_SECONDS_BETWEEN_ATTACK;
    bool canAttack = true;
};


#endif //INC_2DSIDESCROLLER_MAGEATTACKSTATE_H
