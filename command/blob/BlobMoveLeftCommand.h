//
// Created by niels on 6/1/21.
//

#ifndef INC_2DSIDESCROLLER_BLOBMOVELEFTCOMMAND_H
#define INC_2DSIDESCROLLER_BLOBMOVELEFTCOMMAND_H


#include "../../entity/Skeleton1.h"
#include "../Command.h"

class BlobMoveLeftCommand : public Command {
public:
    explicit BlobMoveLeftCommand(Skeleton1 * entity);
    void execute() override;

private:
    Skeleton1 * entity;
};


#endif //INC_2DSIDESCROLLER_BLOBMOVELEFTCOMMAND_H
