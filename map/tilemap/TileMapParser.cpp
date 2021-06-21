//
// Created by niels on 4/17/21.
//

#include "TileMapParser.h"
#include "../../entity/Wall.h"
#include "../MapReader.h"

TileMapParser::TileMapParser(TilesetTextureHolder * holder) : MapParser(holder) {}

std::string TileMapParser::getMapFilePath() {
    return std::string("../resources/tilemap/level2.txt");
}

Entity * TileMapParser::createPlatform(int row, int col, int index) {
    auto * entityRect = new SDL_Rect {col * 64, row * 64, 64, 64};
    int clipX = index % 5;
    int clipY = std::floor(index/5);
    auto * clipRect = new SDL_Rect{clipX * 64, clipY * 64, 64, 64};
    return new Platform({0,0}, entityRect, clipRect);
}


EntityManager * TileMapParser::mapToEntities() {
    MapReader mapReader;
    std::vector<std::vector<int>> map = mapReader.read(getMapFilePath());
    std::list<Entity *> entities;

    for(int i = 0; i != map.size(); i++) {
        const std::vector<int>& row = map.at(i);
        int j = 0;
        while(j < row.size()) {
            std::vector<Entity *> platforms;
            int index = map[i][j];
            j++;
            int col = j - 1;
            if (index == -1) continue;
            platforms.push_back(createPlatform(i, col, index));
            int wallWidth = 1;
            while(j  < row.size() && map[i][j] != -1) {
                index = map[i][j];
                platforms.push_back(createPlatform(i, j, index));
                wallWidth++;
                if(index != -1){
                    j++;
                }
            }
            Wall * wall  = new Wall(col * 64, i * 64, 64 * wallWidth, 64);
            wall->setPlatforms(platforms);
            entities.push_back(wall);
        }
    }
    return new EntityManager(entities);
}
