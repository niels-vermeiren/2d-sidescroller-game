//
// Created by niels on 06.06.21.
//

#ifndef INC_2DSIDESCROLLER_MAGEMOVERIGHTCOMMAND_H
#define INC_2DSIDESCROLLER_MAGEMOVERIGHTCOMMAND_H


#include "../Command.h"
#include "../../entity/Mage.h"

class MageMoveRightCommand : public Command {
public:
    explicit MageMoveRightCommand(Mage * entity);
    void execute() override;

private:
    Mage * entity;
};


#endif //INC_2DSIDESCROLLER_MAGEMOVERIGHTCOMMAND_H
