//
// Created by niels on 19.06.21.
//

#ifndef INC_2DSIDESCROLLER_MOVINGSAWAI_H
#define INC_2DSIDESCROLLER_MOVINGSAWAI_H


#include "../entity/Saw.h"
#include "../entity/EntityManager.h"
#include "EntityAI.h"

class MovingSawAI  : public EntityAI {
public:
    MovingSawAI(Saw * saw, EntityManager * walls);
    void update() override;
private:
    Saw * saw;
    Entity * wall;
};


#endif //INC_2DSIDESCROLLER_MOVINGSAWAI_H
