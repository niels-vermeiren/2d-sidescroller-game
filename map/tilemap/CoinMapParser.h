//
// Created by niels on 5/27/21.
//

#ifndef INC_2DSIDESCROLLER_COINMAPPARSER_H
#define INC_2DSIDESCROLLER_COINMAPPARSER_H


#include "../MapParser.h"
#include "../../entity/EntityManager.h"

class CoinMapParser : public MapParser {
public:
    EntityManager * mapToEntities(std::string LEVEL) override;
private:
    static std::string getMapFilePath(const std::string LEVEL);
    SDL_Rect * getRectCenterCoin(int row, int col);
    SDL_Rect * getRectUpperLeftCoin(int row, int col);
    SDL_Rect * getRectUpperRightCoin(int row, int col);
    SDL_Rect * getRectBottomLeftCoin(int row, int col);
    SDL_Rect * getRectBottomRightCoin(int row, int col);
};


#endif //INC_2DSIDESCROLLER_COINMAPPARSER_H
