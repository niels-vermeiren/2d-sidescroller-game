//
// Created by niels on 5/25/21.
//

#include "SawMapParser.h"
#include "../MapReader.h"
#include "../../entity/Saw.h"

EntityManager *SawMapParser::mapToEntities(const std::string LEVEL) {
    MapReader mapReader;
    std::vector<std::vector<int>> map = mapReader.read(getMapFilePath(LEVEL));
    std::list<Entity *> entities;

    for(int i = 0; i != map.size(); i++) {
        const std::vector<int>& row = map.at(i);
        for (int j = 0; j != row.size(); ++j) {
            int index = map[i][j];
            if (index == -1) continue;
            int sawX, sawY;
            if(index == 0 || index == 2) {
                sawX = (64 * j) + 32 - 76;
                sawY = (64 * i) + 32 - 76;
            }
            if(index == 1 || index == 3) {
                sawX = (64 * j) + 32 - 76;
                sawY = (64 * i) + 13 - 76;
            }
            auto * sawRect = new SDL_Rect {sawX, sawY, 152, 152};
            auto * saw = new Saw(sawRect, index == 2 || index == 3);
            entities.push_back(saw);
        }
    }
    return new EntityManager(entities);
}

std::string SawMapParser::getMapFilePath(const std::string LEVEL) {
    return std::string("../resources/sawmap/"+LEVEL);
}
