//
// Created by niels on 4/11/21.
//

#ifndef INC_2DSIDESCROLLER_COMMAND_H
#define INC_2DSIDESCROLLER_COMMAND_H

#include "../entity/Entity.h"
#include "../input/InputManager.h"
#include "SDL2/SDL.h"
#include "../defs.h"

class Command {
public:
    virtual void execute() = 0;
};

#endif //INC_2DSIDESCROLLER_COMMAND_H
