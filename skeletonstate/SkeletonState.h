//
// Created by niels on 6/1/21.
//

#ifndef INC_2DSIDESCROLLER_SKELETONSTATE_H
#define INC_2DSIDESCROLLER_SKELETONSTATE_H


class Skeleton;

enum SState {
    IDLE,
    DEAD,
    MOVE_LEFT,
    MOVE_RIGHT,
    ATTACK
};

class SkeletonState {
public:
    virtual void update(Skeleton * player) = 0;
    virtual SState getState() = 0;
};


#endif //INC_2DSIDESCROLLER_SKELETONSTATE_H
