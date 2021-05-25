//
// Created by niels on 5/25/21.
//

#include "SawMapParser.h"
#include "../../entity/Spike.h"
#include "../MapReader.h"
#include "../../entity/Saw.h"

std::string SawMapParser::getMapFilePath() {
    return std::string("/home/niels/Projects/2dSideScroller/resources/sawmap/level1.txt");
}

EntityManager *SawMapParser::mapToEntities() {
    MapReader mapReader;
    std::vector<std::vector<int>> map = mapReader.read(getMapFilePath());
    std::list<Entity *> entities;

    for(int i = 0; i != map.size(); i++) {
        const std::vector<int>& row = map.at(i);
        for (int j = 0; j != row.size(); ++j) {
            int index = map[i][j];
            if (index == -1) continue;
            int sawX, sawY;
            if(index == 0) {
                sawX = (64 * j) + 32 - 76;
                sawY = (64 * i) + 32 - 76;
            }
            if(index == 1) {
                sawX = (64 * j) + 32 - 76;
                sawY = (64 * i) + 13 - 76;
            }
            auto * sawRect = new SDL_Rect {sawX, sawY, 152, 152};
            auto * saw = new Saw(sawRect);
            entities.push_back(saw);
        }
    }
    return new EntityManager(entities);
}
