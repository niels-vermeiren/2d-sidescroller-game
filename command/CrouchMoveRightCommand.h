//
// Created by niels on 5/6/21.
//

#ifndef INC_2DSIDESCROLLER_CROUCHMOVERIGHTCOMMAND_H
#define INC_2DSIDESCROLLER_CROUCHMOVERIGHTCOMMAND_H


#include "Command.h"
#include "../entity/Player.h"

class CrouchMoveRightCommand : public Command {
public:
    explicit CrouchMoveRightCommand(Player * entity);
    void execute() override;

private:
    Player * entity{};
};


#endif //INC_2DSIDESCROLLER_CROUCHMOVERIGHTCOMMAND_H
