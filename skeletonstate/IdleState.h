//
// Created by niels on 6/2/21.
//

#ifndef INC_2DSIDESCROLLER_IDLESTATE_H
#define INC_2DSIDESCROLLER_IDLESTATE_H


#include "SkeletonState.h"
#include "../entity/Skeleton1.h"
class IdleState : public SkeletonState {
public:
    void update(Skeleton1 * skeleton) override;
    SState getState() override;

};


#endif //INC_2DSIDESCROLLER_IDLESTATE_H
