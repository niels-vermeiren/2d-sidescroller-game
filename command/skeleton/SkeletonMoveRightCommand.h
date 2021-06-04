//
// Created by niels on 6/1/21.
//

#ifndef INC_2DSIDESCROLLER_SKELETONMOVERIGHTCOMMAND_H
#define INC_2DSIDESCROLLER_SKELETONMOVERIGHTCOMMAND_H


#include "../Command.h"
#include "../../entity/Skeleton.h"

class SkeletonMoveRightCommand : public Command {
public:
    explicit SkeletonMoveRightCommand(Skeleton * entity);
    void execute() override;

private:
    Skeleton * entity;

};


#endif //INC_2DSIDESCROLLER_SKELETONMOVERIGHTCOMMAND_H
