//
// Created by niels on 08.12.21.
//

#ifndef INC_2DSIDESCROLLER_SCOREBOARD_H
#define INC_2DSIDESCROLLER_SCOREBOARD_H


#include "LTexture.h"
#include "Renderer.h"
class Scoreboard {
public:
    Scoreboard();
    void draw();

private:
    LTexture * successText;
    LTexture * totalCoins;
    LTexture * totalDeaths;
};


#endif //INC_2DSIDESCROLLER_SCOREBOARD_H
