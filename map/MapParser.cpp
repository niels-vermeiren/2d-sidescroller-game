//
// Created by niels on 4/17/21.
//

#include "MapParser.h"
#include "../entity/Wall.h"
#include "MapReader.h"

MapParser::MapParser() {
    this->tileHolder = nullptr;
}

MapParser::MapParser(TilesetTextureHolder * holder) {
    this->tileHolder = holder;
}

MapParser::~MapParser() {
    delete tileHolder;
}
