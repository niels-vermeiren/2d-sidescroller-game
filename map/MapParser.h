//
// Created by niels on 4/17/21.
//

#ifndef INC_2DSIDESCROLLER_MAPPARSER_H
#define INC_2DSIDESCROLLER_MAPPARSER_H
#include "../entity/EntityManager.h"
#include "tilemap/TilesetTextureHolder.h"
#include <fstream>
#include <sstream>

class MapParser {
public:
    MapParser();
    explicit MapParser(TilesetTextureHolder * holder);
    virtual ~MapParser();
    virtual EntityManager * mapToEntities(const std::string LEVEL) = 0;

protected:
    TilesetTextureHolder * tileHolder;
};


#endif //INC_2DSIDESCROLLER_MAPPARSER_H
