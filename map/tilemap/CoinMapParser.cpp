//
// Created by niels on 5/27/21.
//

#include "CoinMapParser.h"
#include "../MapReader.h"
#include "../../entity/Coin.h"

std::string CoinMapParser::getMapFilePath() {
    return std::string("../resources/coinmap/level1.txt");
}

EntityManager *CoinMapParser::mapToEntities() {
    MapReader mapReader;
    std::vector<std::vector<int>> map = mapReader.read(getMapFilePath());
    std::list<Entity *> entities;

    for(int i = 0; i != map.size(); i++) {
        const std::vector<int>& row = map.at(i);
        for (int j = 0; j != row.size(); ++j) {
            int index = map[i][j];
            if (index == -1) continue;
            if(index == 0) {
                entities.push_back(new Coin(getRectCenterCoin(j, i)));
            }
            if(index == 1) {
                entities.push_back(new Coin(getRectBottomLeftCoin(j, i)));
                entities.push_back(new Coin(getRectBottomRightCoin(j, i)));
            }
            if(index == 2) {
                entities.push_back(new Coin(getRectUpperLeftCoin(j, i)));
                entities.push_back(new Coin(getRectUpperRightCoin(j, i)));
                entities.push_back(new Coin(getRectBottomLeftCoin(j, i)));
                entities.push_back(new Coin(getRectBottomRightCoin(j, i)));
            }
            if(index == 3) {
                entities.push_back(new Coin(getRectUpperLeftCoin(j, i)));
                entities.push_back(new Coin(getRectUpperRightCoin(j, i)));
            }
            if(index == 4) {
                entities.push_back(new Coin(getRectUpperRightCoin(j, i)));
                entities.push_back(new Coin(getRectBottomLeftCoin(j, i)));
            }
            if(index == 5) {
                entities.push_back(new Coin(getRectBottomRightCoin(j, i)));
                entities.push_back(new Coin(getRectUpperLeftCoin(j, i)));
            }
        }
    }
    return new EntityManager(entities);
}

SDL_Rect *CoinMapParser::getRectCenterCoin(int row, int col) {
    int coinX = (64 * row) + 32 - 12.5;
    int coinY = (64 * col) + 32 - 12.5;
    return new SDL_Rect {coinX, coinY, 25, 25};
}

SDL_Rect *CoinMapParser::getRectUpperLeftCoin(int row, int col) {
    int coinX = (64 * row) + 64/4 - 12.5;
    int coinY = (64 * col) + 64/4 - 12.5;
    return new SDL_Rect {coinX, coinY, 25, 25};
}

SDL_Rect *CoinMapParser::getRectUpperRightCoin(int row, int col) {
    int coinX = (64 * row) + 32 + 64/4 - 12.5;
    int coinY = (64 * col) + 64/4 - 12.5;
    return new SDL_Rect {coinX, coinY, 25, 25};
}

SDL_Rect *CoinMapParser::getRectBottomLeftCoin(int row, int col) {
    int coinX = (64 * row) + 64/4 - 12.5;
    int coinY = (64 * col) + 32 + 64/4 - 12.5;
    return new SDL_Rect {coinX, coinY, 25, 25};
}

SDL_Rect *CoinMapParser::getRectBottomRightCoin(int row, int col) {
    int coinX = (64 * row) + 32 + 64/4 - 12.5;
    int coinY = (64 * col) + 32 + 64/4 - 12.5;
    return new SDL_Rect {coinX, coinY, 25, 25};
}
