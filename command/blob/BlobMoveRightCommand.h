//
// Created by niels on 6/1/21.
//

#ifndef INC_2DSIDESCROLLER_BLOBMOVERIGHTCOMMAND_H
#define INC_2DSIDESCROLLER_BLOBMOVERIGHTCOMMAND_H


#include "../Command.h"
#include "../../entity/Skeleton1.h"

class BlobMoveRightCommand : public Command {
public:
    explicit BlobMoveRightCommand(Skeleton1 * entity);
    void execute() override;

private:
    Skeleton1 * entity;

};


#endif //INC_2DSIDESCROLLER_BLOBMOVERIGHTCOMMAND_H
