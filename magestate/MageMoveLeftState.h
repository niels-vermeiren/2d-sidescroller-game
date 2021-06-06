//
// Created by niels on 06.06.21.
//

#ifndef INC_2DSIDESCROLLER_MAGEMOVELEFTSTATE_H
#define INC_2DSIDESCROLLER_MAGEMOVELEFTSTATE_H


#include "MageState.h"
#include "../entity/Mage.h"
#include "../command/mage/MageMoveLeftCommand.h"

class MageMoveLeftState : public MageState {
public:
    void update(Mage * mage) override;
    MState getState() override;

};


#endif //INC_2DSIDESCROLLER_MAGEMOVELEFTSTATE_H
