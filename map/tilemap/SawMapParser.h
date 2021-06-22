//
// Created by niels on 5/25/21.
//

#ifndef INC_2DSIDESCROLLER_SAWMAPPARSER_H
#define INC_2DSIDESCROLLER_SAWMAPPARSER_H


#include <string>
#include "../MapParser.h"
#include "../../entity/EntityManager.h"

class SawMapParser : public MapParser {
public:
    EntityManager * mapToEntities(const std::string LEVEL) override;
private:
    static std::string getMapFilePath(const std::string LEVEL);
};


#endif //INC_2DSIDESCROLLER_SAWMAPPARSER_H
