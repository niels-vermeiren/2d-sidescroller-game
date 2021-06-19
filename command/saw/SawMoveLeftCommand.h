//
// Created by niels on 19.06.21.
//

#ifndef INC_2DSIDESCROLLER_SAWMOVELEFTCOMMAND_H
#define INC_2DSIDESCROLLER_SAWMOVELEFTCOMMAND_H


#include "../Command.h"
#include "../../entity/Saw.h"

class SawMoveLeftCommand : public Command {
public:
    explicit SawMoveLeftCommand(Saw * saw);
    void execute() override;

private:
    Saw * entity;

};


#endif //INC_2DSIDESCROLLER_SAWMOVELEFTCOMMAND_H
