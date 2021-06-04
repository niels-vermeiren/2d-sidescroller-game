//
// Created by niels on 6/1/21.
//

#ifndef INC_2DSIDESCROLLER_SKELETONMOVELEFTCOMMAND_H
#define INC_2DSIDESCROLLER_SKELETONMOVELEFTCOMMAND_H


#include "../../entity/Skeleton.h"
#include "../Command.h"

class SkeletonMoveLeftCommand : public Command {
public:
    explicit SkeletonMoveLeftCommand(Skeleton * entity);
    void execute() override;

private:
    Skeleton * entity;
};


#endif //INC_2DSIDESCROLLER_SKELETONMOVELEFTCOMMAND_H
