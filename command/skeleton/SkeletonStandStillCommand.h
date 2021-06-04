//
// Created by niels on 6/3/21.
//

#ifndef INC_2DSIDESCROLLER_STANDSTILLCOMMAND_H
#define INC_2DSIDESCROLLER_STANDSTILLCOMMAND_H


#include "../Command.h"
#include "../../entity/Skeleton.h"

class SkeletonStandStillCommand : public Command {
public:
    explicit SkeletonStandStillCommand(Skeleton * skeleton);
    void execute() override;

private:
    Skeleton * skeleton;

};


#endif //INC_2DSIDESCROLLER_STANDSTILLCOMMAND_H
