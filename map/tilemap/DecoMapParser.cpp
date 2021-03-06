//
// Created by niels on 11.06.21.
//

#include "DecoMapParser.h"
#include "../MapReader.h"
#include "../../entity/Deco.h"


EntityManager *DecoMapParser::mapToEntities(const std::string LEVEL) {
    MapReader mapReader;
    std::vector<std::vector<int>> map = mapReader.read(getMapFilePath(LEVEL));
    std::list<Entity *> entities;

    for(int i = 0; i != map.size(); i++) {
        const std::vector<int>& row = map.at(i);
        for (int j = 0; j != row.size(); j++) {
            int index = map[i][j];
            if (index == -1) continue;
            auto * decoRect = new SDL_Rect {j * 64 , i * 64, 0, 0};

            if(index == 10 || index == 13) decoRect->x -= 18;
            decoRect->y += 1;
            Entity * enemy = new Deco(decoRect, index);
            entities.push_back(enemy);
        }
    }
    return new EntityManager(entities);
}

std::string DecoMapParser::getMapFilePath(const std::string LEVEL) {
    return std::string("../resources/decomap/"+LEVEL);
}
