//
// Created by niels on 4/17/21.
//

#ifndef INC_2DSIDESCROLLER_TILEMAPPARSER_H
#define INC_2DSIDESCROLLER_TILEMAPPARSER_H

#include "TilesetTextureHolder.h"
#include "../MapParser.h"

class TileMapParser : public MapParser {
public:
    explicit TileMapParser(TilesetTextureHolder * holder);
    EntityManager * mapToEntities(const std::string LEVEL) override;
private:
    static std::string getMapFilePath(const std::string LEVEL);
    Entity * createPlatform(int row, int col, int index);
};


#endif //INC_2DSIDESCROLLER_TILEMAPPARSER_H
