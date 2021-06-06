//
// Created by niels on 06.06.21.
//

#ifndef INC_2DSIDESCROLLER_MAGESLOWDOWNCOMMAND_H
#define INC_2DSIDESCROLLER_MAGESLOWDOWNCOMMAND_H


#include "../Command.h"
#include "../../entity/Mage.h"

class MageSlowDownCommand : public Command {
public:
    explicit MageSlowDownCommand(Mage * entity);
    void execute() override;

private:
    Mage * entity;

};


#endif //INC_2DSIDESCROLLER_MAGESLOWDOWNCOMMAND_H
