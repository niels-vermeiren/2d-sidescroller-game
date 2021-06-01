//
// Created by niels on 4/11/21.
//

#ifndef INC_2DSIDESCROLLER_MOVERIGHTCOMMAND_H
#define INC_2DSIDESCROLLER_MOVERIGHTCOMMAND_H


#include "../Command.h"
#include "../../physics/PhysicsManager.h"
#include "../../entity/Player.h"

class MoveRightCommand : public Command {
public:
    explicit MoveRightCommand(Player * entity);
    void execute() override;

private:
    Player * entity;
};


#endif //INC_2DSIDESCROLLER_MOVERIGHTCOMMAND_H
