//
// Created by niels on 5/25/21.
//

#ifndef INC_2DSIDESCROLLER_SPIKEMAPPARSER_H
#define INC_2DSIDESCROLLER_SPIKEMAPPARSER_H


#include "../MapParser.h"
#include "../MapReader.h"
#include "../../entity/Spike.h"
#include "../../entity/Saw.h"

class SpikeMapParser : public MapParser {
public:
    EntityManager * mapToEntities(const std::string LEVEL) override;
private:
    static std::string getMapFilePath(const std::string LEVEL);
};


#endif //INC_2DSIDESCROLLER_SPIKEMAPPARSER_H
