//
// Created by niels on 11.06.21.
//

#include "SkeletonMapParser.h"
#include "../MapReader.h"
#include "../../entity/Skeleton.h"
#include "../../entity/Mage.h"

std::string SkeletonMapParser::getMapFilePath() {
    return std::string("../resources/skeletonmap/testlevel.txt");
}

EntityManager *SkeletonMapParser::mapToEntities() {
    MapReader mapReader;
    std::vector<std::vector<int>> map = mapReader.read(getMapFilePath());
    std::list<Entity *> entities;

    for(int i = 0; i != map.size(); i++) {
        const std::vector<int>& row = map.at(i);
        for (int j = 0; j != row.size(); j++) {
            int index = map[i][j];
            if (index == -1) continue;
            auto * enemyRect = new SDL_Rect {j * 64, i * 64 -150, 155, 149};
            Vector v(0,0);
            Entity * enemy = new Skeleton(v,enemyRect);
            entities.push_back(enemy);
        }
    }
    return new EntityManager(entities);
}
