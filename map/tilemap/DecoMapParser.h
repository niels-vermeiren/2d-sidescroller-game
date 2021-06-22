//
// Created by niels on 11.06.21.
//

#ifndef INC_2DSIDESCROLLER_DECOMAPPARSER_H
#define INC_2DSIDESCROLLER_DECOMAPPARSER_H


#include "../MapParser.h"

class DecoMapParser : public MapParser {
public:
    EntityManager * mapToEntities(const std::string LEVEL) override;
private:
    static std::string getMapFilePath(const std::string LEVEL);
};


#endif //INC_2DSIDESCROLLER_DECOMAPPARSER_H
