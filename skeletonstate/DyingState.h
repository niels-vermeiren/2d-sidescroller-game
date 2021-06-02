//
// Created by niels on 6/1/21.
//

#ifndef INC_2DSIDESCROLLER_DYINGSTATE_H
#define INC_2DSIDESCROLLER_DYINGSTATE_H


#include "SkeletonState.h"
#include "../entity/Skeleton1.h"

class DyingState : public SkeletonState {
public:
    void update(Skeleton1 * blob) override;
    SState getState() override;

};


#endif //INC_2DSIDESCROLLER_DYINGSTATE_H
