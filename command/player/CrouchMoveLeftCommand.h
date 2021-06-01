//
// Created by niels on 5/6/21.
//

#ifndef INC_2DSIDESCROLLER_CROUCHMOVELEFTCOMMAND_H
#define INC_2DSIDESCROLLER_CROUCHMOVELEFTCOMMAND_H


#include "../Command.h"
#include "../../entity/Player.h"

class CrouchMoveLeftCommand : public Command {
public:
    explicit CrouchMoveLeftCommand(Player * entity);
    void execute() override;

private:
    Player * entity;
};


#endif //INC_2DSIDESCROLLER_CROUCHMOVELEFTCOMMAND_H
