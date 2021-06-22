//
// Created by niels on 11.06.21.
//

#include "MageMapParser.h"
#include "../MapReader.h"
#include "../../entity/Mage.h"


EntityManager *MageMapParser::mapToEntities(const std::string LEVEL) {
    MapReader mapReader;
    std::vector<std::vector<int>> map = mapReader.read(getMapFilePath(LEVEL));
    std::list<Entity *> entities;

    for(int i = 0; i != map.size(); i++) {
        const std::vector<int>& row = map.at(i);
        for (int j = 0; j != row.size(); j++) {
            int index = map[i][j];
            if (index == -1) continue;
            auto * enemyRect = new SDL_Rect {j * 64, i * 64 -150, 150, 150};
            Entity * enemy = new Mage({0,0},enemyRect);
            entities.push_back(enemy);
        }
    }
    return new EntityManager(entities);
}

std::string MageMapParser::getMapFilePath(const std::string LEVEL) {
    return std::string("../resources/magemap/"+LEVEL);
}
