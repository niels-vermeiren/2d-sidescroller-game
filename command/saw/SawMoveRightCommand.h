//
// Created by niels on 19.06.21.
//

#ifndef INC_2DSIDESCROLLER_SAWMOVERIGHTCOMMAND_H
#define INC_2DSIDESCROLLER_SAWMOVERIGHTCOMMAND_H


#include "../../entity/Saw.h"
#include "../Command.h"

class SawMoveRightCommand : public Command {
public:
    explicit SawMoveRightCommand(Saw * saw);
    void execute() override;

private:
    Saw * entity;

};


#endif //INC_2DSIDESCROLLER_SAWMOVERIGHTCOMMAND_H
