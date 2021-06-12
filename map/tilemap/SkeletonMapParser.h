//
// Created by niels on 11.06.21.
//

#ifndef INC_2DSIDESCROLLER_SKELETONMAPPARSER_H
#define INC_2DSIDESCROLLER_SKELETONMAPPARSER_H


#include "../MapParser.h"

class SkeletonMapParser : public MapParser {
public:
    EntityManager * mapToEntities() override;
private:
    static std::string getMapFilePath();

};


#endif //INC_2DSIDESCROLLER_SKELETONMAPPARSER_H
