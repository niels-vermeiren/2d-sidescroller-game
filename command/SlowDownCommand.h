//
// Created by niels on 5/14/21.
//

#ifndef INC_2DSIDESCROLLER_SLOWDOWNCOMMAND_H
#define INC_2DSIDESCROLLER_SLOWDOWNCOMMAND_H


#include "Command.h"
#include "../entity/Player.h"

class SlowDownCommand : public Command {
public:
    explicit SlowDownCommand(Player * entity);
    void execute() override;

private:
    Player * entity;
};


#endif //INC_2DSIDESCROLLER_SLOWDOWNCOMMAND_H
