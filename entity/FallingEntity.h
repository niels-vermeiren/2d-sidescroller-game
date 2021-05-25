//
// Created by niels on 4/10/21.
//

#ifndef INC_2DSIDESCROLLER_FALLINGENTITY_H
#define INC_2DSIDESCROLLER_FALLINGENTITY_H
#include "../math/Vector.h"
#include "../physics/PhysicsManager.h"
#include "Entity.h"

class FallingEntity: public Entity {
protected:
    Vector gravity;

public:
    FallingEntity(Vector direction, SDL_Rect * rect);
    void applyGravity();
};


#endif //INC_2DSIDESCROLLER_FALLINGENTITY_H
