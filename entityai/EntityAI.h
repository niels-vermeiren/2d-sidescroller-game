//
// Created by niels on 6/2/21.
//

#ifndef INC_2DSIDESCROLLER_ENTITYAI_H
#define INC_2DSIDESCROLLER_ENTITYAI_H
#include "../observer/EntityObserver.h"
class EntityAI : public EntityObserver {
public:
    virtual void update() = 0;
};

#endif //INC_2DSIDESCROLLER_ENTITYAI_H
