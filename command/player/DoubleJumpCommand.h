//
// Created by niels on 4/28/21.
//

#ifndef INC_2DSIDESCROLLER_DOUBLEJUMPCOMMAND_H
#define INC_2DSIDESCROLLER_DOUBLEJUMPCOMMAND_H


#include "../Command.h"
#include "../../entity/Player.h"

class DoubleJumpCommand : public Command {
public:
    explicit DoubleJumpCommand(Player * player);
    void execute() override;

private:
    Player * player;
};


#endif //INC_2DSIDESCROLLER_DOUBLEJUMPCOMMAND_H
