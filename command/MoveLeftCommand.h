//
// Created by niels on 4/11/21.
//

#ifndef INC_2DSIDESCROLLER_MOVELEFTCOMMAND_H
#define INC_2DSIDESCROLLER_MOVELEFTCOMMAND_H


#include "Command.h"
#include "../entity/Player.h"
#include "../physics/PhysicsManager.h"

class MoveLeftCommand : public Command {
public:
    explicit MoveLeftCommand(Player * entity);
    void execute() override;

private:
    Player * entity;
};


#endif //INC_2DSIDESCROLLER_MOVELEFTCOMMAND_H
