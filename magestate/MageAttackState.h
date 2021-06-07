//
// Created by niels on 07.06.21.
//

#ifndef INC_2DSIDESCROLLER_MAGEATTACKSTATE_H
#define INC_2DSIDESCROLLER_MAGEATTACKSTATE_H


#include "MageState.h"

class MageAttackState : public MageState {
public:
    void update(Mage * mage) override;
    MState getState() override;

private:
    int tick = 0;

};


#endif //INC_2DSIDESCROLLER_MAGEATTACKSTATE_H
