//
// Created by niels on 6/3/21.
//

#ifndef INC_2DSIDESCROLLER_MAGEMOVELEFTSTATE_H
#define INC_2DSIDESCROLLER_MOVELEFTSTATE_H


#include "SkeletonState.h"
#include "../entity/Skeleton.h"
class MoveLeftState : public SkeletonState {
public:
    void update(Skeleton * skeleton) override;
    SState getState() override;
};


#endif //INC_2DSIDESCROLLER_MAGEMOVELEFTSTATE_H
