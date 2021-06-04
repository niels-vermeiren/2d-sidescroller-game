//
// Created by niels on 6/1/21.
//

#ifndef INC_2DSIDESCROLLER_SKELETONSLOWDOWNCOMMAND_H
#define INC_2DSIDESCROLLER_SKELETONSLOWDOWNCOMMAND_H


#include "../Command.h"
#include "../../entity/Skeleton.h"

class SkeletonSlowDownCommand : public Command {
public:
    explicit SkeletonSlowDownCommand(Skeleton * entity);
    void execute() override;

private:
    Skeleton * entity;
};


#endif //INC_2DSIDESCROLLER_SKELETONSLOWDOWNCOMMAND_H
