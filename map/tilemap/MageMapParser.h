//
// Created by niels on 11.06.21.
//

#ifndef INC_2DSIDESCROLLER_MAGEMAPPARSER_H
#define INC_2DSIDESCROLLER_MAGEMAPPARSER_H


#include "../MapParser.h"
#include "../../entity/EntityManager.h"

class MageMapParser : public MapParser {
public:
    EntityManager * mapToEntities() override;
private:
    static std::string getMapFilePath();
};


#endif //INC_2DSIDESCROLLER_MAGEMAPPARSER_H
