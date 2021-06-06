//
// Created by niels on 06.06.21.
//

#ifndef INC_2DSIDESCROLLER_MAGEMOVELEFTCOMMAND_H
#define INC_2DSIDESCROLLER_MAGEMOVELEFTCOMMAND_H


#include "../Command.h"
#include "../../entity/Mage.h"

class MageMoveLeftCommand : public Command {
public:
    explicit MageMoveLeftCommand(Mage * entity);
    void execute() override;

private:
    Mage * entity;

};


#endif //INC_2DSIDESCROLLER_MAGEMOVELEFTCOMMAND_H
