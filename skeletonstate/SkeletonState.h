//
// Created by niels on 6/1/21.
//

#ifndef INC_2DSIDESCROLLER_SKELETONSTATE_H
#define INC_2DSIDESCROLLER_SKELETONSTATE_H


class Skeleton1;

enum SState {
    IDLE,
    DEAD,
    MOVING,
    ATTACK
};

class SkeletonState {
public:
    virtual void update(Skeleton1 * player) = 0;
    virtual SState getState() = 0;
};


#endif //INC_2DSIDESCROLLER_SKELETONSTATE_H
