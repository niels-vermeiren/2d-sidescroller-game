//
// Created by niels on 06.06.21.
//

#ifndef INC_2DSIDESCROLLER_MAGESTATE_H
#define INC_2DSIDESCROLLER_MAGESTATE_H

class Mage;

enum MState {
    STILL,
    DOOD,
    LEFT,
    RIGHT,
    STAFF_ATTACK
};

class MageState {
public:
    virtual void update(Mage * mage) = 0;
    virtual MState getState() = 0;
};


#endif //INC_2DSIDESCROLLER_MAGESTATE_H
