//
// Created by niels on 5/11/21.
//

#ifndef INC_2DSIDESCROLLER_ATTACKCOMMAND_H
#define INC_2DSIDESCROLLER_ATTACKCOMMAND_H


#include "../Command.h"
#include "../../entity/Player.h"

class AttackCommand : public Command{
public:
    explicit AttackCommand(Player * entity);
    void execute() override;

private:
    Player * entity;
};


#endif //INC_2DSIDESCROLLER_ATTACKCOMMAND_H
