//
// Created by niels on 4/17/21.
//

#include "MapParser.h"
#include "../entity/Wall.h"
#include "MapReader.h"

MapParser::MapParser() {
    this->tileHolder = nullptr;
}

MapParser::~MapParser() {
    delete tileHolder;
}

MapParser::MapParser(TilesetTextureHolder *holder) {
    this->tileHolder = holder;
}
