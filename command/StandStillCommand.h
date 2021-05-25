//
// Created by niels on 4/11/21.
//

#ifndef INC_2DSIDESCROLLER_STANDSTILLCOMMAND_H
#define INC_2DSIDESCROLLER_STANDSTILLCOMMAND_H


#include "Command.h"
#include "../entity/Player.h"

class StandStillCommand : public Command {
public:
    explicit StandStillCommand(Player * entity);
    void execute() override;

private:
    Player * entity;
};


#endif //INC_2DSIDESCROLLER_STANDSTILLCOMMAND_H
