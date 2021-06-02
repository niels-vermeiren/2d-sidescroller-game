//
// Created by niels on 6/1/21.
//

#ifndef INC_2DSIDESCROLLER_WALKINGSTATE_H
#define INC_2DSIDESCROLLER_WALKINGSTATE_H


#include "SkeletonState.h"
#include "../entity/Skeleton1.h"
class WalkingState : public SkeletonState {
public:
    void update(Skeleton1 * skeleton1) override;
    SState getState() override;
};


#endif //INC_2DSIDESCROLLER_WALKINGSTATE_H
