//
// Created by niels on 6/2/21.
//

#ifndef INC_2DSIDESCROLLER_ATTACKINGSTATE_H
#define INC_2DSIDESCROLLER_ATTACKINGSTATE_H


#include "SkeletonState.h"

class AttackingState : public SkeletonState {
public:
    void update(Skeleton1 * skeleton1) override;
    SState getState() override;

};


#endif //INC_2DSIDESCROLLER_ATTACKINGSTATE_H
