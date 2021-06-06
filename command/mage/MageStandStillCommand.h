//
// Created by niels on 06.06.21.
//

#ifndef INC_2DSIDESCROLLER_MAGESTANDSTILLCOMMAND_H
#define INC_2DSIDESCROLLER_MAGESTANDSTILLCOMMAND_H


#include "../Command.h"
#include "../../entity/Mage.h"

class MageStandStillCommand  : public Command {
public:
    explicit MageStandStillCommand(Mage * entity);
    void execute() override;

private:
    Mage * entity;

};


#endif //INC_2DSIDESCROLLER_MAGESTANDSTILLCOMMAND_H
