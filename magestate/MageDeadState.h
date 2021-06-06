//
// Created by niels on 06.06.21.
//

#ifndef INC_2DSIDESCROLLER_MAGEDEADSTATE_H
#define INC_2DSIDESCROLLER_MAGEDEADSTATE_H


#include "../entity/Mage.h"
#include "MageState.h"

class MageDeadState : public MageState {
public:
    void update(Mage * mage) override;
    MState getState() override;

};


#endif //INC_2DSIDESCROLLER_MAGEDEADSTATE_H
