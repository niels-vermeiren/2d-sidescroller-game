//
// Created by niels on 6/3/21.
//

#ifndef INC_2DSIDESCROLLER_STANDSTILLSTATE_H
#define INC_2DSIDESCROLLER_STANDSTILLSTATE_H


#include "SkeletonState.h"

class StandStillState : public SkeletonState{
public:
    void update(Skeleton * skeleton) override;
    SState getState() override;
};


#endif //INC_2DSIDESCROLLER_STANDSTILLSTATE_H
