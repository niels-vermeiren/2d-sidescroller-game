//
// Created by niels on 10.06.21.
//

#ifndef INC_2DSIDESCROLLER_SHOOTBULLETCOMMAND_H
#define INC_2DSIDESCROLLER_SHOOTBULLETCOMMAND_H


#include "../Command.h"
#include "../../entity/Player.h"

class ShootBulletCommand : public Command {
public:
    explicit ShootBulletCommand(Player * entity);
    void execute() override;

private:
    Player * entity;
    int tick = 0;
};


#endif //INC_2DSIDESCROLLER_SHOOTBULLETCOMMAND_H
