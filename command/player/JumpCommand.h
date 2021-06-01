//
// Created by niels on 4/11/21.
//

#ifndef INC_2DSIDESCROLLER_JUMPCOMMAND_H
#define INC_2DSIDESCROLLER_JUMPCOMMAND_H


#include "../Command.h"
#include "../../entity/Player.h"

class JumpCommand : public Command {
public:
    explicit JumpCommand(Player * player);
    void execute() override;

private:
    Player * player;
};


#endif //INC_2DSIDESCROLLER_JUMPCOMMAND_H
