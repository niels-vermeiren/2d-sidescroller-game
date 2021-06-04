//
// Created by niels on 6/2/21.
//

#ifndef INC_2DSIDESCROLLER_ATTACKINGSTATE_H
#define INC_2DSIDESCROLLER_ATTACKINGSTATE_H


#include "SkeletonState.h"

class AttackingState : public SkeletonState {
public:
    void update(Skeleton * skeleton) override;
    SState getState() override;

private:
    int tick = 0;
};


#endif //INC_2DSIDESCROLLER_ATTACKINGSTATE_H
