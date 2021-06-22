//
// Created by niels on 5/25/21.
//

#include "SpikeMapParser.h"

EntityManager * SpikeMapParser::mapToEntities(const std::string LEVEL) {
    MapReader mapReader;
    std::vector<std::vector<int>> map = mapReader.read(getMapFilePath(LEVEL));
    std::list<Entity *> entities;

    for(int i = 0; i != map.size(); i++) {
        const std::vector<int>& row = map.at(i);
        for (int j = 0; j != row.size(); ++j) {
            int index = map[i][j];
            if (index == -1) continue;

            auto * spikeRect = new SDL_Rect {j * 64, i * 64 + 18, 64, 46};
            auto * spike = new Spike(spikeRect);
            entities.push_back(spike);
        }
    }
    return new EntityManager(entities);
}

std::string SpikeMapParser::getMapFilePath(const std::string LEVEL) {
    return std::string("../resources/spikemap/"+LEVEL);
}
