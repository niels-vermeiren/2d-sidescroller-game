//
// Created by niels on 6/1/21.
//

#ifndef INC_2DSIDESCROLLER_BLOBSLOWDOWNCOMMAND_H
#define INC_2DSIDESCROLLER_BLOBSLOWDOWNCOMMAND_H


#include "../Command.h"
#include "../../entity/Skeleton1.h"

class BlobSlowDownCommand : public Command {
public:
    explicit BlobSlowDownCommand(Skeleton1 * entity);
    void execute() override;

private:
    Skeleton1 * entity;
};


#endif //INC_2DSIDESCROLLER_BLOBSLOWDOWNCOMMAND_H
