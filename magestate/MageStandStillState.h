//N
// Created by niels on 07.06.21.
//

#ifndef INC_2DSIDESCROLLER_MAGESTANDSTILLSTATE_H
#define INC_2DSIDESCROLLER_MAGESTANDSTILLSTATE_H


#include "../entity/Mage.h"
#include "MageState.h"

class MageStandStillState : public MageState{
public:
    void update(Mage * mage) override;
    MState getState() override;

};


#endif //INC_2DSIDESCROLLER_MAGESTANDSTILLSTATE_H
